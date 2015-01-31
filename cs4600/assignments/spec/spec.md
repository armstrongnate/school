# CS 4600 Project Specification

## By Nate Armstrong
## Spring, 2015

### Overview
An application for organizing meetings. Users of the app will have a place to keep track
of upcoming meetings, manage the content of their meetings and store that content
in a secure and searchable database.

Targeted platforms
* **iOS** (both iPad and iPhone).

### Part 1 - Groundwork
* Store meetings locally and in the cloud.
* Add attendees to meetings
* Meetings are synced across organizer and attendee devices

A `Meeting` will have many `User`s and a `User` will have many `Meeting`s.

#### Meeting Fields

field | type
----- | -----
title | string
location | string
starts | date
ends | date
notes | attributed string
organizer | reference user

#### User Fields

field | type
----- | ----
name | string
email | string

### Part 2 - Add Features
* attach files (images, audio, etc)
* push notifications
* Today Widget


Example use:
1. Bob is a manager of a project and needs to schedule a meeting with his secretary,
Sally, a designer, Daisy, and his client, Cliff.
2. Bob launches the app and taps a button to create a new meeting.
3. He titles the meeting _Quarter 2 Sync Up_ and sets the date for January 1, 2015 at
2:30 pm for 1 hour and the sets the location to his office building. There is a section of
the meeting form for adding `Attendees`. Bob adds Sally, Daisy and Cliff to the
meeting using the contacts on his phone and taps save which creates a meeting on
his phone and in the cloud.
4. Well structured meetings have an agenda so Bob adds a few topics of discussion
for the upcoming meeting so they don't get distracted. He prepares a Keynote presentation
and attaches it to the meeting. He also wants Sally to be able to take notes so
he grants her collaborator priveledges.
5. Sally and Daisy also have the app so the meeting Bob just created is available
on their devices since they were added as attendees. In fact, they received a notification
telling them about the newly created meeting.
6. Since Cliff does not have the app but was added to the meeting as an attendee he
received an email from Bob containing the details of the meeting and a link to download
the meeting app.
7. Bob, Sally and Daisy receive a notification some time before the meeting reminding
them of its time and location.
8. In the meeting, Sally takes notes while Bob carefully sticks to the predefined
agenda, checking off agenda items as they are discussed.
9. Daisy sketches a few things on the whiteboard in Bill's office. Bill wants the
sketches to stick around so Sally snaps a picture using the app and saves them to
the meeting.
10. Toward the end of the meeting Cliff begins discussing a new feature he would
like implemented. Sally can't type fast enough so she uses the app to audio record
Cliff's voice as he speaks. The audio is attached to the meeting just like the
images and notes so everything they might need later is in one central place.
11. Bill wants Daisy to design the new feature Cliff just described so he creates
an _Action Item_ which is tied to the meeting and assigns it to Daisy. All Action
Items are accumulated within their own screen in the app and Agenda items can be
quickly created from existing or completed Action Items.
12. Weeks later, Daisy is working on the design for the new feature and is unsure
of one small detail. She pulls up the meeting notes and listens to the audio recording
and is pleasantly surprised to have her question answered without having to trouble
Bill or Cliff.

### Technologies and APIs that will be used
* iCloud Sync (CloudKit)
* Core Data
* Today Widget
* Push Notifications
* Location

### Wishlist (if I have time)
* Mac app
