//
//  ViewController.swift
//  DrawPad
//
//  Created by Nate Armstrong on 11/10/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var lastPoint: CGPoint!
    var red: CGFloat = 0
    var green: CGFloat = 0
    var blue: CGFloat = 0
    var opacity: CGFloat = 1
    var brush: CGFloat = 10
    var mouseSwiped: Bool!

    @IBOutlet weak var mainImageView: UIImageView!
    @IBOutlet weak var tempDrawImageView: UIImageView!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        super.touchesBegan(touches, withEvent: event)

        if let touch = touches.first {
            mouseSwiped = false
            lastPoint = touch.locationInView(view)
        }
    }

    override func touchesMoved(touches: Set<UITouch>, withEvent event: UIEvent?) {
        if let touch = touches.first {
            mouseSwiped = true

            let currentPoint = touch.locationInView(view)

            UIGraphicsBeginImageContext(view.frame.size)
            tempDrawImageView.image?.drawInRect(view.frame)
            CGContextMoveToPoint(UIGraphicsGetCurrentContext(), lastPoint.x, lastPoint.y)
            CGContextAddLineToPoint(UIGraphicsGetCurrentContext(), currentPoint.x, currentPoint.y)
            CGContextSetLineCap(UIGraphicsGetCurrentContext(), CGLineCap.Round)
            CGContextSetLineWidth(UIGraphicsGetCurrentContext(), brush)
            CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), red, green, blue, 1)
            CGContextSetBlendMode(UIGraphicsGetCurrentContext(), CGBlendMode.Normal)
            CGContextStrokePath(UIGraphicsGetCurrentContext())
            tempDrawImageView.image = UIGraphicsGetImageFromCurrentImageContext()
            tempDrawImageView.alpha = opacity
            UIGraphicsEndImageContext()
            lastPoint = currentPoint
        }
    }

    override func touchesEnded(touches: Set<UITouch>, withEvent event: UIEvent?) {
        if !mouseSwiped {
            UIGraphicsBeginImageContext(view.frame.size)
            tempDrawImageView.image?.drawInRect(view.frame)
            CGContextMoveToPoint(UIGraphicsGetCurrentContext(), lastPoint.x, lastPoint.y)
            CGContextAddLineToPoint(UIGraphicsGetCurrentContext(), lastPoint.x, lastPoint.y)
            CGContextSetLineCap(UIGraphicsGetCurrentContext(), CGLineCap.Round)
            CGContextSetLineWidth(UIGraphicsGetCurrentContext(), brush)
            CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), red, green, blue, opacity)
            CGContextSetBlendMode(UIGraphicsGetCurrentContext(), CGBlendMode.Normal)
            CGContextStrokePath(UIGraphicsGetCurrentContext())
            tempDrawImageView.image = UIGraphicsGetImageFromCurrentImageContext()
            tempDrawImageView.alpha = opacity
            UIGraphicsEndImageContext()
        }

        UIGraphicsBeginImageContext(view.frame.size)
        mainImageView.image?.drawInRect(view.frame, blendMode: .Normal, alpha: 1)
        tempDrawImageView.image?.drawInRect(view.frame, blendMode: .Normal, alpha: opacity)
        mainImageView.image = UIGraphicsGetImageFromCurrentImageContext()
        tempDrawImageView.image?.drawInRect(view.frame, blendMode: .Normal, alpha: 0)
        UIGraphicsEndImageContext()
    }

    @IBAction func pencilPressed(sender: UIButton) {
        switch(sender.tag)
        {
        case 0:
            red = 0.0/255.0;
            green = 0.0/255.0;
            blue = 0.0/255.0;
        case 1:
            red = 105.0/255.0;
            green = 105.0/255.0;
            blue = 105.0/255.0;
        case 2:
            red = 255.0/255.0;
            green = 0.0/255.0;
            blue = 0.0/255.0;
        case 3:
            red = 0.0/255.0;
            green = 0.0/255.0;
            blue = 255.0/255.0;
        case 4:
            red = 102.0/255.0;
            green = 204.0/255.0;
            blue = 0.0/255.0;
        case 5:
            red = 102.0/255.0;
            green = 255.0/255.0;
            blue = 0.0/255.0;
        case 6:
            red = 51.0/255.0;
            green = 204.0/255.0;
            blue = 255.0/255.0;
        case 7:
            red = 160.0/255.0;
            green = 82.0/255.0;
            blue = 45.0/255.0;
        case 8:
            red = 255.0/255.0;
            green = 102.0/255.0;
            blue = 0.0/255.0;
        case 9:
            red = 255.0/255.0;
            green = 255.0/255.0;
            blue = 0.0/255.0;
        default:
            red = 0
            green = 0
            blue = 0
        }
    }

    @IBAction func eraserPressed(sender: UIButton) {
        red = 1
        green = 1
        blue = 1
        opacity = 1
    }

}

