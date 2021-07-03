//
// Created by dimit on 01/07/2021.
//

#include "gtest/gtest.h"
#include "../chat.h"
#include "../user.h"


TEST(chat,functions){
    user princesse("princesse");
    user solene("solene");
    std:: string name_chat ("due chiachere.");
    chat c (princesse, solene, name_chat);
    message mes (&princesse,&solene, "Buongiorno Solène, tutto bene?");
    c.addMessage (mes);
    ASSERT_EQ(c.getUnreadMessages(), 1);
    c.addMessage (mes);
    ASSERT_EQ(c.getUnreadMessages(), 2);
    c.addMessage (mes);
    ASSERT_EQ(c.getUnreadMessages(), 3);
    c.addMessage (mes);
    ASSERT_EQ(c.getUnreadMessages(), 4);
    c.addMessage (mes);
    ASSERT_EQ(c.getUnreadMessages(), 5);

    /* ASSERT_EQ(c.lastMessage(), mes);*/
    c.readMessage(3);
    ASSERT_EQ(c.getUnreadMessages(), 4);
    c.readMessage(1);
    ASSERT_EQ(c.getUnreadMessages(), 3);
    c.readMessage(2);
    ASSERT_EQ(c.getUnreadMessages(), 2);
    ASSERT_THROW(c.readMessage(5), std::out_of_range);
    ASSERT_THROW(c.readMessage(6), std::out_of_range);
}

TEST(chat, add_message){
    user princesse("princesse");
    user solene("solene");
    std:: string name_chat ("due chiachere.");
    chat c (princesse, solene, name_chat);
    user solange("Solange");
    user charles("Charles");
    message mes (&solange,&charles, "Questo messaggio non sarà inoltrato");
    ASSERT_THROW(c.addMessage (mes), std::out_of_range);
    ASSERT_TRUE(c.getMessages().empty());
}