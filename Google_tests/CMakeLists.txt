# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run StackTests.cpp LinkedListTests.cpp LinkedListTests.h AlgorithmTests.cpp CheckMatchingTests.cpp)

add_library(data_structures_lib
        ../Gale_Shapely_lib/Data_Structures/Stack.cpp
        ../Gale_Shapely_lib/Data_Structures/Node.cpp
        ../Gale_Shapely_lib/Data_Structures/LinkedList.cpp
        )

add_library(I_O_lib
        ../Gale_Shapely_lib/getPairsFromFile.cpp
        ../Gale_Shapely_lib/read_file.cpp
        )

add_library(GS_Algo_lib
        ../Gale_Shapely_lib/StableMatchingAlgo.cpp
        ../Gale_Shapely_lib/CheckPairStability.cpp
        ../Gale_Shapely_lib/CheckForMatching.cpp ../Gale_Shapely_lib/CheckForMatching.h)

target_link_libraries(Google_Tests_run data_structures_lib I_O_lib GS_Algo_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)

