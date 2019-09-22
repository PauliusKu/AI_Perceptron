cmake_minimum_required(VERSION 3.14)
project(AI_Perceptron)

set(CMAKE_CXX_STANDARD 17)

add_executable(AI_Perceptron main.cpp perceptron.cpp perceptron.h testPerceptron.cpp testPerceptron.h activationFunctions.cpp activationFunctions.h randomNum.cpp randomNum.h dataStructure.h)