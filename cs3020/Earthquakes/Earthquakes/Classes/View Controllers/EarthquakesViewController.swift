//
//  EarthquakesViewController.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import MapKit
import CoreData
import EarthShakeKit

class EarthquakesViewController: UIViewController {

    // MARK: Properties

    var mapView: MKMapView!
    var collectionView: UICollectionView!
    var fetchedResultsController: NSFetchedResultsController!
    let queue = NSOperationQueue()
    var managedObjectContext: NSManagedObjectContext! {
        didSet {
            guard let context = managedObjectContext else {
                return
            }
            let request = NSFetchRequest(entityName: ESEarthquake.entityName())
            let sort = NSSortDescriptor(key: "timestamp", ascending: false)
            request.sortDescriptors = [sort]
            request.fetchLimit = 100
            fetchedResultsController = NSFetchedResultsController(
                fetchRequest: request,
                managedObjectContext: context,
                sectionNameKeyPath: nil, cacheName: nil)
            getEarthquakes()
        }
    }
    lazy var refreshControl: UIRefreshControl = {
        let refresh = UIRefreshControl()
        refresh.tintColor = UIColor.grayColor()
        refresh.addTarget(self, action: "getEarthquakes", forControlEvents: .ValueChanged)
        return refresh
    }()

    // MARK: View Life Cycle

    override func viewDidLoad() {
        super.viewDidLoad()

        setup()
        refreshControl.beginRefreshing()
    }

    // MARK: Instance Methods

    func setup() {
        layoutMap()
        layoutList()
    }

    func layoutMap() {
        mapView = MKMapView()
        mapView.translatesAutoresizingMaskIntoConstraints = false
        mapView.delegate = self
        view.addSubview(mapView)

        mapView.wta_addTopConstraintToSuperviewOffset(0)
        mapView.wta_addLeadingConstraintToSuperviewOffset(0)
        mapView.wta_addTrailingConstraintToSuperviewOffset(0)
        mapView.wta_addBottomConstraintToSuperviewCenterOffset(0)
    }

    func layoutList() {
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.minimumInteritemSpacing = 5
        flowLayout.minimumLineSpacing = 5
        flowLayout.sectionInset = UIEdgeInsetsMake(5, 5, 5, 5)

        let frame = CGRectMake(0, CGRectGetMidY(view.frame), CGRectGetWidth(view.frame), CGRectGetHeight(view.frame) / 2);
        collectionView = UICollectionView(frame: frame, collectionViewLayout: flowLayout)
        collectionView.backgroundColor = .whiteColor()
        collectionView.translatesAutoresizingMaskIntoConstraints = false
        collectionView.dataSource = self
        collectionView.delegate = self
        collectionView.registerClass(EarthquakeCell.self, forCellWithReuseIdentifier: EarthquakeCell.reuseIdentifier)
        collectionView.addSubview(refreshControl)
        view.addSubview(collectionView)

        collectionView.wta_addConstraintPlacingViewBelowView(mapView, separation: 0)
        collectionView.wta_addLeadingConstraintToSuperviewOffset(0)
        collectionView.wta_addTrailingConstraintToSuperviewOffset(0)
        collectionView.wta_addBottomConstraintToSuperviewOffset(0)
    }

    func getEarthquakes() {
        let url = NSURL(string: "http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/2.5_month.geojson")
        let getEarthquakes = ESGetEarthquakesOperation(context: managedObjectContext, url: url) { [weak self] in
            dispatch_async(dispatch_get_main_queue()) {
                self?.refreshControl.endRefreshing()
                self?.updateUI()
            }
        }
        queue.addOperation(getEarthquakes)
    }

    func updateUI() {
        do {
            try fetchedResultsController.performFetch()
            collectionView.reloadData()
            updateMap()
        }
        catch {
            print("fetch error: \(error)")
        }
    }

