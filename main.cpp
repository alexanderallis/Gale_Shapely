#include <iostream>
#include <vector>

#include "LinkedList.h"
#include "Stack.h"
#include "read_file.h"

using namespace std;

int main() {

    // Read File
    std::string fileName = "test_preferences.txt";
    vector<LinkedList> malePreferences;
    vector<vector<int>> preferencesArr;

    if(fileToVector(&preferencesArr, &fileName) == nullptr) {
        return 1;
    }
    else {
        vectorToLinkedList(&malePreferences, &preferencesArr);

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

        // Preferences
        int femalePreferences[10];

        return 0;
    }

}
