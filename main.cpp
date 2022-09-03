#include <iostream>

#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "read_file.h"

int main() {

    LinkedList* listOfPreferences;
    std::string fileName = "test_preferences.txt";
    std::string* filePointer = &fileName;
    listOfPreferences = fileToList(filePointer);

    return 0;
}

//int main() {
//
//    const int NUM_MEN = 10;
//
//    // People
//    int men[NUM_MEN];
//    for (int i = 0; i < NUM_MEN; i++) men[i] = i + 1;
//    int women[NUM_MEN];
//    for (int i = 0; i < NUM_MEN; i++) women[i] = i + 1;
//
//    // Marriages
//    int wife[NUM_MEN] = {0};
//    int husband[NUM_MEN] = {0};
//
//    // List of free men
//    Stack freeMen;
//    for (int i : men) freeMen.push(men[i]);
//
//    // Preferences
//    LinkedList malePreferences[10];
//    int femalePreferences[10];
//
//
//
//    return 0;
//}


//LinkedList l;
//
//for(int i = 1; i < 11; i++) l.add(i);