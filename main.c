#include <stdio.h>
#include <stdlib.h>
#include "HomoSapiens.h"
/// Class, Object, Abstraction, Encapsulation, inheritence, polymorphism, Overloading terimlerinin C'deki muadilleri nelerdir?
///     Abstraction: Detaylari gizle yalnizca gerekli olan fonksiyonlari/metotlari kullanilabilir/gorulebilir yap...
///     Encapsulation: iliskileri seyleri bir grup altinda toplama yani STRUCT/Class
/// In Object-Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.
///     Polymorphism: A person at the same time can have different characteristic. Like a man at the same time is a father, a husband, an employee.
/// So the same person posses different behaviour in different situations. This is called polymorphism.

/// Message Passing...

/// Todo overloading olayi getHomoSound() -> getHomoSapiensSound() ornegi ile gosterilecek boylece
/// getHomoSound(&MehmetObj.HomoBase) yerine getHomoSapiensSound(&MehmetObj) ifadesi kullanilabiliyor olacak

/// Todo ISound() arayuz yapisi ile uzunca if-elseif ya da switch-case yapisi kurmadan ilgili insan turunun farkli sesleri
/// cikartabilmesini ve ya farkli dilleri konusabilmesini sagliyoruz. Benzer bir yapi HayvanBase sinifindan tureyecek
/// tum canlilar icin dusunulebilir

/// Todo ilerleyen zamanlar icin ISound() gibi Conversation() arayuz fonksiyonu eklenip NLP kullanilarak yapay zeka tabanli bir
/// bir chat-botu yada botlari yapilabilir...

/// Todo Insan nesnelerini kullanarak bir chat/konusma uygulamasi yapilabilir... Ali Mehmet'e bir sey soylesin yada sorsun, Mehmet'de
/// Ali'ye cevap versin gibi...

/// Todo Diger insan turlerininde ISound() arayuz fonksiyonu yazilacak, onlar icin 1 tane olacak sacma-sapan sesler cikartacaklar, Sapiens gibi
/// bir cok dil opsiyonlari olmayacak

/// Todo setHomoHeight() kullanmak yerine setHomoSapiensHeight() ile cakma-overloading yapabiliriz...

/// Todo C++'da bir cok Creational Pattern mevcut ancak C'de gomulu sistemlerde bu tarz yapilari kullanmamiz mantikli degil, dinamik bellekleme
/// yontemleri bizim isimize pek gelmiyor(Yinede bazi yaklasimlar bir cok bileseni olan kutuphanelerde static bellek kullanimina dikkat edilerek
/// uygulanabilir).
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
    /// Bilinen dilleri bir listede tutulup, bir sapiense birden cok dil ozelligi eklenebilir... Veri yapilari ve Algoritmalar...
    printf("MehmetObj ingilizce ogrendi!!!!\n");
    setHomoSapiensLanguage(&MehmetObj, LANGUAGE_ENG);
    printf("MehmetObj.Soru = %s, MehmetObj.Cevap = %s\n", "What's up", getHomoSound(&MehmetObj.HomoBase)("What's up"));

    return 0;
}
