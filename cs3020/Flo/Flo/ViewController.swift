//
//  ViewController.swift
//  Flo
//
//  Created by Nate Armstrong on 11/5/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var counterView: CounterView!
    @IBOutlet weak var counterLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()

        counterLabel.text = "\(Int(counterView.counter))"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func btnPush(button: PushButtonView) {
        if button.isAddButton {
            counterView.counter++
        }
        else {
            if counterView.counter > 0 {
                counterView.counter--
            }
        }
        counterLabel.text = "\(Int(counterView.counter))"
    }

}

