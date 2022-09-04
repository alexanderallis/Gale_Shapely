#include <iostream>
#include <vector>

#include "LinkedList.h"
#include "Stack.h"
#include "read_file.h"

using namespace std;

int main(int argc, char** argv) {

    for (int i = 0; i < argc; ++i)
        cout << "arg " << i << ": " << argv[i] << "\n";

    string maleFileName = argv[3];
    string femaleFileName = argv[4];

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
    for (int i = 0; i < NUM_MEN; i++) men[i] = i + 1;
    int women[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) women[i] = i + 1;

    // Marriages
    int wife[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) wife[i] = 0;
    int husband[NUM_MEN];
    for (int i = 0; i < NUM_MEN; i++) husband[i] = 0;

    // List of free men
    Stack freeMen;
    for (int i = 0; i < NUM_MEN; i++) freeMen.push(men[i]);

    // Algorithm


    return 0;


}
