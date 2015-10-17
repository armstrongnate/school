//
//  SecondViewController.swift
//  Todo
//
//  Created by Nate Armstrong on 9/15/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController {

    @IBOutlet weak var textField: UITextField!

    let todoManager = TodoManager()


    override func viewDidLoad() {
        super.viewDidLoad()
        textField.delegate = self
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        view.endEditing(true)
    }

    @IBAction func save(sender: AnyObject) {
        guard let todo = textField.text else {
            return
        }
        todoManager.addTodo(todo)
        textField.text = ""
        textField.resignFirstResponder()
    }

}

extension SecondViewController: UITextFieldDelegate {

    func textFieldShouldReturn(textField: UITextField) -> Bool {
        if textField == self.textField {
            save(textField)
        }
        return true
    }

}
