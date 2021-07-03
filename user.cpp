//
// Created by dimit on 30/06/2021.
//

#include "user.h"
#include "chat.h"

user::~user() = default;

std::shared_ptr<chat> user::createChat (user& u, std::string& name_chat_){
    chat *c = new chat ((*this), u, name_chat_);
    std::shared_ptr<chat> ptr = std::make_shared<chat>(*c);
    chats.insert(std::make_pair(name_chat_,ptr));
    u.addChat(ptr);
    return ptr;
}

void user::removeChat(std:: string& name_chat_){
    auto it=chats.find(name_chat_);
    chats.erase(it);
}

void user::addChat(std::shared_ptr<chat> &c) {
    chats.insert(std::make_pair(c->getNameChat(),c));
}
std::shared_ptr<chat> user::findChat(std:: string& name_chat_){
    auto it=chats.find(name_chat_);
    return (it->second);
}

bool user::operator==(const user &right) {
    return name == right.getName();
}