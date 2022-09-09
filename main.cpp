#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "LinkedList.h"
#include "read_file.h"
#include "StableMatchingAlgo.h"
#include "getPairsFromFile.h"
#include "CheckPairStability.h"

using namespace std;

int main(int argc, char** argv) {  //Reconfiguring main()

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
    unsigned int numberOfWomen = femalePreferenceArr.size();
    femalePreferenceArr = *invertList(&femalePreferenceArr);

    const unsigned int NUM_MEN = malePreferences.size();

    // People
    int men[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) men[i] = i;
    int women[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) women[i] = i;
    if(programType == "stable") {
        string outputFileName = fourthArg;
        // Call Stable Matching Function
        vector<int> pairs;  // defined as index:value = man:woman
        pairs = stableMatchingAlgorithm(malePreferences, femalePreferenceArr, men, women);

        // Stable Matching Output
        ofstream outputFS;
        outputFS.open(outputFileName);
        if(!outputFS.is_open()) {
            cout << "Error with output file." << endl;
        }

        int manNum;
        int womanNum;
        for(int i = 0; i < NUM_MEN; i++) {
            manNum = i + 1;  // Convert to non-zero-indexed numbers
            womanNum = pairs.at(i) + 1;
            outputFS << manNum << " " << womanNum << endl;
        }
    }
    else if(programType == "check") {
        string pairsFileName = fourthArg;
        std::vector<std::vector<int>> pairs;
        pairs = *getPairsFromFile(&pairs, &pairsFileName);
//        int numCouples = (int) pairs.size();

        // Check for matching property
        vector<int> menCount(NUM_MEN);
        fill(menCount.begin(), menCount.end(), 0);
        vector<int> womenCount(NUM_MEN);
        fill(womenCount.begin(), womenCount.end(), 0);
        bool monogamy = true;
        if(NUM_MEN > 0) {
            for(auto & pair : pairs) {
                if(++menCount.at(pair.at(0)) > 1) {
                    monogamy = false;
                }
                if(++womenCount.at(pair.at(1)) > 1) {
                    monogamy = false;
                }
            }
            if(monogamy) {
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


        // Check pair stability if perfection holds
        if(monogamy) {
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
