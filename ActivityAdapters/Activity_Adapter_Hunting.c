
#include "Activity_Adapter_Hunting.h"
#include <stdio.h>

/// Private hunting  interface functions
static ActivityStatus_e _PreActivityHunting(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _ActivityHunting(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _PostActivityHunting(Activity_t *ActivityObj, void *obj);
static ActivityStatus_e _EndActivityHunting(Activity_t *ActivityObj, void *obj);


void setActivityAdapterHunting(Activity_t *ActivityObj){

    ActivityObj->state = ACTIVITY_STATE_PRE;

    ActivityObj->ticker_pre = 0;
    ActivityObj->ticker_act = 0;
    ActivityObj->ticker_post = 0;
    ActivityObj->ticker_end = 0;

    ActivityObj->preActivityFunc = _PreActivityHunting;
    ActivityObj->activityFunc = _ActivityHunting;
    ActivityObj->postActivityFunc = _PostActivityHunting;
    ActivityObj->endActivityFunc = _EndActivityHunting;

    setActivityFunctionsToArray(ActivityObj);
}


ActivityStatus_e _PreActivityHunting(Activity_t *ActivityObj, void *obj){

    printf("Baltami ariyorum!\n");
    ActivityObj->ticker_pre++;

    if(ActivityObj->ticker_pre >= 1){

            ActivityObj->ticker_pre = 0;
            return ACTIVITY_STATUS_NEXT;
    }
    else{

            return ACTIVITY_STATUS_ONGOING;
    }


}

ActivityStatus_e _ActivityHunting(Activity_t *ActivityObj, void *obj){

    ActivityObj->ticker_act++;

    printf("Avlaniyorum, ticker = %d\n", ActivityObj->ticker_act);

    if(ActivityObj->ticker_act >= 3){

        ActivityObj->ticker_act = 0;
        return ACTIVITY_STATUS_NEXT;
    }
    else{

        return ACTIVITY_STATUS_ONGOING;
    }


}

ActivityStatus_e _PostActivityHunting(Activity_t *ActivityObj, void *obj){

    ActivityObj->ticker_post++;

    printf("Avimi yiyorum, ticker = %d\n", ActivityObj->ticker_post);

    if(ActivityObj->ticker_post >= 5){

        ActivityObj->ticker_post = 0;
        return ACTIVITY_STATUS_NEXT;
    }
    else{

        return ACTIVITY_STATUS_ONGOING;
    }

}

ActivityStatus_e _EndActivityHunting(Activity_t *ActivityObj, void *obj){

    printf("End Activity\n");
    return ACTIVITY_STATUS_ONGOING;
}
