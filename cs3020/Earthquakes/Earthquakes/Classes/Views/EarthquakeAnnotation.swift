//
//  EarthquakeAnnotation.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import MapKit
import EarthShakeKit

class EarthquakeAnnotation: NSObject, MKAnnotation {

    // MARK: Constants

    static let reuseIdentifier = "earthquakeAnnotation"

    // MARK: Properties

    let earthquake: ESEarthquake
    let coordinate: CLLocationCoordinate2D
    let title: String?
    let subtitle: String?

    // MARK: Initialization

    init(earthquake: ESEarthquake) {
        self.earthquake = earthquake
        let coordinate = CLLocationCoordinate2DMake(earthquake.latitude.doubleValue, earthquake.longitude.doubleValue)
        self.coordinate = coordinate;
        self.title = earthquake.place;

        let dateFormatter = NSDateFormatter()
        dateFormatter.dateStyle = .MediumStyle
        dateFormatter.timeStyle = .ShortStyle
        self.subtitle = dateFormatter.stringFromDate(earthquake.timestamp)

        super.init()
    }

}
