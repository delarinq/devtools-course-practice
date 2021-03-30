// Copyright 2021 Novozhilova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Novozhilova_Ekaterina_ComplexNumberTest,
Created_With_The_Same_Complex_Number_Are_Equal) {
    
    ComplexNumber z(2.0, -4.5);

    ComplexNumber z1(z);
    ComplexNumber z2(z);

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Novozhilova_Ekaterina_ComplexNumberTest, Equals_Origin) {

    ComplexNumber a(-2.3, 0.0);

    ComplexNumber b(a);
    ComplexNumber c(b);

    EXPECT_EQ(a.getRe(), c.getRe());
    EXPECT_EQ(a.getIm(), c.getIm());
}

TEST(Novozhilova_Ekaterina_ComplexNumberTest,
Res_Are_Not_Equal_Then_Numbers_Arent_Too) {

    ComplexNumber a(7.8, 5.0);
    ComplexNumber b(3.0, 5.0);

    // 0 is not equal, 1 is equal
    int part_equality;
    int full_equality;

    if(a.getRe() != b.getRe()) {
        part_equality = 0;
    } else {
        part_equality = 1;
    }
    if(a != b) {
        full_equality = 0;
    } else {
        full_equality = 1;
    }
    EXPECT_EQ(part_equality, full_equality);
}