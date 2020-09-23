
#include "HomoAbstract.h"

void setHomoWeight(HomoAbstract_t *HomoObj, uint16_t weight){

    HomoObj->weight = weight;
}

void setHomoHeight(HomoAbstract_t *HomoObj, uint16_t height){

    HomoObj->height = height;
}

void setHomoSound(HomoAbstract_t *HomoObj, ISound soundFunc){

    HomoObj->SoundFunc = soundFunc;
}

ISound getHomoSound(HomoAbstract_t *HomoObj){

    return HomoObj->SoundFunc;
}
