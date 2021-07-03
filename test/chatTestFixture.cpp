//
// Created by dimit on 03/07/2021.
//
#include "gtest/gtest.h"
#include "../chat.h"
#include "../user.h"


class chatSuite : public ::testing::Test {

protected:
     void SetUp() override{
         princesse->setName("princesse");
         solene->setName("solene");
         std:: string name_chat ("due chiachere.");
    }
    user* princesse = new user ("user1");
    user* solene = new user ("user2");
    std:: string name_chat;

};


TEST_F(chatSuite,test_set_get){
    chat c (*princesse, *solene, name_chat);
    ASSERT_EQ((c.getMyName())->getName(), princesse->getName());
    user solange("Solange");
    c.setMyName(&solange);
    ASSERT_EQ((c.getMyName())->getName(), solange.getName());
    ASSERT_EQ((c.getOtherName())->getName(),solene->getName());
    user charles("Charles");
    c.setOtherName(&charles);
    ASSERT_EQ((c.getOtherName())->getName(), charles.getName());
    ASSERT_EQ(c.getUnreadMessages(), 0);
}