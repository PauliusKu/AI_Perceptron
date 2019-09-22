//
// Created by Paulius on 2019-09-10.
//

#include "perceptron.h"

double perceptron(const std::vector<inpPerceptronData>& inputData){
    double sum = 0;

    for(auto const& value: inputData) {
        sum += value.input * value.weight;
    }
    return sum;
}

