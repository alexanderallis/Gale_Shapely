//
// Created by Alexander Allis on 9/2/22.
//

#ifndef GALE_SHAPELY_READ_FILE_H
#define GALE_SHAPELY_READ_FILE_H

#include <string>
#include <fstream>
#include "LinkedList.h"

std::vector<LinkedList>* fileToList(std::vector<LinkedList>*, std::string* fileName);

std::vector<std::vector<int>>* fileToVector(std::vector<std::vector<int>>*, std::string* fileName);

std::vector<LinkedList>* vectorToLinkedList(std::vector<LinkedList>*, std::vector<std::vector<int>>*);

#endif //GALE_SHAPELY_READ_FILE_H
