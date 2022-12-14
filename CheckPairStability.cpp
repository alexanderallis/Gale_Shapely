//
// Created by Alexander Allis on 9/5/22.
//

#include <vector>
#include "CheckPairStability.h"

using namespace std;

/*
 * Checks a vector of vector pairs for the stability property.
 * Args:
 *  malePreferences: a 2d vector of male preferences [man][preference (most to least preferred)] = woman
 *  femaleInvertedPreferences: a 2d vector of female preferences [woman][man] = rank
 *  pairs: a 2d vector of pairs
 * Returns:
 *  A 2d vector of ordered pairs. Modified on line 51 to return only 1 pair.
 */

vector<vector<int>> checkPairStability(std::vector<std::vector<int>>* malePreferences, std::vector<std::vector<int>>* femaleInvertedPreferences, std::vector<std::vector<int>>* pairs) {

    vector<vector<int>> unstablePairs;
    int numCouples = (int) pairs -> size();

    // Create list of wives, husbands, and pairs
    int wife[numCouples];
    int husband[numCouples];
    for(auto & pair : *pairs) {
        wife[pair.at(0)] = pair.at(1);
        husband[pair.at(1)] = pair.at(0);
    }

    int man;
    int prefWoman;
    int husbandRank;
    int manRank;

    for(int i = 0; i < numCouples; i++) {
        for(int j = 0; j < numCouples; j++) {
            man = i;
            prefWoman = malePreferences -> at(i).at(j);  // A woman who the man prefers more
            if(prefWoman == wife[i]) {  // If we work our way down the preference list to the wife of i, go to next man
                j = numCouples;
                break;
            }
            husbandRank = femaleInvertedPreferences -> at(prefWoman).at(husband[prefWoman]);
            manRank = femaleInvertedPreferences -> at(prefWoman).at(i);
            if(husbandRank > manRank) {
                unstablePairs.emplace_back(vector<int>());
                unstablePairs.back().emplace_back(i);
                unstablePairs.back().emplace_back(prefWoman);
                return unstablePairs;  // Returning only one unstable pair, per the project instructions.
            }
        }
    }

    return unstablePairs;

}