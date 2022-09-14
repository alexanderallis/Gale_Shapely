//
// Created by Alexander Allis on 9/13/22.
//

#include <gtest/gtest.h>
#include <vector>
#include "../Gale_Shapely_lib/Data_Structures/LinkedList.h"
#include "../Gale_Shapely_lib/StableMatchingAlgo.h"
#include "../Gale_Shapely_lib/CheckPairStability.h"
#include "../Gale_Shapely_lib/CheckForMatching.h"

using namespace std;

class MatchingTestFixture : public ::testing::Test {

protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

};

TEST_F(MatchingTestFixture, matchingTestOne) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {2, 2},
                 {3, 3}};

    ASSERT_TRUE(checkForMatching(testPairs));

}

TEST_F(MatchingTestFixture, matchingTestPolygamyOne) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {1, 2},
                 {3, 3}};

    ASSERT_FALSE(checkForMatching(testPairs));

}

TEST_F(MatchingTestFixture, matchingTestPolygamyTwo) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {2, 2},
                 {3, 2}};

    ASSERT_FALSE(checkForMatching(testPairs));

}

TEST_F(MatchingTestFixture, matchingTestPolygamyThree) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {3, 2},
                 {3, 2}};

    ASSERT_FALSE(checkForMatching(testPairs));

}

TEST_F(MatchingTestFixture, matchingTestPolygamyFour) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {2, 2},
                 {3, 3},
                 {4, 4}};

    ASSERT_TRUE(checkForMatching(testPairs));

}

TEST_F(MatchingTestFixture, matchingTestPolygamyFive) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {2, 2},
                 {3, 3},
                 {4, 4},
                 {5, 5}};

    ASSERT_TRUE(checkForMatching(testPairs));

}

TEST_F(MatchingTestFixture, matchingTestExtraNumber) {

    vector<vector<int>> testPairs;
    testPairs = {{1, 1},
                 {4, 2},
                 {3, 2}};

    ASSERT_FALSE(checkForMatching(testPairs));

}