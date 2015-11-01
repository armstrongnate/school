//
//  ViewController.swift
//  PasswordStorage
//
//  Created by Nate Armstrong on 10/6/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import CoreData

class ViewController: UIViewController {

    // MARK: - Outlets

    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var passwordField: UITextField!

    // MARK: - Properties

    var managedObjectContext: NSManagedObjectContext {
        return (UIApplication.sharedApplication().delegate as! AppDelegate).managedObjectContext
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - Actions

    @IBAction func loadAction() {
        guard let name = nameField.text else {
            return
        }
        let request = NSFetchRequest(entityName: "Login")
        request.returnsObjectsAsFaults = false
        request.predicate = NSPredicate(format: "name = %@", name)
        do {
            if let result = try managedObjectContext.executeFetchRequest(request).first {
                passwordField.text = (result as! NSManagedObject).valueForKey("password") as? String
            }
        } catch {
            print("fetch error: \(error)")
        }
    }

    @IBAction func saveAction() {
        guard let name = nameField.text, password = passwordField.text
            where !name.isEmpty && !password.isEmpty else {
            // invalid name or password
            return
        }
        let login = NSEntityDescription.insertNewObjectForEntityForName("Login", inManagedObjectContext: managedObjectContext)
        login.setValue(name, forKey: "name")
        login.setValue(password, forKey: "password")
        do {
            try managedObjectContext.save()
            print("saved!")
            nameField.text = ""
            passwordField.text = ""
        } catch {
            print("save error: \(error)")
        }
    }


}

