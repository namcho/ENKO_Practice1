#ifndef _HOMOSAPIENS_H_
#define _HOMOSAPIENS_H_

#include "HomoAbstract.h"

// Kitap okuma, TV izleme,

typedef enum{
    LANGUAGE_NONE = 0,
    LANGUAGE_TR,
    LANGUAGE_ENG,
}HomoSapiens_Language_e;

typedef struct{

    HomoAbstract_t HomoBase;

    char name[20];
    char surname[20];

}HomoSapiens_t;

void initHomoSapiens(HomoSapiens_t *PersonObj);

void setHomoSapiensName(HomoSapiens_t *PersonObj, char *name);

void setHomoSapiensSurname(HomoSapiens_t *PersonObj, char *surname);

void setHomoSapiensLanguage(HomoSapiens_t *PersonObj, HomoSapiens_Language_e LANGUAGE_x);

char *getHomoSapiensName(HomoSapiens_t *PersonObj);

char *getHomoSapiensSurname(HomoSapiens_t *PersonObj);

#endif //_HOMOSAPIENS_H_
