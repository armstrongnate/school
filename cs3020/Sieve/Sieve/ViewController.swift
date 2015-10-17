//
//  ViewController.swift
//  Sieve
//
//  Created by Nate Armstrong on 9/8/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var slider: UISlider!
    @IBOutlet weak var numberLabel: UILabel!
    @IBOutlet weak var primeLabel: UILabel!

    var sieve: [Bool]!

    override func viewDidLoad() {
        super.viewDidLoad()
        sieve = calculateSieve(Int(slider.maximumValue) + 1)
        updateUI()
    }

    func updateUI() {
        let n = Int(slider.value)
        numberLabel.text = "\(n)"
        primeLabel.text = isPrime(n) ? "is prime" : "is NOT prime"
    }

    func isPrime(n: Int) -> Bool {
        return sieve[n]
    }

    func calculateSieve(n: Int) -> [Bool] {
        var a = [Bool](count: n, repeatedValue: true)
        a[0] = false
        a[1] = false
        for i in 2..<n {
            if a[i] {
                for var j=i*2; j<n; j+=i {
                    a[j] = false
                }
            }
        }
        return a
    }

    @IBAction func sliderValueChanged(sender: AnyObject) {
        updateUI()
    }

}

