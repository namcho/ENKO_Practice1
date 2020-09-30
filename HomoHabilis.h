#ifndef _HOMOHABILIS_H_
#define _HOMOHABILIS_H_

#include <stdint.h>
#include "HomoAbstract.h"

typedef struct{

    HomoAbstract_t HomoBase;

    uint16_t id;

}HomoHabilis_t;


void initHomoHabilis(HomoHabilis_t *HabilisObj);

void setHomoHabilisID(HomoHabilis_t *HabilisObj);

#endif // _HOMOHABILIS_H_
