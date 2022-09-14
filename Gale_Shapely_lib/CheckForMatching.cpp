//
// Created by Alexander Allis on 9/12/22.
//
#include <iostream>
#include <vector>

using namespace std;

bool checkForMatching(std::vector<std::vector<int>> pairs) {

    int NUM_MEN = (int) pairs.size();

    vector<int> menCount(NUM_MEN);
    fill(menCount.begin(), menCount.end(), 0);
    vector<int> womenCount(NUM_MEN);
    fill(womenCount.begin(), womenCount.end(), 0);
    bool matching = true;
    if(NUM_MEN > 0) {
        for (auto &pair: pairs) {
            if (++menCount.at((pair.at(0)) - 1) > 1) {
                matching = false;
            }
            if (++womenCount.at((pair.at(1)) - 1) > 1) {
                matching = false;
            }
        }
    }

    return matching;

}