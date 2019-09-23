//
// Created by Paulius on 2019-09-10.
//

#include "perceptron.h"
#include <iostream>

double perceptron(const std::vector<inpPerceptronData>& inputData){
    double sum = 0;

    for(auto const& value: inputData) {
        sum = sum + value.input * value.weight;
    }
    return sum;
}

