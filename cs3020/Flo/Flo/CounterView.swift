//
//  CounterView.swift
//  Flo
//
//  Created by Nate Armstrong on 11/5/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

let NumRecommendedGlasses: CGFloat = 8
let π: CGFloat = CGFloat(M_PI)

@IBDesignable
class CounterView: UIView {

    @IBInspectable var counter: CGFloat = 5 {
        didSet {
            if counter <= NumRecommendedGlasses {
                setNeedsDisplay()
            }
        }
    }
    @IBInspectable var outlineColor: UIColor = .blueColor()
    @IBInspectable var counterColor: UIColor = .orangeColor()


    override func drawRect(rect: CGRect) {
        let center = CGPoint(x: CGRectGetMidX(rect), y: CGRectGetMidY(rect))
        let radius: CGFloat = max(rect.width, rect.height)
        let arcWidth: CGFloat = 76

        let startAngle = 3 * π / 4
        let endAngle = π / 4

        let path = UIBezierPath(arcCenter: center, radius: radius/2 - arcWidth/2, startAngle: startAngle, endAngle: endAngle, clockwise: true)
        path.lineWidth = arcWidth
        counterColor.setStroke()
        path.stroke()

        let angleDifference = 2 * π - startAngle + endAngle
        let arcLengthPerGlass = angleDifference / NumRecommendedGlasses
        let outlineEndAngle = arcLengthPerGlass * counter + startAngle

        let outlinePath = UIBezierPath(arcCenter: center, radius: rect.width/2 - 2.5, startAngle: startAngle, endAngle: outlineEndAngle, clockwise: true)
        outlinePath.addArcWithCenter(center, radius: rect.width/2 - arcWidth + 2.5, startAngle: outlineEndAngle, endAngle: startAngle, clockwise: false)

        outlinePath.closePath()
        outlineColor.setStroke()
        outlinePath.lineWidth = 5
        outlinePath.stroke()
    }

}
