//
//  ImageScrollViewController.swift
//  ScrollViews
//
//  Created by Nate Armstrong on 11/12/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class ImageScrollViewController: UIViewController {

    @IBOutlet weak var scrollView: UIScrollView!

    var imageView: UIImageView!

    override func viewDidLoad() {
        super.viewDidLoad()

        automaticallyAdjustsScrollViewInsets = false

        let image = UIImage(named: "photo1.png")!
        imageView = UIImageView(image: image)
        imageView.frame = CGRect(origin: CGPoint(x: 0, y: 0), size: image.size)
        scrollView.addSubview(imageView)

        scrollView.contentSize = image.size

        let scrollViewFrame = scrollView.frame
        let scaleWidth = scrollViewFrame.size.width / scrollView.contentSize.width
        let scaleHeight = scrollView.frame.size.height / scrollView.contentSize.height
        let minScale = min(scaleWidth, scaleHeight)

        scrollView.minimumZoomScale = minScale
        scrollView.maximumZoomScale = 1.0
        scrollView.zoomScale = minScale
    }

}

extension ImageScrollViewController: UIScrollViewDelegate {

    func viewForZoomingInScrollView(scrollView: UIScrollView) -> UIView? {
        return imageView
    }

}
