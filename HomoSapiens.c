#include "HomoSapiens.h"
#include <stdio.h>
#include <string.h>

// Private functions
static char *LanguageNull(char *question);
static char *LanguageTurkish(char *question);
static char *LanguageEnglish(char *question);

void setHomoSapiensName(HomoSapiens_t *PersonObj, char *name){

    uint16_t name_len;
    uint16_t i;

    name_len = strlen(name);

    printf("sizeof = %d\n", name_len);
    for(i = 0; i < name_len; i++){

        PersonObj->name[i] = name[i];
        printf("%c", name [i]);
    }

    printf("\n");
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
        answer[0] = 'S';
        answer[1] = 'e';
        answer[2] = 'l';
        answer[3] = 'a';
        answer[4] = 'm';
    }
    else if(strcmp(question, "Nasilsin") == 0){
        answer[0] = 'i';
        answer[1] = 'y';
        answer[2] = 'i';
        answer[3] = 'y';
        answer[4] = 'i';
        answer[5] = 'm';
    }
    else{
        answer[0] = 'A';
        answer[1] = 'n';
        answer[2] = 'l';
        answer[3] = 'm';
        answer[4] = 'a';
        answer[5] = 'd';
        answer[6] = 'i';
        answer[7] = 'm';

    }

    return answer;
}

char *LanguageEnglish(char *question){

    static char answer[20];

    if(strcmp(question, "Hello") == 0){
        answer[0] = 'H';
        answer[1] = 'e';
        answer[2] = 'l';
        answer[3] = 'l';
        answer[4] = 'l';
        answer[5] = 'o';
    }
    else if(strcmp(question, "What's up") == 0){
        answer[0] = 'F';
        answer[1] = 'i';
        answer[2] = 'n';
        answer[3] = 'e';
        answer[4] = '\0';
    }
    else{
        answer[0] = 'E';
        answer[1] = 'r';
        answer[2] = 'r';
        answer[3] = 'o';
        answer[4] = 'r';
    }

    return answer;
}

char *LanguageNull(char *question){

    return NULL;
}
