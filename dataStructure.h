//
// Created by Paulius on 2019-09-22.
//

#ifndef AI_PERCEPTRON_DATASTRUCTURE_H
#define AI_PERCEPTRON_DATASTRUCTURE_H

struct Weight{
    double weight;
};

struct InpPerceptronData{
    double input;
    double Weight;
};

struct InpTestData{
    std::vector<InpPerceptronData> inputPerc;
    bool condition;
};

#endif //AI_PERCEPTRON_DATASTRUCTURE_H
