//
//  ViewController.swift
//  HonoluluArt
//
//  Created by Nate Armstrong on 11/3/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import MapKit

class ViewController: UIViewController {

    @IBOutlet weak var mapView: MKMapView!

    let initialLocation = CLLocation(latitude: 21.282778, longitude: -157.829444)
    var artworks = [Artwork]()

    override func viewDidLoad() {
        super.viewDidLoad()

        centerMapOnLocation(initialLocation)

        // show artwork on map
        let artwork = Artwork(title: "King David Kalakaua",
            locationName: "Waikiki Gateway Park",
            discipline: "Sculpture",
            coordinate: CLLocationCoordinate2D(latitude: 21.283921, longitude: -157.831661))
        
        mapView.addAnnotation(artwork)
        mapView.delegate = self

        loadInitialData()
        mapView.addAnnotations(artworks)
    }

    let regionRadius: CLLocationDistance = 1000
    func centerMapOnLocation(location: CLLocation) {
        let coordinateRegion = MKCoordinateRegionMakeWithDistance(location.coordinate,
            regionRadius * 2.0, regionRadius * 2.0)
        mapView.setRegion(coordinateRegion, animated: true)
    }

    func loadInitialData() {
        // 1
        let fileName = NSBundle.mainBundle().pathForResource("PublicArt", ofType: "json");

        // 2
        do {
            let data: NSData = try NSData(contentsOfFile: fileName!, options: NSDataReadingOptions(rawValue: 0))
            let jsonObject: AnyObject! = try NSJSONSerialization.JSONObjectWithData(data,
                options: NSJSONReadingOptions(rawValue: 0))
            // 3
            if let jsonData = JSONValue.fromObject(jsonObject)?["data"]?.array {
                for artworkJSON in jsonData {
                    if let artworkJSON = artworkJSON.array,
                        // 5
                        artwork = Artwork.fromJSON(artworkJSON) {
                            artworks.append(artwork)
                    }
                }
            }
        } catch {
            print("json error \(error)")
            return
        }

    }

}

