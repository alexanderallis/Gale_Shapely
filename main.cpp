#include <iostream>
#include <vector>

#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "read_file.h"

using namespace std;

int main() {

    // Read File
    std::string fileName = "test_preferences.txt";
    vector<LinkedList> malePreferences;

    // Read file and check for errors. If error, return 1.
    if(fileToList(&malePreferences, &fileName) == nullptr) {
        return 1;
    }
    else {
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

//int main() {

//    return 0;
//}


//LinkedList l;
//
//for(int i = 1; i < 11; i++) l.add(i);