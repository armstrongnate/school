//
//  EarthquakeViewController.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import EarthShakeKit
import MapKit

class EarthquakeViewController: UITableViewController {

    // MARK: Constants

    let historyRadius = 1

    // MARK: Properties

    var tableData: [String:String]!
    var earthquake: ESEarthquake! {
        didSet {
            tableView.backgroundColor = .whiteColor()
            tableData = [
                "Magnitude": String(format: "%.2f", earthquake.magnitude.floatValue),
                "Location": earthquake.place,
                "Lat/Long": "\(earthquake.latitude)/\(earthquake.longitude)",
                "Date": dateFormatter.stringFromDate(earthquake.timestamp)
            ]
            getHistory()
        }
    }

    var queue: NSOperationQueue = NSOperationQueue()

    lazy var fetchedResultsController: NSFetchedResultsController = {
        let request = NSFetchRequest(entityName: ESEarthquake.entityName())
        request.sortDescriptors = [NSSortDescriptor(key: "timestamp", ascending: false)]
        request.fetchLimit = 100
        let controller = NSFetchedResultsController(fetchRequest: request, managedObjectContext: self.historyContext, sectionNameKeyPath: nil, cacheName: nil)
        return controller
    }()

    /// in-memory context for the history
    lazy var historyContext: NSManagedObjectContext = {
        let modelURL = NSBundle(forClass: ESPersistenceController.self).URLForResource("DataModel", withExtension: "momd")!
        let mom = NSManagedObjectModel(contentsOfURL: modelURL)!
        let coordinator = NSPersistentStoreCoordinator(managedObjectModel: mom)
        do {
            try coordinator.addPersistentStoreWithType(NSInMemoryStoreType, configuration: nil, URL: nil, options: nil)
        } catch {
            fatalError("error creating history context")
        }
        let context = NSManagedObjectContext(concurrencyType: .MainQueueConcurrencyType)
        context.persistentStoreCoordinator = coordinator
        return context
    }()

    lazy var dateFormatter: NSDateFormatter = {
        let formatter = NSDateFormatter()
        formatter.dateStyle = .MediumStyle
        formatter.timeStyle = .MediumStyle
        return formatter
    }()

    // MARK: Initialization

    init() {
        super.init(style: .Grouped)
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    // MARK: View Life Cycle

    override func viewDidLoad() {
        super.viewDidLoad()

        tableView.registerClass(InfoCell.self, forCellReuseIdentifier: "infoCell")
    }

    // MARK: Instance Methods

    func getHistory() {
        let lat = earthquake.latitude
        let long = earthquake.longitude
        let url = NSURL(string:
            "http://ehp2-earthquake.wr.usgs.gov/fdsnws/event/1/query?" +
            "latitude=\(lat)" +
            "&longitude=\(long)" +
            "&maxradius=\(historyRadius)" +
            "&format=geojson"
        )
        let getEarthquakesOperation = ESGetEarthquakesOperation(context: historyContext, url: url) { [weak self] in
            dispatch_async(dispatch_get_main_queue()) {
                do {
                    try self?.fetchedResultsController.performFetch()
                    self?.tableView.reloadData()
                }
                catch {
                    print("fetch error \(error)")
                }
            }
        }
        queue.addOperation(getEarthquakesOperation)
    }

}

// MARK: UITableViewDataSource
extension EarthquakeViewController {

    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 2
    }

    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if section == 0 {
            return tableData?.keys.count ?? 0
        }
        return fetchedResultsController.fetchedObjects?.count ?? 0
    }

    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("infoCell") as! InfoCell
        if indexPath.section == 0 {
            let key = Array(tableData.keys)[indexPath.row]
            cell.textLabel!.text = key
            cell.detailTextLabel!.text = tableData[key]
            return cell
        }
        let old = fetchedResultsController.sections![0].objects![indexPath.row] as! ESEarthquake
        cell.textLabel!.text = dateFormatter.stringFromDate(old.timestamp)
        cell.detailTextLabel!.text = String(format: "%.2f", old.magnitude.floatValue)
        return cell
    }

    override func tableView(tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        if section != 0 {
            return nil
        }
        let mapView = MKMapView()
        let center = CLLocationCoordinate2DMake(earthquake.latitude.doubleValue, earthquake.longitude.doubleValue)
        let span = MKCoordinateSpanMake(3, 3)
        let region = MKCoordinateRegionMake(center, span)
        mapView.setRegion(region, animated: false)

        let annotation = EarthquakeAnnotation(earthquake: earthquake)
        mapView.addAnnotation(annotation)
        return mapView
    }

}

// MARK: UITableViewDelegate
extension EarthquakeViewController {

    override func tableView(tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return section == 0 ? 180 : 34
    }

    override func tableView(tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return section == 1 ? "History" : nil
    }

}

// MARK: Utils

class InfoCell: UITableViewCell {

    init() {
        super.init(style: .Value1, reuseIdentifier: "infoCell")
    }

    override init(style: UITableViewCellStyle, reuseIdentifier: String?) {
        super.init(style: .Value1, reuseIdentifier: "infoCell")
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

}