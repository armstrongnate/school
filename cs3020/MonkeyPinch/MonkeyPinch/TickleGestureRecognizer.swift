//
//  TickleGestureRecognizer.swift
//  MonkeyPinch
//
//  Created by Nate Armstrong on 12/8/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class TickleGestureRecognizer:UIGestureRecognizer {

    // 1
    let requiredTickles = 2
    let distanceForTickleGesture: CGFloat = 25.0

    // 2
    enum Direction: Int {
        case DirectionUnknown = 0
        case DirectionLeft
        case DirectionRight
    }

    // 3
    var tickleCount: Int = 0
    var curTickleStart: CGPoint = CGPointZero
    var lastDirection:Direction = .DirectionUnknown

    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent) {
        if let touch = touches.first {
            self.curTickleStart = touch.locationInView(self.view)
        }
    }

    override func touchesMoved(touches: Set<UITouch>, withEvent event: UIEvent) {
        if let touch = touches.first {
            let ticklePoint = touch.locationInView(self.view)

            let moveAmt = ticklePoint.x - curTickleStart.x
            var curDirection:Direction
            if moveAmt < 0 {
                curDirection = .DirectionLeft
            } else {
                curDirection = .DirectionRight
            }

            //moveAmt is a Float, so self.distanceForTickleGesture needs to be a Float also
            if abs(moveAmt) < self.distanceForTickleGesture {
                return
            }

            if self.lastDirection == .DirectionUnknown ||
                (self.lastDirection == .DirectionLeft && curDirection == .DirectionRight) ||
                (self.lastDirection == .DirectionRight && curDirection == .DirectionLeft) {
                    self.tickleCount++
                    self.curTickleStart = ticklePoint
                    self.lastDirection = curDirection

                    if self.state == .Possible && self.tickleCount > self.requiredTickles {
                        self.state = .Ended
                    }
            }
        }
    }

    override func reset() {
        self.tickleCount = 0
        self.curTickleStart = CGPointZero
        self.lastDirection = .DirectionUnknown
        if self.state == .Possible {
            self.state = .Failed
        }
    }

    override func touchesEnded(touches: Set<UITouch>, withEvent event: UIEvent) {
        self.reset()
    }

    override func touchesCancelled(touches: Set<UITouch>, withEvent event: UIEvent) {
        self.reset()
    }

}
