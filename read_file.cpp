//
// Created by Alexander Allis on 9/2/22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "read_file.h"
#include "LinkedList.h"

using namespace std;

vector<LinkedList>* fileToList(vector<LinkedList>* malePreferencesList, std::string* fileName){

    string fileN = *fileName;

    // Check if file exists
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

    stringstream sStream;  // stream to parse each line
    string line;  // each line
    int rank;  // each number
    vector<int> currentList;  // integers read from each line

    getline(fileStream, line);  // Consume first line

    int counter = 0;
    while (!fileStream.eof()) {  // Loop through lines

        getline(fileStream, line);

        if (!fileStream.fail()) {
            sStream << line;
            while(!sStream.eof()) {  // Loop through numbers
                if(!sStream.fail()) {
                    sStream >> rank;
                    currentList.push_back(rank);
                }
            }
            malePreferencesList -> emplace_back(currentList);  // Construct linked list in last index of the vector

            // Clean up
            sStream.str(std::string());  // Clear string
            sStream.clear();  // Clear the state flags for eof()
            currentList.clear();  // Clear contents of the vector just because
        }

        counter++;
    }

    fileStream.close();

    return malePreferencesList;

};
