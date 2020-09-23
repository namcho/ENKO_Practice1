#include <stdint.h>


typedef char *(*ISound)(char *question);

typedef struct{

    uint16_t weight;
    uint16_t height;
    ISound SoundFunc;

}HomoAbstract_t;


void setHomoWeight(HomoAbstract_t *HomoObj, uint16_t weight);

void setHomoHeight(HomoAbstract_t *HomoObj, uint16_t height);

void setHomoSound(HomoAbstract_t *HomoObj, ISound soundFunc);

ISound getHomoSound(HomoAbstract_t *HomoObj);
