//
//  EarthquakeCell.swift
//  Earthquakes
//
//  Created by Nate Armstrong on 10/21/15.
//  Copyright © 2015 Nate Armstrong. All rights reserved.
//

import UIKit
import EarthShakeKit

class EarthquakeCell: UICollectionViewCell {

    // MARK: Constants

    static let reuseIdentifier = "earthquakeCell"

    // MARK: Properties

    var magnitudeLabel: UILabel!
    var placeLabel: UILabel!
    var earthquake: ESEarthquake! {
        didSet {
            backgroundColor = UIColor.colorForMagnitude(earthquake.magnitudeCategory())
            magnitudeLabel.text = String(format: "%.1f", earthquake.magnitude.floatValue)
            placeLabel.text = earthquake.place
            setNeedsUpdateConstraints()
        }
    }
    override var selected: Bool {
        didSet {
            layer.borderWidth = selected ? 4 : 0
        }
    }

    init() {
        super.init(frame: CGRectZero)
        setup()
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
        setup()
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        setup()
    }

    // MARK: Instance Methods

    func setup() {
        layer.borderColor = UIColor.earthquakeCellBorderColor().CGColor
        layer.borderWidth = 0

        // magnitude label
        magnitudeLabel = UILabel()
        magnitudeLabel.translatesAutoresizingMaskIntoConstraints = false
        magnitudeLabel.font = .earthquakeCellMagnitudeFont()
        magnitudeLabel.textColor = .earthquakeCellMagnitudeTextColor()
        magnitudeLabel.adjustsFontSizeToFitWidth = true
        magnitudeLabel.minimumScaleFactor = 0.5
        magnitudeLabel.textAlignment = .Center
        contentView.addSubview(magnitudeLabel)

        // place label
        placeLabel = UILabel()
        placeLabel.translatesAutoresizingMaskIntoConstraints = false
        placeLabel.font = .earthquakeCellPlaceFont()
        placeLabel.textColor = .earthquakeCellPlaceTextColor()
        placeLabel.lineBreakMode = .ByWordWrapping;
        placeLabel.textAlignment = .Center;
        placeLabel.numberOfLines = 0;
        placeLabel.shadowColor = UIColor(white:0.3, alpha:1.0)
        placeLabel.shadowOffset = CGSizeMake(0.0, 1.0)
        contentView.addSubview(placeLabel)
    }

    override func updateConstraints() {
        super.updateConstraints()

        let magMargin: CGFloat = 2
        magnitudeLabel.wta_addEdgeConstraintsToSuperview(UIEdgeInsetsMake(magMargin, magMargin, magMargin, magMargin))

        let placeMargin: CGFloat = 4
        placeLabel.wta_addEdgeConstraintsToSuperview(UIEdgeInsetsMake(placeMargin, placeMargin, placeMargin, placeMargin))
    }

}
