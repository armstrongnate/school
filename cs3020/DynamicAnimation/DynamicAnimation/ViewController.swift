//
//  ViewController.swift
//  DynamicAnimation
//
//  Created by Nate Armstrong on 10/13/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var greenSquare: UIView!
    var redSquare: UIView!
    var blueSquare: UIView!
    var animator: UIDynamicAnimator!

    override func viewDidLoad() {
        super.viewDidLoad()

        // setup

        var dimen = CGRect(x: 25, y: 25, width: 60, height: 60)
        greenSquare = UIView(frame: dimen)
        greenSquare.backgroundColor = .greenColor()
        view.addSubview(greenSquare)

        dimen.origin.x = 130
        dimen.size = CGSize(width: 100, height: 100)
        redSquare = UIView(frame: dimen)
        redSquare.backgroundColor = .redColor()
        view.addSubview(redSquare)

        dimen.origin.x = 150
        dimen.size = CGSize(width: 150, height: 150)
        blueSquare = UIView(frame: dimen)
        blueSquare.backgroundColor = .blueColor()
        blueSquare.layer.cornerRadius = blueSquare.frame.size.width / 2
        view.addSubview(blueSquare)

        // animate

        animator = UIDynamicAnimator(referenceView: view)

        let bounds = UICollisionBehavior(items: [greenSquare, redSquare, blueSquare])
        bounds.translatesReferenceBoundsIntoBoundary = true
        animator.addBehavior(bounds)

        let gravity = UIGravityBehavior(items: [greenSquare, redSquare, blueSquare])
        animator.addBehavior(gravity)

        let greenBounce = UIDynamicItemBehavior(items: [greenSquare])
        greenBounce.elasticity = 1
        animator.addBehavior(greenBounce)

        let redBounce = UIDynamicItemBehavior(items: [redSquare])
        redBounce.elasticity = 1
        animator.addBehavior(redBounce)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

