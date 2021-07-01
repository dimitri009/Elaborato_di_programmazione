#include <iostream>
#include <memory>

#include "chat.h"
#include "user.h"
#include "messageNotifier.h"
#include "unreadMessageNotification.h"
#include "version.h"
int main() {
    std::cout << "Chat message " << VERSION << std::endl;
    user solange("Solange");
    user charles ("Charles");
    std::shared_ptr<chat> ptr= solange.createChat(charles);
    std::shared_ptr<chat> ptr2= solange.findChat(charles);
    user princesse("Princesse");
    message foo(&solange, &charles, "Buongiorno Charles, tutto bene?");
    message bar(&charles, &solange, "Tutto bene, te?");
    message fooBar(&solange, &charles, "Anch'io tutto bene");
    messageNotifier messageNotifier(true, ptr);
    unreadMessageNotification iconBadgeMonitor(ptr);
    messageNotifier.attach();
    iconBadgeMonitor.attach();
    ptr2->addMessage(foo);
    ptr->addMessage(bar);
    ptr->addMessage(fooBar);
    try {
        ptr->readMessage(1);
        ptr2->readMessage(5);
    }
    catch (std::out_of_range &e) {
        std::cerr << "Out of range error:" << e.what() << std::endl;
    }
    solange.removeChat(charles);
}