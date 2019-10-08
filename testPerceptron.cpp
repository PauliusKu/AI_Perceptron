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

void printMenu();
void testRandPerceptron(std::vector<InpTestData>& inputData);
void testLearningPerceptron(std::vector<InpTestData>& inputData);
void testLearningPerceptron(std::vector<InpTestData>& inputData, double pLearnRate, unsigned long pEpochs, double pErrMargin);
void prepareTestData(std::vector<InpTestData>& inputData);
void prepareTestDataAND(std::vector<InpTestData>& inputData);
void prepareTestDataANDAND(std::vector<InpTestData>& inputData);
void addSomeRandWeights(std::vector<InpTestData>& inputData);
void fillWithRands( std::vector<Weight>& randNums);
void fillWithRands( std::vector<double>& randNums);
bool meetAllConds(std::vector<InpTestData>& inputData);
bool isSetOk(bool, bool);

void chooseTest(){
    std::vector<InpTestData> inputData {};
    std::string activationFuncName{};

    int inp;
    bool exitLoop = false;

    printMenu();
    do {

        inp = 0;
        std::cin >> inp;
        switch (inp) {
            case 0:
                printMenu();
            case 1:
                prepareTestData(inputData);
                break;
            case 2:
                prepareTestDataAND(inputData);
                break;
            case 3:
                prepareTestDataANDAND(inputData);
                break;
            default:
                exitLoop = true;
        }

        inp = 0;
        std::cin >> inp;
        switch (inp) {
            case 0:
                printMenu();
            case 1:
                testRandPerceptron(inputData);
                break;
            case 2:
                testLearningPerceptron(inputData);
                break;
            default:
                exitLoop = true;
        }
    }while (!exitLoop);
}

void testRandPerceptron(std::vector<InpTestData>& inputData){
    int itr = 0;

    while(true){
        itr++;
        addSomeRandWeights(inputData);
        if (meetAllConds(inputData))
            break;
    }

    std::cout << itr << " Result Weights: " << std::endl;
    for(auto const& value: inputData[0].inputPerc)
        std::cout << value.Weight << std::endl;
}

void testLearningPerceptron(std::vector<InpTestData>& inputData){
    testLearningPerceptron(inputData, 1, 1000, 0.01);
}

void testLearningPerceptron(std::vector<InpTestData>& inputData, double pLearnRate, unsigned long pEpochs, double pErrMargin){
    int epoch = 0;
    double rez = 0;
    double error = 0;
    double sumError = 0;

    std::vector<Weight> weights(inputData[0].inputPerc.size());
    fillWithRands(weights);

    while(epoch < pEpochs){
        epoch++;
        sumError = 0;
        for(auto const& value: inputData){
            rez = unitStep(perceptron(value.inputPerc, weights));
            error = value.condition - rez;
            sumError += std::pow(error, 2);
            for(unsigned long i = 0; i < weights.size(); i++)
                weights[i].weight = weights[i].weight + pLearnRate * error * value.inputPerc[i].input;
        }
        if (sumError < pErrMargin)
            break;
    }

    std::cout << "Epochs: " << epoch << std::endl;
    std::cout << "Sum of errors: " << sumError << std::endl;
    std::cout << "Result Weights: " << std::endl;
    for(auto const& value: weights)
        std::cout << value.weight << std::endl;
}

void prepareTestData(std::vector<InpTestData>& inputData){
    inputData.clear();
    inputData.push_back({{{1, {}}, {-0.2, {}}, {0.5, {}}},false});
    inputData.push_back({{{1, {}}, {0.2, {}}, {-0.5, {}}},false});
    inputData.push_back({{{1, {}}, {0.8, {}}, {-0.8, {}}},true});
    inputData.push_back({{{1, {}}, {0.8, {}}, {0.8, {}}},true});
}

void prepareTestDataAND(std::vector<InpTestData>& inputData){
    inputData.clear();
    inputData.push_back({{{1, {}}, {1, {}}, {1, {}}},true});
    inputData.push_back({{{1, {}}, {0, {}}, {0, {}}},false});
    inputData.push_back({{{1, {}}, {0, {}}, {1, {}}},false});
    inputData.push_back({{{1, {}}, {1, {}}, {0, {}}},false});
}

void prepareTestDataANDAND(std::vector<InpTestData>& inputData){
    inputData.clear();
    inputData.push_back({{{1, {}}, {1, {}}, {1, {}}, {1, {}}},true});
    inputData.push_back({{{1, {}}, {0, {}}, {0, {}}, {1, {}}},false});
    inputData.push_back({{{1, {}}, {0, {}}, {1, {}}, {1, {}}},false});
    inputData.push_back({{{1, {}}, {1, {}}, {0, {}}, {1, {}}},false});
    inputData.push_back({{{1, {}}, {1, {}}, {1, {}}, {0, {}}},false});
    inputData.push_back({{{1, {}}, {0, {}}, {0, {}}, {0, {}}},false});
    inputData.push_back({{{1, {}}, {0, {}}, {1, {}}, {0, {}}},false});
    inputData.push_back({{{1, {}}, {1, {}}, {0, {}}, {0, {}}},false});
}

void addSomeRandWeights(std::vector<InpTestData>& inputData){
    std::vector<double> randNums( inputData.at(0).inputPerc.size());
    fillWithRands(randNums);

    for(auto& value: inputData)
        for (unsigned long i = 0; i < value.inputPerc.size(); i++)
            value.inputPerc[i].Weight = randNums[i];
}

void fillWithRands(std::vector<Weight>& randNums){
    for(auto& value: randNums)
        value = {round(randomNum(-1.0, 1.0)*100)/100};
}

void fillWithRands(std::vector<double>& randNums){
    for(auto& value: randNums)
        value = round(randomNum(-1.0, 1.0)*100)/100;
}

bool meetAllConds(std::vector<InpTestData>& inputData) {
    int itr = 0;
    for (auto const &value: inputData){
        if (!isSetOk(unitStep(perceptron(value.inputPerc)), value.condition))
            return false;
        itr++;
    }
    return true;
}

bool isSetOk(const bool input, const bool condition) {return input == condition;}

void printMenu(){
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "Choose data:" << std::endl;
    std::cout << "1 - first test (from 1st task)" << std::endl;
    std::cout << "2 - AND function" << std::endl;
    std::cout << "3 - AND AND function" << std::endl;
    std::cout << "Choose algorithm:" << std::endl;
    std::cout << "1 - random weight generation" << std::endl;
    std::cout << "2 - learning neuron" << std::endl;
    std::cout << "----------------------------------" << std::endl;
}