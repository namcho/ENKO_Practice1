#include <stdint.h>


/// Her turlu sesi kapsar, maymun, yunus, at, balina vs... bizlerin cikardigi bize gore normal anlasilabilir olanlar
/// Bu fonksiyon dogal frekansi ve genligi olan sese donusturmeye yapayan bir fonksiyon olabilirdi...

/// Bu islemi yapabilmemiz icin bir donanima ihtiyacimiz var, donanim'da surekli degisebilecegi icin, bir arayuz fonksiyonu
/// kullanmak dogru bir yaklasim olur.
typedef char *(*ISound)(char *question);

///     Action() arayuz fonksiyonu eklensin, yemek, film izleme kitap okuma, vs... gibi eylemler icin
/// yazilacak olan aksiyonlarida STATE-MACHINE kullanarak tasarlayalim. Ornegin yemek yerken lokmanin bitmesini beklemek bu sirada
/// TV izliyor olmak vs...
///     Once her bir aksiyon ayri bir fonksiyon olacak sekilde; ornegin ActionYemek(), ActionTV(), ActionYemekTV() gbi...
///     Bir sonraki asamada eszamanli onceden tanimlanmis aksiyonlarin kombinasyonlarini kullanimini saglaycak bir yapi. Bir kuyruk yapisiyla
/// eszamanli yapilmasi istenilen aksiyonlarin kuyruga eklenmesi ve bu aksiyonlarin sonlanana kadar devam etmesi ardindan listeden silinmesin.
/// Her bir aksiyonun farkli state-machine yapisi olabilir. Her bir aksiyon suresi farkli olabilir; film aksiyon 2 saat surecek olsun, filme baslarken
/// 15dk boyunca bir yandan yemek yeniyor, ardindan da arada bir su iciliyor olabilir... HATTA film izleme aksiyon pause yapilarak calan kapiya ya da telefona
/// bakilip telefon aksiyon bittikten sonra film resume ile devam ettiriliyor olabilir...

typedef struct{

    uint16_t weight;
    uint16_t height;
    ISound SoundFunc;

}HomoAbstract_t;


void setHomoWeight(HomoAbstract_t *HomoObj, uint16_t weight);

void setHomoHeight(HomoAbstract_t *HomoObj, uint16_t height);

void setHomoSound(HomoAbstract_t *HomoObj, ISound soundFunc);

ISound getHomoSound(HomoAbstract_t *HomoObj);
