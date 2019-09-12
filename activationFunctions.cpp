//
// Created by Paulius on 2019-09-10.
//

#include "activationFunctions.h"

int unitStep(double x){
    if(x < 0) return 0;
    else return 1;
}