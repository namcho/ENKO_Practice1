#ifndef _ACTIVITY_H_
#define _ACTIVITY_H_

#include <stdint.h>

struct Activity_st;

typedef enum{

    ACTIVITY_STATUS_ONGOING = 0,
    ACTIVITY_STATUS_CMPLT,
    ACTIVITY_STATUS_NEXT,
}ActivityStatus_e;

typedef enum{

    ACTIVITY_STATE_PRE = 0,
    ACTIVITY_STATE_ACT,
    ACTIVITY_STATE_POST,
    ACTIVITY_STATE_END,
}ActivityState_e;

typedef ActivityStatus_e (*IPreActivity)(struct Activity_st *ActivityObj, void *obj);
typedef ActivityStatus_e (*IActivity)(struct Activity_st *ActivityObj, void *obj);
typedef  ActivityStatus_e (*IPostActivity)(struct Activity_st *ActivityObj, void *obj);
typedef ActivityStatus_e (*IEndActivity)(struct Activity_st *ActivityObj, void *obj);

typedef struct Activity_st{

    ActivityState_e state;

    uint16_t ticker_pre;
    uint16_t ticker_act;
    uint16_t ticker_post;
    uint16_t ticker_end;

    IPreActivity preActivityFunc;
    IActivity activityFunc;
    IPostActivity postActivityFunc;
    IEndActivity endActivityFunc;

}Activity_t;


//void setActivity(Activity_t *ActivityObj,
//                                IPreActivity preActivityFunc,
//                                IActivity activityFunc,
//                                IPostActivity postActivityFunc,
//                                IEndActivity endActivityFunc);

ActivityState_e getActivityState(Activity_t *ActivityObj);

void setActivityState(Activity_t *ActivityObj, ActivityState_e state_new);

#endif // _ACTIVITY_H_
