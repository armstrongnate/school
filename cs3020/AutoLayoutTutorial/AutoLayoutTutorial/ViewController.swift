//
//  ViewController.swift
//  AutoLayoutTutorial
//
//  Created by Nate Armstrong on 11/30/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // terms
        let terms = UILabel()
        terms.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(terms)
        terms.text = "By joining you agree to our Terms & Privacy Policy"
        terms.font = UIFont.systemFontOfSize(12)
        terms.textColor = UIColor.lightGrayColor()
        terms.textAlignment = .Center

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: terms,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: view,
            attribute: .BottomMargin,
            multiplier: 1,
            constant: -8))
        // leading
        view.addConstraint(NSLayoutConstraint(
            item: terms,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: view,
            attribute: .LeadingMargin,
            multiplier: 1,
            constant: 0))
        // trailing
        view.addConstraint(NSLayoutConstraint(
            item: terms,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: view,
            attribute: .TrailingMargin,
            multiplier: 1,
            constant: 0))

        // submit button
        let button = UIButton(type: .System)
        button.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(button)
        button.backgroundColor = UIColor.darkGrayColor()
        button.setTitleColor(UIColor.whiteColor(), forState: .Normal)
        button.setTitle("JOIN SPRING", forState: .Normal)

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: button,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: terms,
            attribute: .Top,
            multiplier: 1,
            constant: -30))
        // leading
        view.addConstraint(NSLayoutConstraint(
            item: button,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: view,
            attribute: .LeadingMargin,
            multiplier: 1,
            constant: 0))
        // trailing
        view.addConstraint(NSLayoutConstraint(
            item: button,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: view,
            attribute: .TrailingMargin,
            multiplier: 1,
            constant: 0))
        // height
        button.addConstraint(NSLayoutConstraint(
            item: button,
            attribute: .Height,
            relatedBy: .Equal,
            toItem: nil,
            attribute: .NotAnAttribute,
            multiplier: 1,
            constant: 50))

        // text fields container
        let textFields = UIView()
        textFields.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(textFields)
        textFields.backgroundColor = UIColor.lightGrayColor()

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: textFields,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: button,
            attribute: .Top,
            multiplier: 1,
            constant: -20))
        // leading
        view.addConstraint(NSLayoutConstraint(
            item: textFields,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Leading,
            multiplier: 1,
            constant: 0))
        // trailing
        view.addConstraint(NSLayoutConstraint(
            item: textFields,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Trailing,
            multiplier: 1,
            constant: 0))

        let textFieldHeight: CGFloat = 50
        let textFieldSpacing: CGFloat = 0.5

        // email
        let email = UITextField()
        email.translatesAutoresizingMaskIntoConstraints = false
        textFields.addSubview(email)
        email.placeholder = "Email"
        email.backgroundColor = UIColor.whiteColor()

        // text inset hack
        email.layer.sublayerTransform = CATransform3DMakeTranslation(15, 0, 0)

        // top
        textFields.addConstraint(NSLayoutConstraint(
            item: email,
            attribute: .Top,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Top,
            multiplier: 1,
            constant: textFieldSpacing))
        // height
        email.addConstraint(NSLayoutConstraint(
            item: email,
            attribute: .Height,
            relatedBy: .Equal,
            toItem: nil,
            attribute: .NotAnAttribute,
            multiplier: 1,
            constant: textFieldHeight))
        // leading
        textFields.addConstraint(NSLayoutConstraint(
            item: email,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Leading,
            multiplier: 1,
            constant: 0))
        // trailing
        textFields.addConstraint(NSLayoutConstraint(
            item: email,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Trailing,
            multiplier: 1,
            constant: 0))

        // password
        let password = UITextField()
        password.translatesAutoresizingMaskIntoConstraints = false
        textFields.addSubview(password)
        password.placeholder = "Password"
        password.backgroundColor = UIColor.whiteColor()

        // text inset hack
        password.layer.sublayerTransform = CATransform3DMakeTranslation(15, 0, 0)

        // top
        textFields.addConstraint(NSLayoutConstraint(
            item: password,
            attribute: .Top,
            relatedBy: .Equal,
            toItem: email,
            attribute: .Bottom,
            multiplier: 1,
            constant: textFieldSpacing))
        // leading
        textFields.addConstraint(NSLayoutConstraint(
            item: password,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Leading,
            multiplier: 1,
            constant: 0))
        // trailing
        textFields.addConstraint(NSLayoutConstraint(
            item: password,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Trailing,
            multiplier: 1,
            constant: 0))
        // height
        password.addConstraint(NSLayoutConstraint(
            item: password,
            attribute: .Height,
            relatedBy: .Equal,
            toItem: nil,
            attribute: .NotAnAttribute,
            multiplier: 1,
            constant: textFieldHeight))
        textFields.addConstraint(NSLayoutConstraint(
            item: password,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Bottom,
            multiplier: 1,
            constant: -textFieldSpacing))

        // brand container
        let branding = UIView()
        branding.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(branding)
        branding.backgroundColor = UIColor.darkGrayColor()

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: branding,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Top,
            multiplier: 1,
            constant: 0))
        // top
        view.addConstraint(NSLayoutConstraint(
            item: branding,
            attribute: .Top,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Top,
            multiplier: 1,
            constant: 0))
        // leading
        view.addConstraint(NSLayoutConstraint(
            item: branding,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Leading,
            multiplier: 1,
            constant: 0))
        // trailing
        view.addConstraint(NSLayoutConstraint(
            item: branding,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Trailing,
            multiplier: 1,
            constant: 0))

        // image
        let imageView = UIImageView()
        imageView.translatesAutoresizingMaskIntoConstraints = false
        branding.addSubview(imageView)
        let url = "https://goo.gl/PcxyrU"
        imageView.image = UIImage(data: NSData(contentsOfURL: NSURL(string: url)!)!)
        imageView.contentMode = .ScaleAspectFill
        imageView.clipsToBounds = true

        // bottom
        branding.addConstraint(NSLayoutConstraint(
            item: imageView,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Bottom,
            multiplier: 1,
            constant: -4))
        // top
        branding.addConstraint(NSLayoutConstraint(
            item: imageView,
            attribute: .Top,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Top,
            multiplier: 1,
            constant: 0))
        // leading
        branding.addConstraint(NSLayoutConstraint(
            item: imageView,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Leading,
            multiplier: 1,
            constant: 0))
        // trailing
        branding.addConstraint(NSLayoutConstraint(
            item: imageView,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Trailing,
            multiplier: 1,
            constant: 0))

        // tagline
        let tagline = UILabel()
        tagline.translatesAutoresizingMaskIntoConstraints = false
        branding.addSubview(tagline)
        tagline.text = "Shopping on your phone will never be the same."
        tagline.textColor = UIColor(white: 0.2, alpha: 1)
        tagline.textAlignment = .Center
        tagline.numberOfLines = 0
        tagline.lineBreakMode = .ByWordWrapping
        tagline.shadowColor = UIColor(white: 1.0, alpha: 0.6)
        tagline.shadowOffset = CGSize(width: 1, height: 1)

        let taglineMargin: CGFloat = 80

        // bottom
        branding.addConstraint(NSLayoutConstraint(
            item: tagline,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Bottom,
            multiplier: 1,
            constant: -15))
        // leading
        branding.addConstraint(NSLayoutConstraint(
            item: tagline,
            attribute: .Leading,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Leading,
            multiplier: 1,
            constant: taglineMargin))
        // trailing
        branding.addConstraint(NSLayoutConstraint(
            item: tagline,
            attribute: .Trailing,
            relatedBy: .Equal,
            toItem: branding,
            attribute: .Trailing,
            multiplier: 1,
            constant: -taglineMargin))
    }

}
