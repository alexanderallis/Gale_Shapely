#include <iostream>
#include <fstream>
#include <vector>

#include "Gale_Shapely_lib/Data_Structures/LinkedList.h"
#include "Gale_Shapely_lib/read_file.h"
#include "Gale_Shapely_lib/StableMatchingAlgo.h"
#include "Gale_Shapely_lib/getPairsFromFile.h"
#include "Gale_Shapely_lib/CheckPairStability.h"

using namespace std;

int main(int argc, char** argv) {

    // Get arguments from console
    for (int i = 0; i < argc; ++i)
        cout << "arg " << i << ": " << argv[i] << "\n";

    string programType = argv[1];
    string maleFileName = argv[2];
    string femaleFileName = argv[3];
    string fourthArg = argv[4];

    // Read Male Preferences File
    vector<LinkedList> malePreferences;
    vector<vector<int>> malePreferencesArr;
    if(fileToVector(&malePreferencesArr, &maleFileName) == nullptr) return 1;
    vectorToLinkedList(&malePreferences, &malePreferencesArr);

    // Read Female Preferences File
    vector<vector<int>> femalePreferenceArr;
    if(fileToVector(&femalePreferenceArr, &femaleFileName) == nullptr) return 1;
    femalePreferenceArr = *invertList(&femalePreferenceArr);

    const unsigned int NUM_MEN = malePreferences.size();
    const unsigned int NUM_WOMEN = femalePreferenceArr.size();

    // People
    int men[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) men[i] = i;
    int women[NUM_WOMEN];
    for (int i = 0; i < NUM_MEN; i++) women[i] = i;

    // Run
    if(programType == "stable") {

        // Call Stable Matching Function
        vector<int> pairs;  // defined as index:value = man:woman
        pairs = stableMatchingAlgorithm(malePreferences, femalePreferenceArr, men, women);

        // Output
        ofstream outputFS;
        outputFS.open(fourthArg);  // fourthArg = output file name
        if(!outputFS.is_open()) {
            cout << "Error with output file." << endl;
        }
        for(int i = 0; i < NUM_MEN; i++) {
            outputFS << i + 1 << " " << pairs.at(i) + 1 << endl;  // Convert to non-zero-indexed numbers
        }

        outputFS.close();

    }
    else if(programType == "check") {

        std::vector<std::vector<int>> pairs;
        pairs = *getPairsFromFile(&pairs, &fourthArg);

        // Check for matching property
        vector<int> menCount(NUM_MEN);
        fill(menCount.begin(), menCount.end(), 0);
        vector<int> womenCount(NUM_MEN);
        fill(womenCount.begin(), womenCount.end(), 0);
        bool matching = true;
        if(NUM_MEN > 0) {
            for(auto & pair : pairs) {
                if(++menCount.at(pair.at(0)) > 1) {
                    matching = false;
                }
                if(++womenCount.at(pair.at(1)) > 1) {
                    matching = false;
                }
            }
            if(matching) {
                cout << "Pairs have perfect matching." << endl;
            }
            else {
                cout << "Pairs do not have perfect matching." << endl;
            }
        }
        else{
            cout << "List of pairs are empty" << endl;
        }

        // Check for perfection
        bool perfect;
        if(NUM_MEN == NUM_WOMEN) perfect = true;
        else{ cout << "The matching set S does not hold the property of perfection." << endl; }

        // Check pair stability if matching & perfection are true
        if(matching && perfect) {
            vector<vector<int>> unstablePairs = checkPairStability(&malePreferencesArr, &femalePreferenceArr, &pairs);
            cout << "Unstable Pairs:" << endl;
            for(auto & unstablePair : unstablePairs) {
                // Add 1 to unstable pairs to offset zero-indexing
                cout << unstablePair.at(0) + 1 << " and " << unstablePair.at(1) + 1 << " will elope" << endl;
            }
            if( unstablePairs.empty()) {
                cout << "No unstable pairs" << endl;
            }
        }
    }
    else {
        cout << "Incorrect arguments. Choose \"stable\" or \"check\"" << endl;
    }



    return 0;

}
