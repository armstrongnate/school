//
//  PushButtonView.swift
//  Flo
//
//  Created by Nate Armstrong on 11/5/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

@IBDesignable
class PushButtonView: UIButton {

    @IBInspectable var fillColor: UIColor = .greenColor()
    @IBInspectable var isAddButton: Bool = true

    override func drawRect(rect: CGRect) {
        let path = UIBezierPath(ovalInRect: rect)
        fillColor.setFill()
        path.fill()

        let plusHeight: CGFloat = 3
        let plusWidth: CGFloat = min(bounds.width, bounds.height) * 0.6

        let plusPath = UIBezierPath()
        plusPath.lineWidth = plusHeight

        // -
        let y: CGFloat = rect.height/2 + plusHeight/2
        plusPath.moveToPoint(CGPoint(x: rect.width/2 - plusWidth/2, y: y))
        plusPath.addLineToPoint(CGPoint(x: rect.width/2 + plusWidth/2, y: y))

        if isAddButton {
            // |
            plusPath.moveToPoint(CGPoint(x: rect.width/2, y: rect.height/2 - plusWidth/2))
            plusPath.addLineToPoint(CGPoint(x: rect.width/2, y: rect.height/2 + plusWidth/2))
        }

        UIColor.whiteColor().setStroke()
        plusPath.stroke()
    }

}
