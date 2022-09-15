/*
 * Alexander Allis
 * 09/13/22
 *
 * Purpose: This program executes the Gale-Shapely Algorithm
 * for a pool of men and women, both of size n. It also checks
 * male, female pairs for matching, perfection, and stability.
 *
 * To Compile:
 *  Run "cmake ." in root directory
 *  Run "make"
 *  Run "Gale_Shapely [Program Type] [Male Preferences] [Female Preferences] [Output File]"
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "Gale_Shapely_lib/Data_Structures/LinkedList.h"
#include "Gale_Shapely_lib/read_file.h"
#include "Gale_Shapely_lib/StableMatchingAlgo.h"
#include "Gale_Shapely_lib/getPairsFromFile.h"
#include "Gale_Shapely_lib/CheckPairStability.h"
#include "Gale_Shapely_lib/CheckForMatching.h"

using namespace std;

void printHelp() {
    cout << endl;
    cout << "HELP:" << endl;
    cout << "Correct Format: [Name of Executable] [Program Type] [Male Preferences] [Female Preferences] [Output File]" << endl;
    cout << "Program Type: \"stable\" or \"check\"" << endl;
    cout << "Male Preferences, Female Preferences, Output File must be .txt files." << endl;
    cout << endl;
}

int main(int argc, char** argv) {

    if(argc != 5) {
        printHelp();
        return 1;
    }

    // Get arguments from console
    string programType = argv[1];
    string maleFileName = argv[2];
    string femaleFileName = argv[3];
    string fourthArg = argv[4];

    if (programType == "stable") cout << "Checking for Stability: " << argv[1] << endl;
    else if (programType == "check") cout << "Checking for Integrity of Pairs in " << argv[4] << endl;
    else {
        cout << "Choose \"stable\" or \"check\"" << endl;
        printHelp();
        return 1;
    }

    cout << "Male Preferences: " << maleFileName << endl;
    cout << "Female Preferences: " << femaleFileName << endl;

    if(programType == "stable") cout << "Output File: " << fourthArg << endl;

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
        pairs = stableMatchingAlgorithm(malePreferences, femalePreferenceArr, men);

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

        // Check for matching
        bool matching = checkForMatching(pairs);
        if(matching) cout << endl << "MATCHING PROPERTY HOLDS" << endl;
        else cout << endl << "MATCHING PROPERTY DOES NOT HOLD" << endl;

        // Check for perfection
        bool perfect = false;
        if(NUM_MEN == NUM_WOMEN) {
            perfect = true;
            cout << endl << "THE MATCHING SET S IS A PERFECT MATCHING" << endl;
        }
        else{
            cout << endl << "THE MATCHING SET S DOES NOT HOLD THE PROPERTY OF PERFECTION" << endl;
            if(NUM_MEN > NUM_WOMEN) cout << "There are too many men" << endl;
            if(NUM_WOMEN > NUM_MEN) cout << "There are too many women" << endl;
        }

        // Check pair stability if matching & perfection are true
        if(matching && perfect) {
            vector<vector<int>> unstablePairs = checkPairStability(&malePreferencesArr, &femalePreferenceArr, &pairs);
            if(!unstablePairs.empty()) {
                cout << endl << "THE MATCHING SET S IS NOT STABLE" << endl;
                cout << "Unstable Pairs:" << endl;
                for(auto & unstablePair : unstablePairs) {
                    // Add 1 to unstable pairs to offset zero-indexing
                    cout << "Man " << unstablePair.at(0) + 1 << " and Woman " << unstablePair.at(1) + 1 << " will elope." << endl;
                }
            }
            else {
                cout << endl << "NO UNSTABLE PAIRS" << endl;
            }
        }
    }
    else {
        cout << "Incorrect arguments. Choose \"stable\" or \"check\"" << endl;
    }



    return 0;

}
