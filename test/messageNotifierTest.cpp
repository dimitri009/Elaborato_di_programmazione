//
// Created by dimit on 01/07/2021.
//

#include "gtest/gtest.h"
#include "../messageNotifier.h"
#include "../user.h"

TEST(MessageNotifier, isActive) {
    user a("Solange");
    user b("Charles");
    chat c(a,b);
    std::shared_ptr<chat> ptr = std::make_shared<chat>(c);
    messageNotifier m(true,ptr);
    ASSERT_TRUE(m.isActive());
    m.setActive(false);
    ASSERT_FALSE(m.isActive());
}