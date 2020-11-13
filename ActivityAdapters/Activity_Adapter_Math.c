
#include "Activity_Adapter_Math.h"
#include "../ActivityParameters/ActivityMathArg.h"

/// Private reading interface functions
static ActivityStatus_e _PreActivityMath(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _ActivityMath(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _PostActivityMath(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _EndActivityMath(Activity_t *ActivityObj, void *obj);

void setActivityAdapterMath(Activity_t *ActivityObj){

    ActivityObj->state = ACTIVITY_STATE_PRE;

    ActivityObj->preActivityFunc = _PreActivityMath;
    ActivityObj->activityFunc = _ActivityMath;
    ActivityObj->postActivityFunc = _PostActivityMath;
    ActivityObj->endActivityFunc = _EndActivityMath;
}

ActivityStatus_e _PreActivityMath(Activity_t *ActivityObj, void *obj){

    ActivityMathArgObj *argObj = (ActivityMathArg_t *)obj;

    printf("Soruyu anlamaya calisiyorum.\n");

    if(argObj->operation == ACTIVITY_MATH_OPER_SUM){

        printf("Toplama islemi yapilacak\n");
    }
    else if(argObj->operation == ACTIVITY_MATH_OPER_SUB){

         printf("Cikarma islemi yapilacak\n");
    }

    print("x1 = %.2f, x2 = %.2f\n", argObj->x1, argObj->x2);

    return ACTIVITY_STATUS_NEXT;
}

ActivityStatus_e _ActivityMath(Activity_t *ActivityObj, void *obj){

}

ActivityStatus_e _PostActivityMath(Activity_t *ActivityObj, void *obj){

}

ActivityStatus_e _EndActivityMath(Activity_t *ActivityObj, void *obj){

}
