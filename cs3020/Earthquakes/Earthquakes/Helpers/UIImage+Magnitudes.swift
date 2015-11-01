//
//  UIImage+Magnitudes.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import Foundation
import EarthShakeKit

extension UIImage {

    class func annotationImageForMagnitude(magnitude: EarthquakeMagnitude) -> UIImage? {
        let magString: String
        switch magnitude {
        case .None: magString = "low"
        case .Weak: magString = "weak"
        case .Moderate: magString = "moderate"
        case .Strong: magString = "strong"
        case .Violent: magString = "violent"
        }

        return UIImage(named: "\(magString)-mag-annotation")
    }

}