    func updateMap() {
        mapView.removeAnnotations(mapView.annotations)
        var zoomRect = MKMapRectNull
        (fetchedResultsController.fetchedObjects as! [ESEarthquake]).forEach { earthquake in
            let annotation = EarthquakeAnnotation(earthquake: earthquake)
            mapView.addAnnotation(annotation)

            // keep track of zoom rect
            let annotationPoint = MKMapPointForCoordinate(annotation.coordinate)
            let pointRect = MKMapRectMake(annotationPoint.x, annotationPoint.y, 0.1, 0.1)
            zoomRect = MKMapRectUnion(zoomRect, pointRect)
        }
        mapView.setVisibleMapRect(zoomRect, animated: true)
    }

    func selectAnnotation(earthquake: ESEarthquake) {
        mapView.annotations.forEach { annotation in
            if (annotation as? EarthquakeAnnotation)?.earthquake == earthquake {
                mapView.selectAnnotation(annotation, animated: true)
            }
        }
    }

    func dismissVC() {
        dismissViewControllerAnimated(true, completion: nil)
    }

    func showEarthquake(earthquake: ESEarthquake) {
        let detail = EarthquakeViewController()
        detail.earthquake = earthquake
        detail.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .Done, target: self, action: "dismissVC")
        let nav = UINavigationController(rootViewController: detail)
        nav.modalPresentationStyle = .FormSheet
        presentViewController(nav, animated: true, completion: nil)
        return
    }

}

// MARK: UICollectionViewDataSource
extension EarthquakesViewController: UICollectionViewDataSource {


    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return fetchedResultsController?.fetchedObjects?.count ?? 0
    }

    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let earthquake = fetchedResultsController.fetchedObjects![indexPath.row] as! ESEarthquake
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier(EarthquakeCell.reuseIdentifier, forIndexPath: indexPath) as! EarthquakeCell
        cell.earthquake = earthquake
        return cell
    }

}

// MARK: UICollectionViewDelegate
extension EarthquakesViewController: UICollectionViewDelegate {

    func collectionView(collectionView: UICollectionView, didSelectItemAtIndexPath indexPath: NSIndexPath) {
        let earthquake = fetchedResultsController.objectAtIndexPath(indexPath) as! ESEarthquake
        let center = CLLocationCoordinate2DMake(earthquake.latitude.doubleValue, earthquake.longitude.doubleValue)
        let span = MKCoordinateSpanMake(3, 3)
        let region = MKCoordinateRegionMake(center, span);
        mapView.setRegion(region, animated:false)
        selectAnnotation(earthquake)
    }
}

// MARK: UICollectionViewDelegateFlowLayout
extension EarthquakesViewController: UICollectionViewDelegateFlowLayout {

    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize {
        let height: CGFloat = 60
        var width = CGRectGetWidth(collectionView.frame) / 3
        width -= 10
        return CGSizeMake(width, height)
    }

}

// MARK: MKMapViewDelegate
extension EarthquakesViewController: MKMapViewDelegate {

    func mapView(mapView: MKMapView, viewForAnnotation annotation: MKAnnotation) -> MKAnnotationView? {
        var annotationView: MKAnnotationView? = nil
        if let annotation = annotation as? EarthquakeAnnotation {
            annotationView = mapView.dequeueReusableAnnotationViewWithIdentifier(EarthquakeAnnotation.reuseIdentifier)
            if annotationView == nil {
                annotationView = MKAnnotationView(annotation: annotation, reuseIdentifier: EarthquakeAnnotation.reuseIdentifier)
            }
            annotationView!.canShowCallout = true
            annotationView!.image = UIImage.annotationImageForMagnitude(annotation.earthquake.magnitudeCategory())
            annotationView!.leftCalloutAccessoryView = UIButton(type: .InfoLight)
        }

        return annotationView
    }

    func mapView(mapView: MKMapView, didSelectAnnotationView view: MKAnnotationView) {
        if let annotation = view.annotation as? EarthquakeAnnotation,
           let indexPath = fetchedResultsController.indexPathForObject(annotation.earthquake) {
            collectionView.selectItemAtIndexPath(indexPath, animated: true, scrollPosition: .Top)
        }
    }

    func mapView(mapView: MKMapView, annotationView view: MKAnnotationView, calloutAccessoryControlTapped control: UIControl) {
        guard let earthquake = (view.annotation as? EarthquakeAnnotation)?.earthquake else {
            return
        }

        showEarthquake(earthquake)
    }

}
