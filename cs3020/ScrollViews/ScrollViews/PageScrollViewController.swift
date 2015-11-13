//
//  PageScrollViewController.swift
//  ScrollViews
//
//  Created by Nate Armstrong on 11/12/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit

class PageScrollViewController: UIViewController {

    @IBOutlet weak var scrollView: UIScrollView!
    @IBOutlet weak var pageControl: UIPageControl!

    var pageImages: [UIImage] = []
    var pageViews: [UIImageView?] = []

    override func viewDidLoad() {
        super.viewDidLoad()

        automaticallyAdjustsScrollViewInsets = false
        scrollView.pagingEnabled = true

        pageImages = [
            UIImage(named: "photo1.png")!,
            UIImage(named: "photo2.png")!,
            UIImage(named: "photo3.png")!,
            UIImage(named: "photo4.png")!,
            UIImage(named: "photo5.png")!,
        ]

        let pageCount = pageImages.count
        pageControl.currentPage = 0
        pageControl.numberOfPages = pageCount

        for _ in 0..<pageCount {
            pageViews.append(nil)
        }

        let pageScrollViewSize = scrollView.frame.size
        scrollView.contentSize = CGSize(width: pageScrollViewSize.width * CGFloat(pageCount), height: pageScrollViewSize.height)
    }

    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)

        loadVisiblePages()
    }

    func loadVisiblePages() {
        // First, determine which page is currently visible
        let pageWidth = scrollView.frame.size.width
        let page = Int(floor((scrollView.contentOffset.x * 2.0 + pageWidth) / (pageWidth * 2.0)))

        // Update the page control
        pageControl.currentPage = page

        // Work out which pages you want to load
        let firstPage = page - 1
        let lastPage = page + 1

        // Purge anything before the first page
        for var index = 0; index < firstPage; ++index {
            purgePage(index)
        }

        // Load pages in our range
        for index in firstPage...lastPage {
            loadPage(index)
        }

        // Purge anything after the last page
        for var index = lastPage+1; index < pageImages.count; ++index {
            purgePage(index)
        }
    }

    func loadPage(page: Int) {
        if page < 0 || page >= pageImages.count {
            // If it's outside the range of what you have to display, then do nothing
            return
        }

        // Load an individual page, first checking if you've already loaded it
        guard pageViews[page] == nil else {
            return
        }
        var frame = scrollView.bounds
        frame.origin.x = frame.size.width * CGFloat(page)
        frame.origin.y = 0.0
        frame = CGRectInset(frame, 10.0, 0.0)

        let newPageView = UIImageView(image: pageImages[page])
        newPageView.contentMode = .ScaleAspectFit
        newPageView.frame = frame
        scrollView.addSubview(newPageView)
        pageViews[page] = newPageView
    }

    func purgePage(page: Int) {
        if page < 0 || page >= pageImages.count {
            // If it's outside the range of what you have to display, then do nothing
            return
        }
        
        // Remove a page from the scroll view and reset the container array
        if let pageView = pageViews[page] {
            pageView.removeFromSuperview()
            pageViews[page] = nil
        }
    }

}

extension PageScrollViewController: UIScrollViewDelegate {

    func scrollViewDidScroll(scrollView: UIScrollView) {
        loadVisiblePages()
    }

}
