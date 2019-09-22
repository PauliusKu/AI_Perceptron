//
// Created by Paulius on 2019-09-10.
//

#include <vector>
#include <iostream>
#include "perceptron.h"
#include "activationFunctions.h"
#include "dataStructure.h"
#include "randomNum.h"

void prepareTestData(std::vector<inpTestData>& inputData);
void addSomeRandWeights(std::vector<inpTestData>& inputData);
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



}

void prepareTestData(std::vector<inpTestData>& inputData){
    inputData.push_back({{{1, {}}, {-0.2, {}}, {0.5, {}}},false});
    inputData.push_back({{{1, {}}, {0.2, {}}, {-0.5, {}}},false});
    inputData.push_back({{{1, {}}, {0.8, {}}, {-0.8, {}}},true});
    inputData.push_back({{{1, {}}, {0.8, {}}, {0.8, {}}},true});
}

void addSomeRandWeights(std::vector<inpTestData>& inputData){
    for (auto& value: inputData){
        for (auto& innValue: value.inputPerc) {
            innValue.weight = randomNum(0.0, 1.0);
            std::cout << "rand" << innValue.weight << std::endl;
        }
    }

}

bool meetAllConds(std::vector<inpTestData>& inputData){
    std::cout << "startItr" << std::endl;
    for(auto const& value: inputData){
        std::cout << perceptron(value.inputPerc) << " " << value.condition << std::endl;
        if(!isSetOk(unitStep(perceptron(value.inputPerc)), value.condition))
            return false;
    }
    return true;
}

bool isSetOk(const bool input, const bool condition){
    return input == condition;
}