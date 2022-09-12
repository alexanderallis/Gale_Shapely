//
// Created by Alexander Allis on 9/9/22.
//

#include "StackTests.h"
#include "gtest/gtest.h"
#include "../Gale_Shapely_lib/Data_Structures/Stack.h"


class StackFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {
        testStack = new Stack();
    }

    virtual void TearDown() {
        delete testStack;
    }

    Stack * testStack;
};

TEST_F(StackFixture, pushOneElement){ // 1/1/1 -> 1/3/1

testStack->push(1);
EXPECT_EQ(testStack->pop(),1);

testStack->push(100);
EXPECT_EQ(testStack->pop(),100);

testStack->push(0);
EXPECT_EQ(testStack->pop(),0);

testStack->push(-1);
EXPECT_EQ(testStack->pop(),-1);

testStack->push(-100);
EXPECT_EQ(testStack->pop(),-100);

}

TEST_F(StackFixture, pushMultipleElements){ // 1/1/1 -> 1/3/1

    testStack->push(1);
    testStack->push(2);
    EXPECT_EQ(testStack->pop(),2);
    EXPECT_EQ(testStack->pop(),1);

    testStack->push(100);
    testStack->push(101);
    testStack->push(102);
    EXPECT_EQ(testStack->pop(),102);
    EXPECT_EQ(testStack->pop(),101);
    EXPECT_EQ(testStack->pop(),100);

    testStack->push(-1);
    testStack->push(0);
    testStack->push(1);
    testStack->push(0);
    EXPECT_EQ(testStack->pop(),0);
    EXPECT_EQ(testStack->pop(),1);
    EXPECT_EQ(testStack->pop(),0);
    EXPECT_EQ(testStack->pop(),-1);

}
