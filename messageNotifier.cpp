//
// Created by dimit on 01/07/2021.
//

#include "messageNotifier.h"
#include "user.h"
void messageNotifier::attach() {
    std::shared_ptr<messageNotifier> ptr= std::make_shared<messageNotifier>(*this);
    subject->subscribe(ptr);
}

void messageNotifier::detach(){
    std::shared_ptr<messageNotifier> ptr= std::make_shared<messageNotifier>(*this);
    subject->unsubscribe(ptr);
}

void messageNotifier::update()  {
    if (active)
        messageNotifier::draw(subject->lastMessage());
}

void messageNotifier::draw (const message &ms){
    char buffer [80];
    time_t time =ms.getCurrentTime();
    struct tm *localTime = localtime (& time);
    strftime(buffer, 80, "%I:%M%p", localTime);
    std::cout << "Notifcation message:"<< std::endl;
    std::cout << "Last send message: "<< buffer << "  from " << (ms.getSender())->getName() << " to " <<
              (ms.getReceiver())->getName() << std::endl;
    std::cout << "Text: " << ms.getText() << std::endl;
}