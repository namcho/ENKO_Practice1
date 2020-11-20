
#include "Activity_Adapter_Reading.h"
#include <stdio.h>


/// Private reading interface functions
static ActivityStatus_e _PreActivityReading(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _ActivityReading(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _PostActivityReading(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _EndActivityReading(Activity_t *ActivityObj, void *obj);


void setActivityAdapterReading(Activity_t *ActivityObj){

    ActivityObj->state = ACTIVITY_STATE_PRE;

    ActivityObj->ticker_pre = 0;
    ActivityObj->ticker_act = 0;
    ActivityObj->ticker_post = 0;
    ActivityObj->ticker_end = 0;

    ActivityObj->preActivityFunc = _PreActivityReading;
    ActivityObj->activityFunc = _ActivityReading;
    ActivityObj->postActivityFunc = _PostActivityReading;
    ActivityObj->endActivityFunc = _EndActivityReading;

     setActivityFunctionsToArray(ActivityObj);
}


ActivityStatus_e _PreActivityReading(Activity_t *ActivityObj, void *obj){

    printf("Kitap ariyorum\n");

    setActivityState(ActivityObj, ACTIVITY_STATE_ACT);
    return ACTIVITY_STATUS_NEXT;
}

ActivityStatus_e _ActivityReading(Activity_t *ActivityObj, void *obj){

    ActivityObj->ticker_act++;

    printf("Kitabi okuyorum\n");

    if(ActivityObj->ticker_act >= 5){

        ActivityObj->ticker_act = 0;

        setActivityState(ActivityObj, ACTIVITY_STATE_POST);
        return ACTIVITY_STATUS_NEXT;
    }
    else{

        return ACTIVITY_STATUS_ONGOING;
    }
}

ActivityStatus_e _PostActivityReading(Activity_t *ActivityObj, void *obj){

    printf("Kitabi rafa kaldirdim\n");

    setActivityState(ActivityObj, ACTIVITY_STATE_END);
    return ACTIVITY_STATUS_NEXT;
}

ActivityStatus_e _EndActivityReading(Activity_t *ActivityObj, void *obj){

    return ACTIVITY_STATUS_ONGOING;
}
