//
//  ViewController.swift
//  HelloSwiftProject
//
//  Created by Lian Yang on 2020/12/12.
//

import UIKit
import MapKit

class ViewController: UIViewController {
    
    @IBOutlet weak var inputField: UITextField!
    
    @IBAction func showValue(_ sender: Any) {
        guard let value = inputField.text else {
            return
        }
        
        let alert = UIAlertController(title: "confirm_alert", message: value, preferredStyle: .alert)
        let action = UIAlertAction(title: "confirm_action", style: .default, handler: nil)
        alert.addAction(action)
        
        present(alert, animated: true, completion: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    
}

