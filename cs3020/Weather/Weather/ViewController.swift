//
//  ViewController.swift
//  Weather
//
//  Created by Nate Armstrong on 9/29/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var cityTextField: UITextField!
    @IBOutlet weak var resultLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func getWeather(sender: UIButton?) {
        guard var city = cityTextField.text else {
            resultLabel.text = "City invalid."
            return
        }
        resultLabel.text = "Please wait..."
        city = city.stringByReplacingOccurrencesOfString(" ", withString: "-")
        if let url = NSURL(string: "http://www.weather-forecast.com/locations/\(city)/forecasts/latest") {
            let task = NSURLSession.sharedSession().dataTaskWithURL(url) { [weak self] (rawData, response, error) in
                guard let rawData = rawData else {
                    self?.resultLabel.text = "Error: \(error)"
                    return
                }
                func sendReport(report: String) {
                    dispatch_async(dispatch_get_main_queue()) {
                        self?.resultLabel.text = report
                    }
                }
                if let data = NSString(data: rawData, encoding: NSUTF8StringEncoding) {
                    let chunks = data.componentsSeparatedByString("<span class=\"phrase\">")
                    if chunks.count < 2 {
                        sendReport("Invalid response")
                        return
                    }
                    let chunks2 = chunks[1].componentsSeparatedByString("</span>")
                    if chunks2.count < 2 {
                        sendReport("Invalid response")
                    }
                    let report = chunks2[0]
                    let pretty = report.stringByReplacingOccurrencesOfString("&deg;", withString: "º")
                    sendReport(pretty)
                }
            }
            task.resume()
        }
        else {
            resultLabel.text = "Invalid url."
        }
    }


}

