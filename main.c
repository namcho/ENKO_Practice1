#include <stdio.h>
#include <stdlib.h>
#include "HomoSapiens.h"

HomoSapiens_t MehmetObj;
HomoSapiens_t JohnObj;

int main()
{

    // isim set edildiginde CallbackFonksiyonu cagrilsin...
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

    /// Bir kac farkli nesnenin agirligi girildikten sonra, hatali girilmeye karsi onlem almak icin
    /// Height ve Weight nitelikleri icin basit bir limit kontrolu ekleyelim. AMF5.1 deki ornekler ile kiyaslama yapalim
    JohnObj.HomoBase.weight = 289;      // dezavantaji nedir?
    return 0;
}
