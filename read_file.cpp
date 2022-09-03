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

vector<vector<int>>* fileToVector(vector<vector<int>>* arr, std::string* fileName) {

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
    string line;  // each line (string)
    vector<int> row;  // each line (int)
    int rank;  // each number

    getline(fileStream, line);  // Consume first line
    int numberOfMen = stoi(line);

    while(!fileStream.eof()) {  // Loop through lines

        getline(fileStream, line);

        if (!fileStream.fail()) {
            sStream << line;
            while(!sStream.eof()) {  // Loop through numbers
                if(!sStream.fail()) {
                    sStream >> rank;
                    row.push_back(rank);
                }
            }
            arr -> push_back(row);  // Construct linked list in last index of the vector

            // Clean up
            sStream.str(std::string());  // Clear string
            sStream.clear();  // Clear the state flags for eof()
            for (int &k: row) {    // Clear contents of the vector
                row.clear();
            }
        }
    }

    fileStream.close();
    return arr;
};

vector<LinkedList>* vectorToLinkedList(vector<LinkedList>* malePreferencesList, vector<vector<int>>* arr) {

    unsigned int squareSize = arr -> size();

    for(int i = 0; i < squareSize; i++) {
        malePreferencesList -> emplace_back(arr -> at(i));
    }

    return malePreferencesList;
}
