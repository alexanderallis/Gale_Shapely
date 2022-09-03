//
// Created by Alexander Allis on 9/2/22.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "read_file.h"
#include "LinkedList.h"

using namespace std;

LinkedList* fileToList(std::string* fileName){

    string fileN = *fileName;

    ifstream inFile(fileN.c_str());  // Check to make sure file exists
    if (!inFile) {
        cout << "File not found." << endl;
        return nullptr;
    }

    // Open file
    ifstream fileStream(fileN);
    if (!fileStream.is_open()) {
        cout << "Can't read file." << endl;
        return nullptr;
    }

    string line;  // placeholder for each line
    stringstream sStream;  // stream to parse each line
    int rank;

    getline(fileStream, line);  // Consume first line

    int numberOfMen = stoi(line);
    auto* malePrefLists = new LinkedList[numberOfMen];  // Create list of Linked Lists
    for(int i = 0; i < numberOfMen; i++) malePrefLists[i] = LinkedList();

    // TODO: Remove this.
    cout << line << endl;  // Print to test

    int counter = 0;
    while (!fileStream.eof()) {
        malePrefLists[counter] = singlePreference;
        getline(fileStream, line);

        // TODO: Remove this.
        cout << line << endl;  // Print line to test

        if (!fileStream.fail()) {
            sStream << line;
            while(!sStream.eof()) {
                sStream >> rank;
                cout << "The rank is: " << rank << endl;
                // TODO: Add ranks to list of linked lists -back to front
                malePrefLists[counter].addTail(rank);
            }
            sStream.str(std::string());
            sStream.clear();  // Clear the state flags for eof()
        }
        counter++;
    }

    fileStream.close();

    return 0;

};
