//
// Created by Paulius on 2019-09-10.
//

#include "perceptron.h"

double perceptron(const std::vector<InpPerceptronData>& input, const std::vector<Weight>& weight){
    double sum = 0;

    if (input.size() != weight.size())
        return sum;

    for (unsigned long i = 0; i < input.size(); i++){
        sum += input[i].input * weight[i].weight;
    }
    return sum;
}

double perceptron(const std::vector<InpPerceptronData>& inputData){
    double sum = 0;

    for(auto const& value: inputData) {
        sum += value.input * value.Weight;
    }
    return sum;
}

