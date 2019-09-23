//
// Created by Paulius on 2019-09-10.
//

#include <vector>
#include <iostream>
#include <cmath>
#include "perceptron.h"
#include "activationFunctions.h"
#include "dataStructure.h"
#include "randomNum.h"

void prepareTestData(std::vector<inpTestData>& inputData);
void addSomeRandWeights(std::vector<inpTestData>& inputData);
void fillWithRands( std::vector<double>& randNums);
bool meetAllConds(std::vector<inpTestData>& inputData);
bool isSetOk(bool, bool);

void testPerceptron(){
    std::vector<inpTestData> inputData {};

    prepareTestData(inputData);
    while(true){
        addSomeRandWeights(inputData);
        if (meetAllConds(inputData))
            break;
    }

    std::cout << "Result Weights: " << std::endl;
    for(auto const& value: inputData[0].inputPerc)
        std::cout << value.weight << std::endl;
}

void prepareTestData(std::vector<inpTestData>& inputData){
    inputData.push_back({{{1, {}}, {-0.2, {}}, {0.5, {}}},false});
    inputData.push_back({{{1, {}}, {0.2, {}}, {-0.5, {}}},false});
    inputData.push_back({{{1, {}}, {0.8, {}}, {-0.8, {}}},true});
    inputData.push_back({{{1, {}}, {0.8, {}}, {0.8, {}}},true});
}

void addSomeRandWeights(std::vector<inpTestData>& inputData){
    std::vector<double> randNums( inputData.at(0).inputPerc.size());
    fillWithRands(randNums);

    randNums[0] = -0.2;
    for(auto& value: inputData)
        for(unsigned long i = 0; i < value.inputPerc.size(); i++)
            value.inputPerc[i].weight = randNums[i];
}

void fillWithRands( std::vector<double>& randNums){
    for(auto& value: randNums)
        value = round(randomNum(-1.0, 1.0)*100)/100;
}

bool meetAllConds(std::vector<inpTestData>& inputData){
    for(auto const& value: inputData)
        if(!isSetOk(sigmoid5(perceptron(value.inputPerc)), value.condition))
            return false;
    return true;
}

bool isSetOk(const bool input, const bool condition) {return input == condition;}