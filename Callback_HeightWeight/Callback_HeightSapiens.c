

#include "Callback_HeightSapiens.h"
#include <stdio.h>

static void Callback_HeightSquareSapiens(void *obj);


void setHomoSapiens_CallbackHeight(HomoSapiens_t *PersonObj){

    PersonObj->HomoBase.callback = Callback_HeightSquareSapiens;
}



void Callback_HeightSquareSapiens(void *obj){

    height_t height;
    HomoSapiens_t *SapiensObj = (HomoSapiens_t *)obj;

    height = getHomoSapiensHeight(SapiensObj) * getHomoSapiensHeight(SapiensObj);

    printf("%s %s Height*Height = %.2f\n", getHomoSapiensName(SapiensObj), getHomoSapiensSurname(SapiensObj), height);
}
