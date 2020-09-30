#include "HomoSapiens.h"
#include <stdio.h>
#include <string.h>

// Protected functions from HomoAbstract
extern void Callback_HomoAbstract(HomoAbstract_t *HomoObj);

// Private functions
static char *LanguageNull(char *question);
static char *LanguageTurkish(char *question);
static char *LanguageEnglish(char *question);

static void pictureOfSapiens();

void initHomoSapiens(HomoSapiens_t *PersonObj){

    PersonObj->name[0] = '\0';
    PersonObj->surname[0] = '\0';

    PersonObj->HomoBase.height = 0;
    PersonObj->HomoBase.weight = 0;

    PersonObj->HomoBase.pictureFunc = pictureOfSapiens;

    PersonObj->HomoBase.callback = Callback_HomoAbstract;
}

void setHomoSapiensName(HomoSapiens_t *PersonObj, char *name){

    uint16_t name_len;
    uint16_t i;

    name_len = strlen(name);

    for(i = 0; i < name_len; i++){

        PersonObj->name[i] = name[i];
    }
}

void setHomoSapiensSurname(HomoSapiens_t *PersonObj, char *surname){

    uint16_t sname_len;
    uint16_t i;

    sname_len = strlen(surname);

    for(i = 0; i < sname_len; i++){

        PersonObj->surname[i] = surname[i];
    }
}

void setHomoSapiensLanguage(HomoSapiens_t *PersonObj, HomoSapiens_Language_e LANGUAGE_x){

    if(LANGUAGE_x == LANGUAGE_TR){

        //PersonObj->HomoBase.ISound = LanguageTurkish;
        setHomoSound(&PersonObj->HomoBase, LanguageTurkish);
    }
    else if(LANGUAGE_x == LANGUAGE_ENG){

        //PersonObj->HomoBase.SoundFunc = LanguageEnglish;
        setHomoSound(&PersonObj->HomoBase, LanguageEnglish);
    }
    else{
        //PersonObj->HomoBase.ISound = LanguageNull;
        setHomoSound(&PersonObj->HomoBase, LanguageNull);
    }
}

char *getHomoSapiensName(HomoSapiens_t *PersonObj){

    return &PersonObj->name[0];
}

char *getHomoSapiensSurname(HomoSapiens_t *PersonObj){

    return &PersonObj->surname[0];
}

// ######################
// Private function implementations
// ####################
char *LanguageTurkish(char *question){

    static char answer[20];

    if(strcmp(question, "Merhaba") == 0){

        strcpy(answer, "Selamlar");
    }
    else if(strcmp(question, "Nasilsin") == 0){

        strcpy(answer, "iyiyim");
    }
    else{

        strcpy(answer, "Anlamadim");
    }

    return answer;
}

char *LanguageEnglish(char *question){

    static char answer[20];

    if(strcmp(question, "Hello") == 0){
        strcpy(answer, "Hellllo");
    }
    else if(strcmp(question, "What's up") == 0){

        strcpy(answer, "Fine");
    }
    else{

        strcpy(answer, "Error");
    }

    return answer;
}

char *LanguageNull(char *question){

    return NULL;
}

void pictureOfSapiens(){

    printf("I'm sapiens!\n");
}
