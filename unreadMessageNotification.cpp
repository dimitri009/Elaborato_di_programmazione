//
// Created by dimit on 01/07/2021.
//

#include "unreadMessageNotification.h"

void unreadMessageNotification::attach(){
    std::shared_ptr<unreadMessageNotification> ptr= std::make_shared<unreadMessageNotification>(*this);
    subject->subscribe(ptr);
}

void unreadMessageNotification::detach() {
    std::shared_ptr<unreadMessageNotification> ptr= std::make_shared<unreadMessageNotification>(*this);
    subject->subscribe(ptr);
}

void unreadMessageNotification::update() {
    unreadMessageNotification::draw(subject->getUnreadMessages());
}

void unreadMessageNotification::draw(int um){
    std::cout << "Messaggi non letti: " << um << std::endl;
}