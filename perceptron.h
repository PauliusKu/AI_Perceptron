//
// Created by Paulius on 2019-09-10.
//

#ifndef AI_PERCEPTRON_PERCEPTRON_H
#define AI_PERCEPTRON_PERCEPTRON_H

#include <vector>
#include "dataStructure.h"

double perceptron(const std::vector<InpPerceptronData>& input, const std::vector<Weight>& weight);
double perceptron(const std::vector<InpPerceptronData>&);

#endif //AI_PERCEPTRON_PERCEPTRON_H
