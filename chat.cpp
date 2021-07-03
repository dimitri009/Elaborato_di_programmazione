//
// Created by dimit on 30/06/2021.
//

#include "chat.h"
#include "user.h"

chat::chat(const user& first_user, const user& second_user){
    myName = new user (first_user.getName());
    otherName = new user (second_user.getName());
}

chat::~chat() = default;

void chat::addMessage(const message& newMsg){
    if((*myName==*(newMsg.getReceiver())||*myName==*(newMsg.getSender()))&&(*otherName==*(newMsg.getSender())
                                                                            ||*otherName==*(newMsg.getReceiver())))
        messages.push_back(newMsg);
    else
        throw std::out_of_range("users incompatible !");
    if(*myName==*(newMsg.getReceiver()))
        this->notify();
}

const message& chat::lastMessage() const{
    return messages.back();
}

void chat::readMessage(int i){
    if(i>0 && i<messages.size()) {
        if (*(messages[i].getSender()) == *myName) {
            std::cout <<"Sender: "<< (messages[i].getSender())->getName() <<", "<<"Receiver: "<<
                      (messages[i].getReceiver())->getName()<< std::endl;
            std::cout <<"Text: "<< (messages[i]).getText() << std::endl;
            (messages[i]).setRead(true);
            this->notify();
        }
    }
    else
        throw std::out_of_range(" Messaggio non presente nella chat");
}
int chat::getUnreadMessages() const{
    int i=0;
    for(const auto& message:messages)
        if(*(message.getReceiver())==*otherName)
            if (!message.isRead())
                i++;
    return i;
}
void chat::subscribe(std::shared_ptr<observer> observer) {
    observers.push_back(observer);
}
void chat::unsubscribe(std::shared_ptr<observer> observer) {
    observers.remove(observer);
}
void chat::notify() {
    for (const auto& observer: observers)
        observer->update();
}
chat::chat(user *myName, user *otherName) : myName(myName), otherName(otherName) {}

user *chat::getMyName() const {
    return myName;
}

void chat::setMyName(user *myName_) {
    chat::myName = myName_;
}

user *chat::getOtherName() const {
    return otherName;
}

void chat::setOtherName(user *otherName_) {
    chat::otherName = otherName_;
}

chat::chat(const chat &original) {

    int size = original.messages.size();
    for (int i = 0; i < size; ++i) {
        messages[i]=original.messages[i];
    }

    if (original.myName != nullptr && original.otherName){
        myName = new user(*original.myName);
        otherName = new user(*original.otherName);
    }
    else{
        myName = {nullptr};
        otherName = {nullptr};
    }
}

chat& chat::operator=(const chat &right) {
    if (this != &right) {
        if (myName != nullptr && otherName != nullptr){
            delete myName;
            delete otherName;
        }
        observers.assign(right.observers.begin(),right.observers.end());
        int size = right.messages.size();
        for (int i = 0; i < size; ++i) {
            messages[i]=right.messages[i];
        }
        if (right.myName != nullptr && right.otherName){
            myName = new user(*right.myName);
            otherName = new user(*right.otherName);
        }
        else{
            myName = nullptr;
            otherName = nullptr;
        }
    }
    return *this;
}

const std::vector<message> &chat::getMessages() const {
    return messages;
}

