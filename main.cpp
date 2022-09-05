#include <iostream>
#include <vector>

#include "LinkedList.h"
#include "read_file.h"
#include "StableMatchingAlgo.h"

using namespace std;

int main(int argc, char** argv) {

    for (int i = 0; i < argc; ++i)
        cout << "arg " << i << ": " << argv[i] << "\n";

    string programType = argv[1];
    string maleFileName = argv[2];
    string femaleFileName = argv[3];
    string outputFileName = argv[4];

    // Read Male Preferences File
    vector<LinkedList> malePreferences;
    vector<vector<int>> mpArr;
    if(fileToVector(&mpArr, &maleFileName) == nullptr) return 1;
    vectorToLinkedList(&malePreferences, &mpArr);

    // Read Female Preferences File
    vector<vector<int>> femalePreferenceArr;
    if(fileToVector(&femalePreferenceArr, &femaleFileName) == nullptr) return 1;
    unsigned int numberOfWomen = femalePreferenceArr.size();
    // Invert Female Preferences
    vector<int> tempInverse(numberOfWomen, 0);
    for(int i = 0; i < numberOfWomen; i++) {
        for(int j = 0; j < femalePreferenceArr[i].size(); j++) {
            tempInverse.at(femalePreferenceArr.at(i).at(j)) = j;
        }
        femalePreferenceArr[i] = tempInverse;
    }

    const unsigned int NUM_MEN = malePreferences.size();

    // People
    int men[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) men[i] = i;
    int women[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) women[i] = i;

    // Call Stable Matching Function
    vector<int> pairs;  // defined as index:value = man:woman
    pairs = stableMatchingAlgorithm(malePreferences, femalePreferenceArr, men, women);

    // Stable Matching Output
    ofstream outputFS;
    outputFS.open(outputFileName);
    if(!outputFS.is_open()) {
        cout << "Error with output file." << endl;
    }

    for(int i = 0; i < NUM_MEN; i++) {
        outputFS << i << " " << pairs.at(i) << endl;
    }

    return 0;


}
