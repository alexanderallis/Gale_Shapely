//
// Created by Alexander Allis on 9/12/22.
//

#include <vector>

using namespace std;

/*
 * Checks a vector of pairs for the matching property. Pairs are held in a 2D vector.
 * Args:
 *  A 2D vector of pairs (integers)
 * Return:
 *  Boolean value. If matching property holds, return true, else false.
 */

bool checkForMatching(std::vector<std::vector<int>> pairs) {

    // Find the largest number in the pairs to get a max number of individuals
    int NUM_MEN = 0;
    for(auto pair : pairs) {
        if(pair.at(0) > NUM_MEN) NUM_MEN = pair.at(0);
        if(pair.at(1) > NUM_MEN) NUM_MEN = pair.at(1);
    }

    NUM_MEN++;  // Increment because of zero-indexing

    vector<int> menCount(NUM_MEN);
    fill(menCount.begin(), menCount.end(), 0);
    vector<int> womenCount(NUM_MEN);
    fill(womenCount.begin(), womenCount.end(), 0);
    bool matching = true;
    if(NUM_MEN > 0) {
        for (auto &pair: pairs) {
            if (++menCount.at((pair.at(0))) > 1) {
                matching = false;
            }
            if (++womenCount.at((pair.at(1))) > 1) {
                matching = false;
            }
        }
    }

    return matching;

}