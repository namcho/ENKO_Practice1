
#include "HomoAbstract.h"
#include <stdio.h>

// C++ Style Protected functions
void Callback_mulHeightWeight(void *obj);



void runHomoActivity(HomoAbstract_t *HomoObj, void *arg){

    ActivityStatus_e status;
    if(getActivityState(HomoObj->ActivityObj) == ACTIVITY_STATE_PRE){

            status = HomoObj->ActivityObj->preActivityFunc(HomoObj->ActivityObj, arg);

            // set fonksiyonuyla yapilacak sekilde duzenlenecek
            HomoObj->ActivityObj->state = (status == ACTIVITY_STATUS_NEXT) ? ACTIVITY_STATE_ACT : ACTIVITY_STATE_PRE;
    }
    else if(getActivityState(HomoObj->ActivityObj) == ACTIVITY_STATE_ACT){

            status = HomoObj->ActivityObj->activityFunc(HomoObj->ActivityObj, arg);

            // set fonksiyonuyla yapilacak sekilde duzenlenecek
            HomoObj->ActivityObj->state = (status == ACTIVITY_STATUS_NEXT) ? ACTIVITY_STATE_POST : ACTIVITY_STATE_ACT;
    }
    else if(getActivityState(HomoObj->ActivityObj) == ACTIVITY_STATE_POST){

            status = HomoObj->ActivityObj->postActivityFunc(HomoObj->ActivityObj, arg);

            // set fonksiyonuyla yapilacak sekilde duzenlenecek
            HomoObj->ActivityObj->state = (status == ACTIVITY_STATUS_NEXT) ? ACTIVITY_STATE_END : ACTIVITY_STATE_POST;
    }
    else{

            status = HomoObj->ActivityObj->endActivityFunc(HomoObj->ActivityObj, arg);

            // set fonksiyonuyla yapilacak sekilde duzenlenecek
            HomoObj->ActivityObj->state = (status == ACTIVITY_STATUS_NEXT) ? ACTIVITY_STATE_PRE : ACTIVITY_STATE_END;
    }
}

void setHomoWeight(HomoAbstract_t *HomoObj, weight_t weight){

    HomoObj->weight = weight;

    HomoObj->callback(HomoObj);
}

weight_t getHomoWeight(HomoAbstract_t *HomoObj){

    return HomoObj->weight;
}

void setHomoHeight(HomoAbstract_t *HomoObj, height_t height){

    HomoObj->height = height;

    HomoObj->callback(HomoObj);
}

height_t getHomoHeight(HomoAbstract_t *HomoObj){

    float heigt;

    if(HomoObj->HeightUnit == HEIGHT_UNIT_METER){

        heigt = HomoObj->height / 100.0;
    }
    else if(HomoObj->HeightUnit == HEIGHT_UNIT_MMETER){

        heigt = HomoObj->height * 10.0;
    }
    else{

        heigt = HomoObj->height;
    }

    return heigt;
}

void setHomoSound(HomoAbstract_t *HomoObj, ISound soundFunc){

    HomoObj->SoundFunc = soundFunc;
}

void setHomoHeightUnit(HomoAbstract_t *HomoObj, HomoHeightUnit_e HEIGHT_UNIT_x){

    HomoObj->HeightUnit = HEIGHT_UNIT_x;
}

ISound getHomoSound(HomoAbstract_t *HomoObj){

    return HomoObj->SoundFunc;
}

HomoHeightUnit_e getHomoHeightUnit(HomoAbstract_t *HomoObj){

    return HomoObj->HeightUnit;
}

IPictureOfHomo getHomoPicture(HomoAbstract_t *HomoObj){

    return HomoObj->pictureFunc;
}

void setHomoActivity(HomoAbstract_t *HomoObj, Activity_t *ActivityObj){

    HomoObj->ActivityObj = ActivityObj;
}

// Protected implementations
void Callback_mulHeightWeight(void *obj){

    HomoAbstract_t *HomoObj = (HomoAbstract_t *)obj;
    float mul;

    mul = getHomoHeight(HomoObj) * getHomoWeight(HomoObj);

    printf("Height x Weight = %.2f\n", mul);
}
