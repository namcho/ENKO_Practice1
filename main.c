#include <stdio.h>
#include <stdlib.h>
#include "HomoSapiens.h"
#include "HomoHabilis.h"

#include "Callback_HeightWeight/Callback_HeightSapiens.h"

#include "ActivityAdapters/Activity_Adapter_Hunting.h"

HomoSapiens_t MehmetObj;
HomoSapiens_t JohnObj;
HomoSapiens_t PtolemyObj;
HomoSapiens_t FaradayObj;
HomoSapiens_t LeibnizObj;

HomoHabilis_t Habilis1Obj;
Activity_t ActivityHabilisObj;

HomoHabilis_t Habilis2Obj;

int main()
{

    // isim set edildiginde CallbackFonksiyonu cagrilsin...
    initHomoSapiens(&MehmetObj);
    setHomoSapiensName(&MehmetObj, "Mehmet");
    setHomoSapiensSurname(&MehmetObj, "Yildiz");
    setHomoSapiensLanguage(&MehmetObj, LANGUAGE_TR);
    setHomoHeight(&MehmetObj.HomoBase, 183);
    setHomoHeightUnit(&MehmetObj.HomoBase, HEIGHT_UNIT_METER);
    setHomoWeight(&MehmetObj.HomoBase, 95);

    initHomoSapiens(&JohnObj);
    setHomoSapiensName(&JohnObj, "John");
    setHomoSapiensSurname(&JohnObj, "Abc");
    setHomoSapiensLanguage(&JohnObj, LANGUAGE_ENG);
    setHomoHeight(&JohnObj.HomoBase, 176);
    setHomoHeightUnit(&JohnObj.HomoBase, HEIGHT_UNIT_CM);
    setHomoWeight(&JohnObj.HomoBase, 74);

    initHomoSapiens(&PtolemyObj);
    setHomoSapiensName(&PtolemyObj, "Claudius");
    setHomoSapiensSurname(&PtolemyObj, "Ptolemy");
    setHomoSapiensLanguage(&PtolemyObj, LANGUAGE_ENG);
    setHomoSapiens_CallbackHeight(&PtolemyObj);
    setHomoHeight(&PtolemyObj.HomoBase, 167);
    setHomoHeightUnit(&PtolemyObj.HomoBase, HEIGHT_UNIT_MMETER);
    setHomoWeight(&PtolemyObj.HomoBase, 65);

    initHomoSapiens(&FaradayObj);
    setHomoSapiensName(&FaradayObj, "Micheal");
    setHomoSapiensSurname(&FaradayObj, "Faraday");
    setHomoSapiensLanguage(&FaradayObj, LANGUAGE_ENG);
    setHomoSapiens_CallbackHeight(&FaradayObj);
    setHomoHeight(&FaradayObj.HomoBase, 194);
    setHomoHeightUnit(&FaradayObj.HomoBase, HEIGHT_UNIT_MMETER);
    setHomoWeight(&FaradayObj.HomoBase, 87);

    initHomoHabilis(&Habilis1Obj);
    setHomoHeight(&Habilis1Obj.HomoBase, 130);
    setHomoHeightUnit(&Habilis1Obj.HomoBase, HEIGHT_UNIT_METER);
    setHomoWeight(&Habilis1Obj.HomoBase, 45);

    initHomoHabilis(&Habilis2Obj);
    setHomoHeight(&Habilis2Obj.HomoBase, 124);
    setHomoHeightUnit(&Habilis2Obj.HomoBase, HEIGHT_UNIT_MMETER);
    setHomoWeight(&Habilis2Obj.HomoBase, 41);

    printf("MehmetObj.Name = %s\n", getHomoSapiensName(&MehmetObj));
    printf("MehmetObj.Surname = %s\n", getHomoSapiensSurname(&MehmetObj));

    printf("JohnObj.Name = %s\n", getHomoSapiensName(&JohnObj));
    printf("JohnObj.Surname = %s\n", getHomoSapiensSurname(&JohnObj));

    // Soru cevap
    /// getHomoSound(&MehmetObj) kullanimi sonucu verilen uyarilari MISRA uzerinden degerlendirelim
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "Merhaba", getHomoSound(&MehmetObj.HomoBase)("Merhaba"));
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "Nasil Gidiyor", getHomoSound(&MehmetObj.HomoBase)("Nasil Gidiyor"));
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "What's up", getHomoSound(&MehmetObj.HomoBase)("What's up"));
    printf("\n");

    printf("JohnObj.Question = %s, JohnObj.Answer = %s\n", "Merhaba", getHomoSound(&JohnObj.HomoBase)("Merhaba"));
    printf("JohnObj.Question = %s, JohnObj.Answer = %s\n", "Hello", getHomoSound(&JohnObj.HomoBase)("Hello"));
    printf("\n");

    // Mehmet ingilizce ogrendi.
    /// Bilinen dilleri bir listede tutulup, bir sapiense birden cok dil ozelligi eklenebilir... Veri yapilari ve Algoritmalar...
    printf("MehmetObj ingilizce ogrendi!!!!\n");
    setHomoSapiensLanguage(&MehmetObj, LANGUAGE_ENG);
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "What's up", getHomoSound(&MehmetObj.HomoBase)("What's up"));

    // get fonksiyonlari ile uzunluk alaninin gosterimi
    printf("\n");
    printf("%s Height unit: %d Height = %.2f\n", getHomoSapiensName(&MehmetObj), getHomoHeightUnit(&MehmetObj.HomoBase), getHomoHeight(&MehmetObj.HomoBase));
    printf("%s Height unit: %d Height = %.2f\n", getHomoSapiensName(&JohnObj), getHomoHeightUnit(&JohnObj.HomoBase), getHomoHeight(&JohnObj.HomoBase));
    printf("%s Height unit: %d Height = %.2f\n", getHomoSapiensName(&PtolemyObj), getHomoHeightUnit(&PtolemyObj.HomoBase), getHomoHeight(&PtolemyObj.HomoBase));
    printf("%s Height unit: %d Height = %.2f\n", getHomoSapiensName(&FaradayObj), getHomoHeightUnit(&FaradayObj.HomoBase), getHomoHeight(&FaradayObj.HomoBase));

    // Picture of homos...
    printf("\n");
    getHomoPicture(&MehmetObj.HomoBase)();
    getHomoPicture(&Habilis1Obj.HomoBase)();
    getHomoPicture(&Habilis2Obj.HomoBase)();


    printf("\n");
    printf("\n");
    setActivityAdapterHunting(&ActivityHabilisObj);
    setHomoActivity(&Habilis1Obj.HomoBase, &ActivityHabilisObj);

    for(uint16_t i = 0; i < 10; i++){

        runHomoActivity(&Habilis1Obj.HomoBase, NULL);
    }

    return 0;
}
