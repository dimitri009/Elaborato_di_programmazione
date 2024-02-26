# Elaborato_di_programmazione, Chat Message Project
Programming lab || Unifi computer engineering 2020/2021

**Overview**

This C++ project aims to implement a system for managing chat messages between users. It includes classes representing users, chat messages, and chats between two users. The project utilizes the observer design pattern to facilitate notifications about unread messages.

**Features**

User Management: Users can create chats with other users, remove chats, and retrieve existing chats.
Chat Messaging: Users can exchange messages within chats.
Message Notifications: MessageNotifier class provides notifications for new messages in chats.
Unread Message Notification: UnreadMessageNotification class manages notifications for unread messages.
Files Structure
chat.cpp & chat.h: Implementation and header files for the Chat class.
message.cpp & message.h: Implementation and header files for the Message class.
messageNotifier.cpp & messageNotifier.h: Implementation and header files for the MessageNotifier class.
unreadMessageNotification.cpp & unreadMessageNotification.h: Implementation and header files for the UnreadMessageNotification class.
user.cpp & user.h: Implementation and header files for the User class.
observer.h & subject.h: Header files defining the Observer and Subject interfaces.
version.h: Version information for the project.
main.cpp: Main program demonstrating the usage of classes and functionalities.
test directory: Contains unit tests for the project.

**Usage**

To use the project, include the necessary header files in your C++ program and link against the implementation files. Refer to the main.cpp file for usage examples.

**Testing**

Unit tests for the project are available in the test directory. You can run these tests using a testing framework like Google Test.
