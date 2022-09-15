//
// Created by Alexander Allis on 9/5/22.
//

#include "StableMatchingAlgo.h"
#include "Data_Structures/Stack.h"

using namespace std;

/*
 * Returns a list of stable matching pairs based on male and female preferences.
 * Args:
 *  malePreferences: A vector of male preferences, each man's preference is stored as a singly linked list.
 *  femalePreferences: A 2D vector of female preferences [woman][man] = preference rank.
 * Return:
 *  A vector of wifes for each man's index. vector.at(man) = wife.
 */

vector<int> stableMatchingAlgorithm (std::vector<LinkedList> malePreferences, std::vector<std::vector<int>> invertedFemalePreferenceArr, int* menArr) {

    int NUM_MEN = (int) malePreferences.size();

    // Marriages
    int wife[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) wife[i] = -1;
    int husband[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) husband[i] = -1;

    // List of free men
    Stack freeMen(NUM_MEN);
    for (int i = 0; i < NUM_MEN; i++) {
        int x = menArr[i];
        freeMen.push(x);
    }

    int highestWoman;
    int freeMan = freeMen.pop();
    while(freeMan != -1) {  // If pop() returns -1 for a freeMan, the stack is empty
        highestWoman = malePreferences.at(freeMan).pop();
        if(husband[highestWoman] == -1) {  // If woman is not married, she marries freeMan, and we pop another man from stack.
            husband[highestWoman] = freeMan;
            wife[freeMan] = highestWoman;
            if(!freeMen.isEmpty())
                freeMan = freeMen.pop();
            else
                break;
        }
        else {  // If woman is married, compare freeMan to current fiancée, deal accordingly.
            int femManRank = invertedFemalePreferenceArr.at(highestWoman).at(freeMan);
            int femHusRank = invertedFemalePreferenceArr.at(highestWoman).at(husband[highestWoman]);
            if(femManRank < femHusRank) {
                int temp = husband[highestWoman];
                husband[highestWoman] = freeMan;
                wife[freeMan] = highestWoman;
                freeMan = temp;
            }
        }
    }

    vector<int> pairs;
    pairs.reserve(NUM_MEN);
    for(int i = 0; i < NUM_MEN; i++) {
        pairs.push_back(wife[i]);
    }

    return pairs;

};
