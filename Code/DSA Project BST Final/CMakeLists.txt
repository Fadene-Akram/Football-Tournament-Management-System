cmake_minimum_required(VERSION 3.25)
project(DSA_Project_Final)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_Project_Final BinarySearchTree.h dsexceptions.h Contract.h Contract.cpp Date.h Date.cpp File.cpp File.h Game.h Game.cpp Player.h Player.cpp PlayerStatistics.h PlayerStatistics.cpp Team.h Team.cpp TeamStatistics.h TeamStatistics.cpp Tournament.cpp Tournament.h utilityFunctions.h Table.h Main.cpp)
