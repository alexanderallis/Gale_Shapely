cmake_minimum_required(VERSION 3.21)
project(Gale_Shapely)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gale_Shapely main.cpp LinkedList.cpp LinkedList.h Node.cpp Node.h Stack.cpp Stack.h read_file.cpp read_file.h StableMatchingAlgo.cpp StableMatchingAlgo.h getPairsFromFile.cpp getPairsFromFile.h CheckPairStability.cpp CheckPairStability.h)
