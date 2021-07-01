//
// Created by dimit on 01/07/2021.
//

#include "gtest/gtest.h"
#include "../user.h"

TEST(user, GetterSetter){
    user utente ("Solange");
    ASSERT_EQ(utente.getName(), "Solange");
    utente.setName("Charles");
    ASSERT_EQ(utente.getName(), "Charles");
    ASSERT_TRUE(utente==utente);
}