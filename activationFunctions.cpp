//
// Created by Paulius on 2019-09-10.
//

#include "activationFunctions.h"

bool unitStep(double a){
    return a >= 0;
}

double sigmoid(double a){
    return 1 / (1 + pow(M_E, -a));
}

bool sigmoid5(double a){
    return sigmoid(a) > 0.5;
}