//
// Created by dimit on 01/07/2021.
//

#include "gtest/gtest.h"
#include "../chat.h"
#include "../user.h"

std::string name1 = "Princesse";
std::string name2 = "Solene";
user princesse(name1);
user solene(name2);

TEST(chat,GetterSetter){
    chat c (princesse, solene);
    ASSERT_EQ((c.getMyName())->getName(), princesse.getName());
    user solange("Solange");
    c.setMyName(&solange);
    ASSERT_EQ((c.getMyName())->getName(), solange.getName());
    ASSERT_EQ((c.getOtherName())->getName(),solene.getName());
    user charles("Charles");
    c.setOtherName(&charles);
    ASSERT_EQ((c.getOtherName())->getName(), charles.getName());
    ASSERT_EQ(c.getUnreadMessages(), 0);
}

TEST(chat,functions){
    chat c (princesse, solene);
    message mes (&princesse,&solene, "Buongiorno Solène, tutto bene?");
    c.addMessage (mes);
    c.addMessage (mes);
    c.addMessage (mes);
    c.addMessage (mes);
    c.addMessage (mes);

    /* ASSERT_EQ(c.lastMessage(), mes);*/
    c.readMessage(3);
    c.readMessage(1);
    c.readMessage(2);
    ASSERT_EQ(c.getUnreadMessages(), 2);
    ASSERT_THROW(c.readMessage(5), std::out_of_range);
    ASSERT_THROW(c.readMessage(6), std::out_of_range);
}

TEST(chat, add_message){
    chat c (princesse, solene);
    user solange("Solange");
    user charles("Charles");
    message mes (&solange,&charles, "Questo messaggio non sarà inoltrato");
    c.addMessage (mes);
    ASSERT_TRUE(c.getMessages().empty());
}