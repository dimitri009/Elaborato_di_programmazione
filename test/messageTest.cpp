//
// Created by dimit on 01/07/2021.
//

#include "gtest/gtest.h"
#include "../message.h"
#include "../user.h"

TEST(Message, GetterSetter) {
    user solange("Solange");
    user charles("Charles");
    message mes(&solange, &charles, "Buongiorno Charles, come stai ?");
    ASSERT_EQ((mes.getSender())->getName(), solange.getName());
    ASSERT_EQ((mes.getReceiver())->getName(), charles.getName());
    ASSERT_EQ(mes.getText(), "Buongiorno Charles, come stai ?");
    ASSERT_EQ(mes.isRead(), false);
    mes.setRead(true);
    ASSERT_EQ(mes.isRead(), true);

}