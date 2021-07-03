//
// Created by dimit on 01/07/2021.
//

#include "gtest/gtest.h"
#include "../messageNotifier.h"
#include "../user.h"

TEST(MessageNotifier, isActive) {
    user a("Solange");
    user b("Charles");
    std::string name_chat("due chiechere");
    chat c(a,b,name_chat);
    std::shared_ptr<chat> ptr = std::make_shared<chat>(c);
    messageNotifier m(true,ptr);
    ASSERT_TRUE(m.isActive());
    m.setActive(false);
    ASSERT_FALSE(m.isActive());
}