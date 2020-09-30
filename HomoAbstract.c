
#include "HomoAbstract.h"
#include <stdio.h>

// C++ Style Protected functions
void Callback_HomoAbstract(HomoAbstract_t *HomoObj);

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


// Protected implementations
void Callback_HomoAbstract(HomoAbstract_t *HomoObj){

    float mul;

    mul = getHomoHeight(HomoObj) * getHomoWeight(HomoObj);

    printf("Height x Weight = %.2f\n", mul);
}
