//
//  GameScene.swift
//  SpriteKitSimpleGame
//
//  Created by Nate Armstrong on 10/27/15.
//  Copyright (c) 2015 Nate Armstrong. All rights reserved.
//

import SpriteKit

func + (left: CGPoint, right: CGPoint) -> CGPoint {
    return CGPoint(x: left.x + right.x, y: left.y + right.y)
}

func - (left: CGPoint, right: CGPoint) -> CGPoint {
    return CGPoint(x: left.x - right.x, y: left.y - right.y)
}

func * (point: CGPoint, scalar: CGFloat) -> CGPoint {
    return CGPoint(x: point.x * scalar, y: point.y * scalar)
}

func / (point: CGPoint, scalar: CGFloat) -> CGPoint {
    return CGPoint(x: point.x / scalar, y: point.y / scalar)
}

#if !(arch(x86_64) || arch(arm64))

    func sqrt(a: CGPoint) -> CGFloat {
        return sqrtf(Float(a))
    }

#endif

extension CGPoint {

    func length() -> CGFloat {
        return sqrt(x*x + y*y)
    }

    func normalized() -> CGPoint {
        return self / length()
    }

}

class GameScene: SKScene {

    let player = SKSpriteNode(imageNamed: "player")

    override func didMoveToView(view: SKView) {
        super.didMoveToView(view)

        backgroundColor = SKColor.whiteColor()

        player.position = CGPoint(x: size.width * 0.1, y: size.height * 0.5)
        addChild(player)

        // add monsters
        let actions = [
            SKAction.runBlock(addMonster),
            SKAction.waitForDuration(1.0)
        ]
        runAction(SKAction.repeatActionForever(SKAction.sequence(actions)))
    }

    func random() -> CGFloat {
        return CGFloat(Float(arc4random()) / 0xFFFFFFFF)
    }

    func random(min min: CGFloat, max: CGFloat) -> CGFloat {
        return random() * (max - min) + min
    }

    func addMonster() {
        let monster = SKSpriteNode(imageNamed: "monster")

        let actualY = random(min: monster.size.height/2, max: size.height - monster.size.height/2)
        let actualDuration = NSTimeInterval(random(min: 2, max: 4))

        monster.position = CGPoint(x: size.width + monster.size.width/2, y: actualY)
        addChild(monster)

        let actionMove = SKAction.moveTo(CGPoint(x: -monster.size.width/2, y: actualY), duration: actualDuration)

        let actionMoveDone = SKAction.removeFromParent()

        monster.runAction(SKAction.sequence([actionMove, actionMoveDone]))
    }

    override func touchesEnded(touches: Set<UITouch>, withEvent event: UIEvent?) {
        super.touchesBegan(touches, withEvent: event)

        if let touch = touches.first {
            let loc = touch.locationInNode(self)

            let projectile = SKSpriteNode(imageNamed: "projectile")
            projectile.position = player.position

            let offset = loc - projectile.position

            // don't allow shooting backwards
            if (offset.x < 0) {
                return
            }

            addChild(projectile)

            let destination = offset.normalized() * 1000 + projectile.position

            let actionMove = SKAction.moveTo(destination, duration: 2.0)
            let actionMoveDone = SKAction.removeFromParent()

            projectile.runAction(SKAction.sequence([actionMove, actionMoveDone]))
        }
    }

}
