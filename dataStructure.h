//
// Created by Paulius on 2019-09-22.
//

#ifndef AI_PERCEPTRON_DATASTRUCTURE_H
#define AI_PERCEPTRON_DATASTRUCTURE_H

struct inpPerceptronData{
    double input;
    double weight;
};

struct inpTestData{
    std::vector<inpPerceptronData> inputPerc;
    bool condition;
};

#endif //AI_PERCEPTRON_DATASTRUCTURE_H
