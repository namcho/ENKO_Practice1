
#include "Activity.h"


//void setActivity(Activity_t *ActivityObj,
//                                IPreActivity preActivityFunc,
//                                IActivity activityFunc,
//                                IPostActivity postActivityFunc,
//                                IEndActivity endActivityFunc){
//
//    ActivityObj->preActivityFunc = preActivityFunc;
//    ActivityObj->activityFunc = activityFunc;
//    ActivityObj->postActivityFunc = postActivityFunc;
//    ActivityObj->endActivityFunc = endActivityFunc;
//}

ActivityState_e getActivityState(Activity_t *ActivityObj){

    return ActivityObj->state;
}

void setActivityState(Activity_t *ActivityObj, ActivityState_e state_new){

    ActivityObj->state = state_new;
}
