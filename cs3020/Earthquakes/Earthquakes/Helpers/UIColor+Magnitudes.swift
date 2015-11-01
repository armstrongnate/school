//
//  UIColor+Magnitudes.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import Foundation
import EarthShakeKit

extension UIColor {

    class func lowestMagnitudeColor() -> UIColor {
        return UIColor(white: 233/255.0, alpha: 1.0)
    }

    class func weakMagnitudeColor() -> UIColor {
        return UIColor(white: 155/255.0, alpha: 1.0)
    }

    class func moderateMagnitudeColor() -> UIColor {
        return UIColor(white: 74/255.0, alpha: 1.0)
    }

    class func strongMagnitudeColor() -> UIColor {
        return UIColor(red: 245/255.0, green: 166/255.0, blue: 35/255.0, alpha: 1.0)
    }

    class func violentMagnitudeColor() -> UIColor {
        return UIColor(red: 208/255.0, green: 2/255.0, blue: 27/255.0, alpha: 1.0)
    }

    class func colorForMagnitude(magnitude: EarthquakeMagnitude) -> UIColor {
        switch magnitude {
        case .None: return lowestMagnitudeColor()
        case .Weak: return weakMagnitudeColor()
        case .Moderate: return moderateMagnitudeColor()
        case .Strong: return strongMagnitudeColor()
        case .Violent: return violentMagnitudeColor()
        }
    }

}
