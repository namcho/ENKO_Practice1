///     Action() arayuz fonksiyonu eklensin, yemek, film izleme kitap okuma, vs... gibi eylemler icin
/// yazilacak olan aksiyonlarida STATE-MACHINE kullanarak tasarlayalim. Ornegin yemek yerken lokmanin bitmesini beklemek bu sirada
/// TV izliyor olmak vs...
///     Once her bir aksiyon ayri bir fonksiyon olacak sekilde; ornegin ActionYemek(), ActionTV(), ActionYemekTV() gbi...
///     Bir sonraki asamada eszamanli onceden tanimlanmis aksiyonlarin kombinasyonlarini kullanimini saglaycak bir yapi. Bir kuyruk yapisiyla
/// eszamanli yapilmasi istenilen aksiyonlarin kuyruga eklenmesi ve bu aksiyonlarin sonlanana kadar devam etmesi ardindan listeden silinmesin.
/// Her bir aksiyonun farkli state-machine yapisi olabilir. Her bir aksiyon suresi farkli olabilir; film aksiyon 2 saat surecek olsun, filme baslarken
/// 15dk boyunca bir yandan yemek yeniyor, ardindan da arada bir su iciliyor olabilir... HATTA film izleme aksiyon pause yapilarak calan kapiya ya da telefona
/// bakilip telefon aksiyon bittikten sonra film resume ile devam ettiriliyor olabilir...

///     Yemek yeme tum canlilarin ortak ozelligi... Bu arayuz fonksiyonu eklenebilir...

#ifndef _HOMOABSTRACT_H_
#define _HOMOABSTRACT_H_

#include <stdint.h>

struct HomoAbstract_st;

/// Her turlu sesi kapsar, maymun, yunus, at, balina vs... bizlerin cikardigi bize gore normal anlasilabilir olanlar
/// Bu fonksiyon dogal frekansi ve genligi olan sese donusturmeye yapayan bir fonksiyon olabilirdi...

/// Bu islemi yapabilmemiz icin bir donanima ihtiyacimiz var, donanim'da surekli degisebilecegi icin, bir arayuz fonksiyonu
/// kullanmak dogru bir yaklasim olur.
typedef char *(*ISound)(char *question);

typedef void (*IPictureOfHomo)(void);

typedef void (*ICallbackHeightWeight)(struct HomoAbstract_st *HomoObj);

typedef enum{

    HEIGHT_UNIT_CM = 0,
    HEIGHT_UNIT_METER,
    HEIGHT_UNIT_MMETER,

}HomoHeightUnit_e;

typedef float height_t;
typedef float weight_t;

typedef struct HomoAbstract_st{

    weight_t weight;
    height_t height;
    ISound SoundFunc;

    HomoHeightUnit_e HeightUnit;
    // Her bir turun resmini ekrana basaak
    // arayuz fonksiyonu eklensin

    IPictureOfHomo pictureFunc;

    ICallbackHeightWeight callback;
}HomoAbstract_t;


void setHomoWeight(HomoAbstract_t *HomoObj, weight_t weight);

weight_t getHomoWeight(HomoAbstract_t *HomoObj);

void setHomoHeight(HomoAbstract_t *HomoObj, height_t height);

height_t getHomoHeight(HomoAbstract_t *HomoObj);

void setHomoSound(HomoAbstract_t *HomoObj, ISound soundFunc);

void setHomoHeightUnit(HomoAbstract_t *HomoObj, HomoHeightUnit_e HEIGHT_UNIT_x);

ISound getHomoSound(HomoAbstract_t *HomoObj);

HomoHeightUnit_e getHomoHeightUnit(HomoAbstract_t *HomoObj);

IPictureOfHomo getHomoPicture(HomoAbstract_t *HomoObj);


#endif // _HOMOABSTRACT_H_
