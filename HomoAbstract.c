
#include "HomoAbstract.h"

void setHomoWeight(HomoAbstract_t *HomoObj, weight_t weight){

    HomoObj->weight = weight;
}

void setHomoHeight(HomoAbstract_t *HomoObj, height_t height){

    HomoObj->height = height;
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
