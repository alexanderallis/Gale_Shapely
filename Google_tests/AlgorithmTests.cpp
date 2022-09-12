//
// Created by Alexander Allis on 9/11/22.
//

#include <gtest/gtest.h>
#include <random>
#include <vector>
#include "../Gale_Shapely_lib/Data_Structures/LinkedList.h"
#include "../Gale_Shapely_lib/StableMatchingAlgo.h"
#include "../Gale_Shapely_lib/CheckPairStability.h"
#include "../Gale_Shapely_lib/CheckForMatching.h"

using namespace std;

class MatchingFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {

        // Establish n = number of men = number of women
//        n = 1000;

        // Randomly generate vector of linked lists of male preferences
        LinkedList lList;
        vector<int> mPref;

        for(int i = 0; i < NUM_MEN; i++) {  // For every man...

            for(int j = 0; j < NUM_MEN; j++) { mPref.emplace_back(j); }  // ...add preferences and shuffle...
            random_device randomDevice;
            default_random_engine randEngine(randomDevice());
            shuffle(mPref.begin(), mPref.end(), randEngine);

            for(int j = 0; j < NUM_MEN; j++) { lList.addTail(mPref.at(j)); }  // ...add preferences to linked list

            malePreferences.emplace_back(mPref);  // ...and linked list to the vector
            malePreferenceVector.push_back(mPref);
            lList.clearList();
            mPref.clear();

        }

        // Randomly generate vector of vectors of female preferences
        vector<int> fPref;

        for(int i = 0; i < NUM_MEN; i++) {  // For every woman...

            for(int j = 0; j < NUM_MEN; j++) { fPref.push_back(j); }  // ...add preferences and shuffle...
            random_device randomDevice;
            default_random_engine randEngine(randomDevice());
            shuffle(fPref.begin(), fPref.end(), randEngine);

            femalePreferences.emplace_back(fPref);  // ...and add to vector
            fPref.clear();
        }

        // Make list of men
        for(int i = 0; i < NUM_MEN; i++) { men[i] = i; }

    }

    virtual void TearDown() {
    }

    vector<LinkedList> malePreferences;
    vector<vector<int>> malePreferenceVector;
    vector<vector<int>> femalePreferences;
    static const int NUM_MEN = 1000;  // Establish n = number of men = number of women
    int men[NUM_MEN];
};

TEST_F(MatchingFixture, matchingTest) {

    vector<int> pairs = stableMatchingAlgorithm(malePreferences, femalePreferences, men);

    // Convert pairs into a vector of ordered pairs
    vector<vector<int>> orderedPairs;
    vector<int> temp;
    for(auto i : pairs) {
        temp.push_back(i);
        temp.push_back(pairs.at(i));
        orderedPairs.push_back(temp);
        temp.clear();
    }

    ASSERT_TRUE(checkForMatching(orderedPairs));

}

TEST_F(MatchingFixture, stabilityTest) {

    // Call Stable Matching Function
    // defined as index:value = man:woman
    vector<int> pairs = stableMatchingAlgorithm(malePreferences, femalePreferences, men);

    // Convert pairs into a vector of ordered pairs
    vector<vector<int>> orderedPairs;
    vector<int> temp;
    for(auto i : pairs) {
        temp.push_back(i);
        temp.push_back(pairs.at(i));
        orderedPairs.push_back(temp);
        temp.clear();
    }

    // Call Check Pair Function
    vector<vector<int>> unstablePairs = checkPairStability(&malePreferenceVector, &femalePreferences, &orderedPairs);

    ASSERT_TRUE(unstablePairs.empty());

}

