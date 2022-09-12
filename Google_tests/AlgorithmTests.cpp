//
// Created by Alexander Allis on 9/11/22.
//

#include <gtest/gtest.h>
#include <random>
#include <vector>
#include "../Gale_Shapely_lib/Data_Structures/LinkedList.h"
#include "../Gale_Shapely_lib/StableMatchingAlgo.h"

using namespace std;

class MatchingFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {

        // Establish n = number of men = number of women
        n = 4;

        // Randomly generate vector of linked lists of male preferences
        LinkedList lList;
        vector<int> mPref;

        for(int i = 0; i < n; i++) {  // For every man...

            for(int j = 0; j < n; j++) { mPref.emplace_back(j); }  // ...add preferences and shuffle...
            random_device randomDevice;
            default_random_engine randEngine(randomDevice());
            shuffle(mPref.begin(), mPref.end(), randEngine);

            for(int j = 0; j < n; j++) { lList.addTail(mPref.at(j)); }  // ...add preferences to linked list

            // TODO: Not writing Linked List successfully
            malePreferences.emplace_back(lList);  // ...and linked list to the vector
            malePreferenceVector.emplace_back(mPref);
            lList.clearList();
            mPref.clear();

        }

        // Randomly generate vector of vectors of female preferences
        vector<int> fPref;

        for(int i = 0; i < n; i++) {  // For every woman...

            for(int j = 0; j < n; j++) { fPref.push_back(j); }  // ...add preferences and shuffle...
            random_device randomDevice;
            default_random_engine randEngine(randomDevice());
            shuffle(fPref.begin(), fPref.end(), randEngine);

            femalePreferences.emplace_back(fPref);  // ...and add to vector
            fPref.clear();
        }

    }

    virtual void TearDown() {
    }

    vector<LinkedList> malePreferences;
    vector<vector<int>> malePreferenceVector;
    vector<vector<int>> femalePreferences;
    int n;
};

TEST_F(MatchingFixture, matchingPipelineTest) {

    // Create an array of men
    int men[n];
    for(int i = 0; i < n; n++) {
        men[i] = i;
    }

    // Call Stable Matching Function
    vector<int> pairs;  // defined as index:value = man:woman
    pairs = stableMatchingAlgorithm(malePreferences, femalePreferences, men);

    vector<vector<int>> orderedPairs;
    orderedPairs.reserve(pairs.size());
    for(auto i : pairs) {
        orderedPairs.emplace_back((i, pairs.at(i)));
    }

//    vector<vector<int>> unstablePairs = checkPairStability(&malePreferenceVector, &femalePreferences, &orderedPairs);

//    ASSERT_TRUE(unstablePairs.empty());

    int x = 2;

}