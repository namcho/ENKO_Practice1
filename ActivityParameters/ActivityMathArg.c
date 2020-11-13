

#include "ActivityMathArg.h"


void setActivityMathArg(ActivityMathArg_t *ActivityMathArgObj,
                        ActivityMathOperation_e operation,
                        float x1,
                        float x2,){

    ActivityMathArgObj->operation = operation;
    ActivityMathArgObj->x1 = x1;
    ActivityMathArgObj->x2 = x2;
}

float getActivityMathResult(ActivityMathArg_t *ActivityMathArgObj){

    return ActivityMathArgObj->y;
}
