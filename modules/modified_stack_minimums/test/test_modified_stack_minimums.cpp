// Copyright 2021 Novozhilova Ekaterina

#include <gtest/gtest.h>
#include <iostream>
#include "include/modified_stack_minimums.h"

TEST(Novozhilova_Ekaterina_modified_stack_Test, testgetSize) {
    ModifiedStack mystack(6);
    ASSERT_EQ(6, mystack.getSize());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testConstructor) {
    ModifiedStack mystack1(6);
    ModifiedStack mystack2(mystack1);
    ASSERT_EQ(6, mystack2.getSize());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsEmptyPositive) {
    ModifiedStack mystack(10);
    bool res = false;
    ASSERT_TRUE(mystack.isEmpty());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsFullPositive) {
    ModifiedStack mystack(3);
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    bool res = false;
    ASSERT_TRUE(mystack.isFull());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsEmptyNegative) {
    ModifiedStack mystack(3);
    mystack.push(1);
    bool res = true;
    ASSERT_FALSE(mystack.isEmpty());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testIsFullNegative) {
    ModifiedStack mystack(3);
    mystack.push(1);
    mystack.push(2);
    bool res = true;
    ASSERT_FALSE(mystack.isFull());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testgetMin) {
    ModifiedStack mystack(4);
    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    ASSERT_EQ(1, mystack.getMin());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testgetMin_shuffledOrder) {
    ModifiedStack mystack(4);
    mystack.push(3);
    mystack.push(1);
    mystack.push(2);
    ASSERT_EQ(1, mystack.getMin());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testGetTop) {
    ModifiedStack mystack(5);
    mystack.push(13);
    mystack.push(5);
    mystack.push(26);
    ASSERT_EQ(26, mystack.getTop());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testPop) {
    ModifiedStack mystack(4);
    mystack.push(13);
    mystack.push(5);
    mystack.push(26);
    mystack.pop();
    ASSERT_EQ(5, mystack.getTop());
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareEqualPositive) {
    ModifiedStack mystack1(5);
    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    bool equality = false;
    if(mystack1 == mystack2) {
        equality = true;
    }
    ASSERT_TRUE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareDifferentPositive) {
    ModifiedStack mystack1(5);
    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    mystack1.push(4);
    bool inequality = false;
    if (mystack1 != mystack2) {
        inequality = true;
    }
    ASSERT_TRUE(inequality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareEqualNegative) {
    ModifiedStack mystack1(5);
    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    mystack1.push(18);
    bool equality = false;
    if (mystack1 == mystack2) {
        equality = true;
    }
    ASSERT_FALSE(equality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testCompareDifferentNegative) {
    ModifiedStack mystack1(5);
    mystack1.push(20);
    mystack1.push(64);
    mystack1.push(12);
    mystack1.push(3);
    ModifiedStack mystack2(mystack1);
    bool inequality = false;
    if (mystack1 != mystack2) {
        inequality = true;
    }
    ASSERT_FALSE(inequality);
}

TEST(Novozhilova_Ekaterina_modified_stack_Test, testGetLast) {
    ModifiedStack mystack(5);
    mystack.push(20);
    mystack.push(64);
    mystack.push(23);
    mystack.push(34);
    ASSERT_EQ(3, mystack.getLast());
}
