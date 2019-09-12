//
// Created by Paulius on 2019-09-10.
//

#include <vector>
#include "testPerceptron.h"

void prepareTestData(std::vector<std::vector<double>> &, std::vector<bool> &);
void prepareInputData(std::vector<std::vector<double>> &);
void prepareConditions(std::vector<bool> &);
void generateSomeRandWeights(std::vector<double> &);
bool meetAllConds(std::vector<std::vector<double>>&, std::vector<double>&, std::vector<bool>&);
bool isInputValid(std::vector<std::vector<double>> &inputData, std::vector<bool> &conditions);

void testPerceptron(){
    std::vector<std::vector<double>> inputData {};
    std::vector<bool> conditions {};
    std::vector<double> weights {};

    prepareTestData(inputData, conditions);

    while(true){
        generateSomeRandWeights(weights);

        if (meetAllConds(inputData, weights, conditions))
            break;
    }
}

void prepareTestData(std::vector<std::vector<double>>& inputData, std::vector<bool>& conditions){
    prepareInputData(inputData);
    prepareConditions(conditions);
    isInputValid(inputData, conditions);
}

void prepareInputData(std::vector<std::vector<double>>& inputData){
    inputData.push_back({-0.2, 0.5});
    inputData.push_back({0.2, 0.5});
    inputData.push_back({-0.2, 0.5});
    inputData.push_back({-0.2, 0.5});
}

void prepareConditions(std::vector<bool>& conditions){
    conditions.push_back(false);
    conditions.push_back(false);
    conditions.push_back(true);
    conditions.push_back(true);
}

bool isInputValid(std::vector<std::vector<double>> &inputData, std::vector<bool> &conditions){
    if (inputData.size() == conditions.size())
        return true;
}

void generateSomeRandWeights(std::vector<double> & weights){
    weights.push_back(1);
    weights.push_back(2);
    weights.push_back(3);
    weights.push_back(4);
}

bool meetAllConds(std::vector<std::vector<double>>&, std::vector<double>&, std::vector<bool>&){
//    for(auto const& value: a){
//
//    }
}
