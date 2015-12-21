//
//  ViewController.swift
//  LoginScreen
//
//  Created by Nate Armstrong on 12/1/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        let button = UIButton()
        button.translatesAutoresizingMaskIntoConstraints = false
        // button.setTranslatesAutoresizingMaskIntoConstraints(false)
        view.addSubview(button)
        button.backgroundColor = UIColor.darkGrayColor()
        button.setTitle("JOIN SPRING", forState: .Normal)
        button.setTitleColor(UIColor.whiteColor(), forState: .Normal)
        button.titleLabel!.font = UIFont.systemFontOfSize(18)
        button.layer.cornerRadius = 10

        // bottom
        let constraint = NSLayoutConstraint(
            item: button,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Bottom,
            multiplier: 1,
            constant: -10)
        view.addConstraint(constraint)
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

        let forgot = UILabel()
        forgot.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(forgot)
        forgot.text = "Forgot your password?"
        forgot.textColor = UIColor.lightGrayColor()

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: forgot,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: button,
            attribute: .Top,
            multiplier: 1,
            constant: -20))
        // CenterX
        view.addConstraint(NSLayoutConstraint(
            item: forgot,
            attribute: .CenterX,
            relatedBy: .Equal,
            toItem: view,
            attribute: .CenterX,
            multiplier: 1,
            constant: 0))

        let textFields = UIView()
        textFields.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(textFields)
        textFields.backgroundColor = UIColor.lightGrayColor()

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: textFields,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: forgot,
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

        let password = UITextField()
        password.translatesAutoresizingMaskIntoConstraints = false
        textFields.addSubview(password)
        password.placeholder = "Password"
        password.backgroundColor = UIColor.whiteColor()

        let textFieldSpace: CGFloat = 1
        let textFieldHeight: CGFloat = 50

        // bottom
        textFields.addConstraint(NSLayoutConstraint(
            item: password,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: textFields,
            attribute: .Bottom,
            multiplier: 1,
            constant: -textFieldSpace))
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

        let email = UITextField()
        email.translatesAutoresizingMaskIntoConstraints = false
        textFields.addSubview(email)
        email.placeholder = "Email"
        email.backgroundColor = UIColor.whiteColor()

        // bottom
        textFields.addConstraint(NSLayoutConstraint(
            item: email,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: password,
            attribute: .Top,
            multiplier: 1,
            constant: -textFieldSpace))
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
        // height
        email.addConstraint(NSLayoutConstraint(
            item: email,
            attribute: .Height,
            relatedBy: .Equal,
            toItem: nil,
            attribute: .NotAnAttribute,
            multiplier: 1,
            constant: textFieldHeight))

        // container top
        textFields.addConstraint(NSLayoutConstraint(
            item: textFields,
            attribute: .Top,
            relatedBy: .Equal,
            toItem: email,
            attribute: .Top,
            multiplier: 1,
            constant: -textFieldSpace))

        let branding = UIView()
        branding.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(branding)
        branding.backgroundColor = UIColor.darkGrayColor()

        // bottom
        view.addConstraint(NSLayoutConstraint(
            item: branding,
            attribute: .Bottom,
            relatedBy: .Equal,
            toItem: email,
            attribute: .Top,
            multiplier: 1,
            constant: -textFieldSpace))
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
        // top
        view.addConstraint(NSLayoutConstraint(
            item: branding,
            attribute: .Top,
            relatedBy: .Equal,
            toItem: view,
            attribute: .Top,
            multiplier: 1,
            constant: 0))
    }

}
