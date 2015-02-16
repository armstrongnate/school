# Design Spec

* Nate Armstrong
* Senior Project 2015

## Synopsis
I will be making an app for managing meetings. The purpose of the app is so that
people that participate in a lot of meetings can keep track of meeting details
such as the agenda, notes and action items.

## Hardware
The target platform is iOS and Mac OS X. Any iPhone, iPad or iPad Touch running
iOS 8 will be supported as well as any Mac running Yosemite.

## Software

### Language: Swift
Though the language is immature the point of this project is to try new and cutting
edge technologies within the iOS framework so Swift is a no-brainer.

### Persistence: Core Data and CloudKit
The app will be fully functional both online and offline. To accomplish this I will
use Core Data for local storage and CloudKit for cloud storage.

#### Core Data
Core Data in combiination with sqlite is how I will store data on the device. Core
Data is built into the system framework. I have some experience with it but not much
which is why I've chosen to use it.

#### CloudKit
CloudKit is a new framework introduced in iOS 8. It uses the user's iCloud account
for storing things in the cloud so that the data will accessible on all the user's
devices. Instead of writing my own custom web api for a backend I'll use CloudKit
for cloud storage.

## What else?

This app will make use of many Cocoa API's that I've been eager to try out and
become familiar with. Some of those API's include:
* UIAnimations: animations are a great way to achieve a fluid and catchy ui. They
are often times what divides a good app from a great app
* AutoLayout and size classes: i want the app to work and look as well on an iPhone
as it does on an iPad and full computer screen. Using the latest API's I want to
achieve this without duplicating code or writing 2 separate apps for the different
screen sizes (iOS only, the mac app will obviously have to be its own app)
* Push Notifications: a user will be notified if they are added to a meeting or
if changes on a meeting they are attending receives and changes. I will utilize both
CloudKit and Apple Push Service (APS) if necessary.
* Location: the user will be able to specify a location of a meeting. I will use
Apple's CLLocation API to query locations and check if a user is near the location
of a meeting.
* Today Widget: new with iOS 8 is the Today Widget API. I will create a widget that
lists the user's upcoming meetings.

## Summary
Using Apple's Swift language I will make an app for the iPhone, iPad and the Mac
that utilizes popping animations, notifications, widgets, cloud and local data
persistence and location features.
