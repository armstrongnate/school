//
//  Styles.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import Foundation

extension UIColor {

    // MARK: Earthquake cells

    class func earthquakeCellBorderColor() -> UIColor {
        return UIColor(red: 74/255.0, green: 144/255.0, blue: 226/255.0, alpha: 1.0)
    }

    class func earthquakeCellMagnitudeTextColor() -> UIColor {
        return UIColor(white: 1.0, alpha: 0.5)
    }

    class func earthquakeCellPlaceTextColor() -> UIColor {
        return UIColor.whiteColor()
    }

}

extension UIFont {

    // MARK: Earthquake cells

    class func earthquakeCellMagnitudeFont() -> UIFont {
        return UIFont.boldSystemFontOfSize(60)
    }

    class func earthquakeCellPlaceFont() -> UIFont {
        return UIFont.boldSystemFontOfSize(11)
    }

}
