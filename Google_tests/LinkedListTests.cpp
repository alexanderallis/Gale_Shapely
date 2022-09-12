//
// Created by Alexander Allis on 9/11/22.
//

#include <gtest/gtest.h>
#include "LinkedListTests.h"
#include "../Gale_Shapely_lib/Data_Structures/LinkedList.h"

class LinkedListFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {
        testLL = new LinkedList();
    }

    virtual void TearDown() {
        delete testLL;
    }

    LinkedList * testLL;
};

TEST_F(LinkedListFixture, addOneElement){

testLL->add(-1);
EXPECT_EQ(testLL->pop(),-1);

testLL->add(0);
EXPECT_EQ(testLL->pop(),0);

testLL->add(1);
EXPECT_EQ(testLL->pop(),1);

}

TEST_F(LinkedListFixture, addMultipleElements){

testLL->add(1);
testLL->add(2);
EXPECT_EQ(testLL->pop(),2);
EXPECT_EQ(testLL->pop(),1);

testLL->add(-1);
testLL->add(0);
testLL->add(1);
EXPECT_EQ(testLL->pop(),1);
EXPECT_EQ(testLL->pop(),0);
EXPECT_EQ(testLL->pop(),-1);

testLL->add(-100);
testLL->add(-99);
testLL->add(0);
testLL->add(100);
testLL->add(101);
testLL->add(102);
EXPECT_EQ(testLL->pop(),102);
EXPECT_EQ(testLL->pop(),101);
EXPECT_EQ(testLL->pop(),100);
EXPECT_EQ(testLL->pop(),0);
EXPECT_EQ(testLL->pop(),-99);
EXPECT_EQ(testLL->pop(),-100);

}

TEST_F(LinkedListFixture, addTailOneElement) {

testLL->addTail(-1);
EXPECT_EQ(testLL->pop(), -1);

testLL->addTail(0);
EXPECT_EQ(testLL->pop(), 0);

testLL->addTail(1);
EXPECT_EQ(testLL->pop(), 1);

}

TEST_F(LinkedListFixture, addTailMultipleElements) {

    testLL->addTail(-1);
    testLL->addTail(0);
    testLL->addTail(1);
    EXPECT_EQ(testLL->pop(), -1);
    EXPECT_EQ(testLL->pop(), 0);
    EXPECT_EQ(testLL->pop(), 1);

    testLL->addTail(-100);
    testLL->addTail(-99);
    testLL->addTail(0);
    testLL->addTail(100);
    testLL->addTail(102);
    EXPECT_EQ(testLL->pop(), -100);
    EXPECT_EQ(testLL->pop(), -99);
    EXPECT_EQ(testLL->pop(), 0);
    EXPECT_EQ(testLL->pop(), 100);
    EXPECT_EQ(testLL->pop(), 102);

}

TEST_F(LinkedListFixture, isEmptyTest) {

    EXPECT_EQ(testLL->isEmpty(), 0);

    testLL->add(1);
    EXPECT_EQ(testLL->isEmpty(), 1);

    testLL->pop();
    EXPECT_EQ(testLL->isEmpty(), 0);

    testLL->add(1);
    testLL->pop();
    EXPECT_EQ(testLL->isEmpty(), 0);

    testLL->add(1);
    testLL->add(11);
    testLL->add(111);
    testLL->add(1111);
    testLL->pop();
    testLL->pop();
    testLL->pop();
    testLL->pop();
    EXPECT_EQ(testLL->isEmpty(), 0);

}