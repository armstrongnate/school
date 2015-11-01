//
//  ViewController.swift
//  WebContent
//
//  Created by Nate Armstrong on 9/17/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import SafariServices

class ViewController: UIViewController {

    @IBOutlet weak var webView: UIWebView!

    var page: String? {
        didSet {
            guard let page = page, url = NSURL(string: page) else {
                return
            }
            let task = NSURLSession.sharedSession().dataTaskWithURL(url) { (data, response, error) in
                if error == nil {
                    let content = String(NSString(data: data!, encoding: NSUTF8StringEncoding)!)
                    dispatch_async(dispatch_get_main_queue()) {
                        self.webView.loadHTMLString(content, baseURL: nil)
                    }
                }
            }
            task.resume()
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        page = "https://github.com/n8armstrong"
    }

}

extension ViewController: UITextFieldDelegate {

    func textFieldShouldReturn(textField: UITextField) -> Bool {
        page = textField.text
        return true
    }

}
