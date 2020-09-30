
#include "HomoHabilis.h"
#include <stdio.h>

static void pictureOfHabilis();

void initHomoHabilis(HomoHabilis_t *HabilisObj){

    HabilisObj->id = 0;
    HabilisObj->HomoBase.pictureFunc = pictureOfHabilis;
}

void setHomoHabilisID(HomoHabilis_t *HabilisObj){

}

void pictureOfHabilis(){

    printf("I'm Habilis\n");
}
