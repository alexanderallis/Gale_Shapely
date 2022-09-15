//
// Created by Alexander Allis on 9/5/22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include "getPairsFromFile.h"

using namespace std;

/*
 * Retrieve pairs from an output file and return a 2D vector of pairs.
 * Args:
 *  arr: A pointer to a 2D array to store the output
 *  fileName: a pointer to the path to the file to be read.
 * Return:
 *  Pointer to the 2D array of pairs.
 */

vector<vector<int>>* getPairsFromFile(vector<vector<int>>* arr, std::string *fileName) {

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

    while(!fileStream.eof()) {  // Loop through lines

        getline(fileStream, line);

        if (!fileStream.fail()) {
            sStream << line;
            while(!sStream.eof()) {  // Loop through numbers
                if(!sStream.fail()) {
                    sStream >> rank;
                    row.push_back(rank - 1);  // Subtract 1 to make everything zero-indexed
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

}

/*
 * Inverts a 2D vector. [woman][preference rank] = man ==> [woman][man] = preference rank.
 * Args:
 *  list: a 2D vector to be inverted.
 * Return:
 *  Pointer to the 2D inverted vector.
 */

vector<vector<int>>* invertList(vector<vector<int>>* list) {
    unsigned int size = list -> size();
    vector<int> tempInverse(size, 0);  // Initialize a vector of length numberOfWomen with value 0
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            tempInverse.at(list -> at(i).at(j)) = j;
        }
        list -> at(i) = tempInverse;
    }
    return list;
}