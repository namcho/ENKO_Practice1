
#include "HomoHabilis.h"
#include <stdio.h>

// Protected
extern void Callback_HomoAbstract(HomoAbstract_t *HomoObj);

static void pictureOfHabilis();

void initHomoHabilis(HomoHabilis_t *HabilisObj){

    HabilisObj->id = 0;
    HabilisObj->HomoBase.pictureFunc = pictureOfHabilis;

    HabilisObj->HomoBase.height = 0;
    HabilisObj->HomoBase.weight = 0;

    HabilisObj->HomoBase.callback = Callback_HomoAbstract;
}

void setHomoHabilisID(HomoHabilis_t *HabilisObj){

}

void pictureOfHabilis(){

    printf("I'm Habilis\n");
}
