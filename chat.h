//
// Created by dimit on 30/06/2021.
//

#ifndef ELABORATO_DI_PROGRAMMAZIONE_CHAT_H
#define ELABORATO_DI_PROGRAMMAZIONE_CHAT_H

#include <iostream>
#include <memory>
#include <vector>
#include <list>

#include "message.h"
#include "subject.h"
#include "observer.h"

class user;
class chat : public subject {
public:
    chat(const user& first_user, const user& second_user, std::string& name_chat_);

     ~chat() override;

    void addMessage(const message& newMsg);

    const message& lastMessage() const;

    void readMessage(int i);

    int getUnreadMessages() const;

    void subscribe(std::shared_ptr<observer> observers) override;

    void unsubscribe(std::shared_ptr<observer> observers) override;

    void notify() override;

    user *getMyName() const;

    void setMyName(user *myName);

    user *getOtherName() const;

    void setOtherName(user *otherName);

    chat(user *myName, user *otherName);

    chat(const chat& original);
    chat & operator=(const chat& right);

    const std::vector<message> &getMessages() const;

private:
    std::list<std::shared_ptr<observer>> observers;
    std::vector<message> messages;
    user* myName;
    user* otherName;
    std:: string name_chat;
};



#endif //ELABORATO_DI_PROGRAMMAZIONE_CHAT_H
