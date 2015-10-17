//
//  FirstViewController.swift
//  Todo
//
//  Created by Nate Armstrong on 9/15/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

protocol TodoListProtocol {
    var todoItems: [String] { get }
}

class TodoManager: TodoListProtocol {

    let itemsKey = "todos"
    var todoItems: [String] {
        return NSUserDefaults.standardUserDefaults().objectForKey(itemsKey) as? [String] ?? []
    }

    func addTodo(todo: String) {
        var items = todoItems
        items.append(todo)
        NSUserDefaults.standardUserDefaults().setObject(items, forKey: itemsKey)
    }

    func removeTodo(index: Int) {
        var items = todoItems
        items.removeAtIndex(index)
        NSUserDefaults.standardUserDefaults().setObject(items, forKey: itemsKey)
    }

}

class FirstViewController: UIViewController {

    @IBOutlet weak var tableView: UITableView!

    var data = TodoManager()


    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        tableView.reloadData()
    }

}

extension FirstViewController: UITableViewDataSource {

    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return data.todoItems.count
    }

    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("todo")!
        cell.textLabel?.text = data.todoItems[indexPath.row]

        return cell
    }

}

extension FirstViewController: UITableViewDelegate {

    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        tableView.deselectRowAtIndexPath(indexPath, animated: true)
    }

    func tableView(tableView: UITableView, commitEditingStyle editingStyle: UITableViewCellEditingStyle, forRowAtIndexPath indexPath: NSIndexPath) {
        if editingStyle == .Delete {
            tableView.beginUpdates()
            data.removeTodo(indexPath.row)
            tableView.deleteRowsAtIndexPaths([indexPath], withRowAnimation: .Top)
            tableView.endUpdates()
        }
    }

}