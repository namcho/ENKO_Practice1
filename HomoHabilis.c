
#include "HomoHabilis.h"
#include <stdio.h>

// Protected
extern void Callback_mulHeightWeight(void *obj);

static void pictureOfHabilis();

void initHomoHabilis(HomoHabilis_t *HabilisObj){

    HabilisObj->id = 0;
    HabilisObj->HomoBase.pictureFunc = pictureOfHabilis;

    HabilisObj->HomoBase.height = 0;
    HabilisObj->HomoBase.weight = 0;

    HabilisObj->HomoBase.callback = Callback_mulHeightWeight;
}

void setHomoHabilisID(HomoHabilis_t *HabilisObj){

}

void pictureOfHabilis(){

    printf("I'm Habilis\n");
}
