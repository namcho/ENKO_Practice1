#include <stdio.h>
#include <stdlib.h>
#include "HomoSapiens.h"

HomoSapiens_t MehmetObj;
HomoSapiens_t JohnObj;
//typedef char *(*ISound)(char *question);
int main()
{

    setHomoSapiensName(&MehmetObj, "Mehmet");
    setHomoSapiensSurname(&MehmetObj, "Yildiz");
    setHomoSapiensLanguage(&MehmetObj, LANGUAGE_TR);
    setHomoHeight(&MehmetObj.HomoBase, 183);
    setHomoWeight(&MehmetObj.HomoBase, 95);

    setHomoSapiensName(&JohnObj, "John");
    setHomoSapiensSurname(&JohnObj, "Abc");
    setHomoSapiensLanguage(&JohnObj, LANGUAGE_ENG);
    setHomoHeight(&JohnObj.HomoBase, 176);
    setHomoWeight(&JohnObj.HomoBase, 74);

    printf("MehmetObj.Name = %s\n", getHomoSapiensName(&MehmetObj));
    printf("MehmetObj.Surname = %s\n", getHomoSapiensSurname(&MehmetObj));

    printf("JohnObj.Name = %s\n", getHomoSapiensName(&JohnObj));
    printf("JohnObj.Surname = %s\n", getHomoSapiensSurname(&JohnObj));

    // Soru cevap
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "Merhaba", getHomoSound(&MehmetObj.HomoBase)("Merhaba"));
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "Nasil Gidiyor", getHomoSound(&MehmetObj.HomoBase)("Nasil Gidiyor"));
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "What's up", getHomoSound(&MehmetObj.HomoBase)("What's up"));
    printf("\n");

    printf("JohnObj.Question = %s, JohnObj.Answer = %s\n", "Merhaba", getHomoSound(&JohnObj.HomoBase)("Merhaba"));
    printf("JohnObj.Question = %s, JohnObj.Answer = %s\n", "Hello", getHomoSound(&JohnObj.HomoBase)("Hello"));
    printf("\n");

    // Mehmet ingilizce ogrendi.
    printf("MehmetObj ingilizce ogrendi!!!!\n");
    setHomoSapiensLanguage(&MehmetObj, LANGUAGE_ENG);
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "What's up", getHomoSound(&MehmetObj.HomoBase)("What's up"));

    return 0;
}
