#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<string>
using namespace std;//Ýlk 4 satýrda kullanacaðýmýz kütüphaneleri ekledik
static const int Max = 10;//Cýrpýlama(Hash Tablosu) için Max deðerini 10'a eþitledik

string anamenu = "Yapmak Istediginiz Uygulamayi Seciniz:\n 1-Yigin Uygulamasi\n 2-Kuyruk Uygulamasi\n 3-Tek Yonlu Bagli Liste Uygulamasi\n 4-Ikili Agac Uygulamasi\n 5-Cirpilama Uygulamasi\n 6-Programdan Cikis";//Kullanacaðýmýz Anamenüyü mainde string olarak oluþturduk

class BagliListe {// Baðlýliste sýnýfýný kurduk
public://Tanýmlayacaðýmýz þeyin public olacaðýný belirttik
    BagliListe()//Kurucu fonksiyon
    {
        pSonraki = NULL;//pSonraki deðerine NULL deðerini atadýk
    }
    int veri;//int veri tipinde 'veri' isminde bir deðiþken oluþturduk
    BagliListe* pSonraki;// pointer deðiþken oluþturduk
    void BagliListeSonaEkle(BagliListe*, BagliListe*);//Sona ekleme fonksiyonu tanýmladýk
    void BagliListeArayaEkle(BagliListe*, BagliListe*, int);//Araya ekleme fonksiyonu tanýmladýk
    void BagliListeAradanCikar(BagliListe*, int);// Aradan çýkarma fonksiyonu tanýmladýk
    void BagliListeSondanCikar(BagliListe*);// Sondan çýkarma fonksiyon tanýmladýk

};

class Stack {////Yýðýn sýnýfý oluþturduk

    int veri;//int veri tipinde 'veri' isminde bir deðiþken oluþturduk


public://Tanýmlayacaðýmýz þeylerin public olacaðýný belirttik
    Stack* pSonraki;// Yýðýn tipinde pointer deðiþkeni oluþturduk


    void StackPush(int x);//Yýðýna eleman ekleme fonksiyonu tanýmladýk
    void StackPop();//Yýðýndan eleman çýkarma fonksiyonu tanýmladýk
    void StackWriteAll();//Yýðýný yazdýrma fonksiyonu tanýmladýk
    void StackDeleteAll();//Yýðýný temizleme fonksiyonu tanýmladýk

};

Stack* start = NULL;//Yýðýn baþlangýcýna NULL deðerini atadýk
Stack* temp;// Geçici bir deðiþken oluþturduk

Stack* dugumYarat()//Yýðýndan düðüm yapma fonksiyonu yazdýk
{
    Stack* yenidugum = (Stack*)malloc(sizeof(Stack));//Yýðýn tipinde yenidüðüm deðiþkeni oluþturup yýðýn uzunluðuna ekledik
    return yenidugum;//yenidüðüm deðiþkenini return ettik(dýþarýya verdik)
}

class Kuyruk {//Kuyruk sýnýfý oluþturduk

    int veri;//int veri tipinde 'veri' isminde bir deðiþken oluþturduk


public://Tanýmlayacaðýmýz þeylerin public olacaðýný belirttik
    Kuyruk* pSonra;//Kuyruk tipinde pointer deðiþkeni oluþturduk

    void KuyrukEkle(int x);//Kuyruða eleman ekleme fonksiyonu tanýmladýk
    void KuyrukCikar();//Kuyruktan eleman çýkarma fonksiyonu tanýmladýk
    void KuyrukYazdir();//Kuyruðu yazdýrma fonksiyonu tanýmladýk
    void KuyrukTemizle();//Kuyruðu temizle fonksiyonunu tanýmladýk
};

Kuyruk* basla = NULL;// Kuyruk baþlangýcýna NULL deðerini atadýk
Kuyruk* tempr;//Kuyruktan geçici deðiþken oluþturduk

Kuyruk* dugumYap()//Kuyruktan düðüm oluþturma fonksiyonu yazdýk
{
    Kuyruk* newdugum = (Kuyruk*)malloc(sizeof(Kuyruk));//Kuyruk tipinde newdugum deðiþkeni oluþturduk ve yýðýndaki eleman sayýsýna ekle dedik.
    return newdugum;//newdugumu return ettik(dýþarýya verdik)
}
class IkiliAgac {//Ikili Aðaç sýnýfý oluþturduk
public:
    struct Agacdugum {
        int veri;//int veri tipinde 'veri' isminde bir deðiþken oluþturduk ve bu deðiþken aðaca deðer almak için kullanýlacak
        Agacdugum* Sol;//Aðacýn solu
        Agacdugum* Sag;//Aðacýn saðý
    };
    Agacdugum* kok;//Aðacýn kökünü belirtiyoruz burada
    IkiliAgac() //'IkiliAgac' isminde yapýcý metot oluþturduk
    {
        kok = NULL;//kök'e NULL deðerini veriyoruz
    }
    void AgacDugumEkle(int);//Aðaca eleman ekleme fonksiyonu tanýmladýk


    //Aðaçta dolaþmak için gerekli fonksiyonlar
    void InOrderDolas(Agacdugum* dugumPtr);//InOrder dolasmak için fonskiyon tanýmladýk
    void PreOrderDolas(Agacdugum* dugumPtr);//PreOrder dolasmak için fonksiyon tanýmladýk
    void PostOrderDolas(Agacdugum* dugumPtr);//PostOrder dolasmak için fonksiyon tanýmladýk

    //Düðümleri göstermek için gerekli fonksiyonlar
    void InOrderDugumGoster()//InOrder gösterme fonksiyonu
    {
        InOrderDolas(kok);
    }
    void PreOrderDugumGoster()//PreOrder gösterme fonksiyonu
    {
        PreOrderDolas(kok);
    }
    void PostOrderDugumGoster()//PostOrder gösterme fonksiyonu
    {
        PostOrderDolas(kok);
    }

    bool DugumAra(int sayi); //bool tipinde DugumAra metodu-->Aðacta arama yapmak için metod. Bunu sil fonksiyonu ile kullanacaðýz
    void AgacSil(int sayi);//AgacSil isimli fonksiyon silinecek deðeri ve kökü DugumSil isimli fonksiyona geçirsin 
    void AgacDugumSil(int, Agacdugum*&);//bu fonksiyonu sileceðimiz düðüme ulaþmak amacýyla kullanacaðýz
                                        //bir düðüm silindiðinde alt aðacý baðlayacaðýmýz için sadece 
                                        //bu yapýyý tutan iþaretçinin adresine iþaret ediyoruz
    void AgacTamSil(Agacdugum*&);//AgacTamSil isimli fonksiyon tanýmý ve bu fonksiyonu alt aðacý baðlamak için kullanacaðýz

    void AgaciTemizle();//AgaciTemizle isimli fonksiyon tanýmladýk Bu fonksiyon Aðacý temizleyecek
    void AgacinElemanSayisi(int eleman);//AgacinElemanSayisi isimli fonksiyon tanýmladýk Bu Agaçtaki eleman sayýsýný gösterecek bize
};
class Dugum {//Dugum sýnýfý oluþturduk 
public:
    int Anahtar; //int veri tipinde 'Anahtar' isminde bir deðiþken oluþturduk
    Dugum* pSonraki;//Dugum tipinde bir pointer'ýmýz olacak pSonraki isminde
    Dugum(int Anahtar)//Dugum oluþtururken ilk adým
    {
        this->Anahtar = Anahtar;//Oluþturduðumuz düðümün Anahtar isimli deðiþkenine Anahtar deðiþkenini atayacaðýz
        pSonraki = NULL;//pSonraki deðerine NULL deðerini atadýk
    }
};
class HashTablo {
public:
    Dugum* veri[Max];//Dugum tipinde veri isimli iþaretçi oluþturuyoruz ve bu verinin Boyutu MAX olacak
    HashTablo();//'HashTablo' isminde kurucu fonksiyon oluþturduk
    void HashEkle(int Anahtar);// HashEkle isimli fonksiyon tanýmladýk.Bu ekleme iþlemini yapacak          
    void HashiTemizle();//temizleme fonksiyonu
    void HashSil(int Anahtar);//HashSil isimli fonksiyon tanýmladýk.Bu silme iþlemini yapacak 
    void HashGoster(int Anahtar);//elemanlarý gösterme fonksiyonu
    Dugum* HashiBul(int Anahtar);//Dugum tipinde HashiBul isimli fonksiyon tanýmladýk.Bu bulmayý silme içinde kullanacak             

};
HashTablo::HashTablo() {//Tabloyu oluþturmak için yapýcý fonksiyon oluþturduk
    for (int i = 0; i < Max; i++)//0'dan baþlayan Max deðerine kadar for döngüsü oluþturduk
        veri[i] = NULL;//10 elemaný NULL yaptýk
}

int main()// main fonksiyonu giriþ
{
    BagliListe* p1 = new BagliListe();////Baðlýlisteden p1 elemaný oluþturduk
    p1->veri = 0;//en baþa 0 elemanýný atadýk
    IkiliAgac Agac;//Aðaç için tanýmlama oluþturduk
    int agacElemanSayisi = 0;//int veri tipinde 'agacElemanSayisi' isimli deðiþken oluþturduk ve baþlangýç deðerine 0'ý atadýk
    HashTablo Hash;//Hash Tablosu için tanýmlama oluþturduk
    int hashElemanSayisi = 0;//int veri tipinde 'hashElemanSayisi' isimli deðiþken oluþturduk ve baþlangýç deðerine 0'ý atadýk

    do {//Döngü giriþi

        cout << "########################################" << endl;
        cout << "#############              #############" << endl;
        cout << anamenu << endl;
        cout << "########################################" << endl;//Anamenüyü yazdýrdýk 3 satýrda
        cout << "#############              #############" << endl;//Þekiller oluþturarak biraz görsellik kattýk 
        char secim;//karakter tipinde secim isimli deðiþken oluþturduk
        cout << "secim:";
        cin >> secim;//Seçimi kullanýcýdan aldýk ve yazdýrdýk

        switch (secim)//Karar vermek için seçimimizi switch yapýsýna verdik
        {
        case '1'://1'i seçersek
            cout << "********************************" << endl;
            cout << "******** YIGIN UYGULAMASI ********" << endl;//Ekranda YIGIN UYGULAMA'sý yazacak

            do {//Döngü giriþi

                cout << "---------------------------------" << endl;
                cout << "Yigin icin islem seciniz:" << endl;
                cout << "1-Yigina Eleman Ekle" << endl;
                cout << "2-Yigindan Eleman Cikar" << endl;
                cout << "3-Yigini Temizle" << endl;
                cout << "4-Yigindaki Elemanlari Goster" << endl;
                cout << "5-Yigindaki Eleman Sayisini Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Yýðýn menüsünü yazdýrdýk

                char islem;//karakter tipinde islem deðiþkeni oluþturduk
                cout << "islem:";
                cin >> islem;//iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk

                switch (islem)//iþlemi karar yapýsýna soktuk
                {
                case'1'://1'i seçersek
                {
                    Stack a;// Yýðýn tipinde nesne oluþturduk
                    int eklenecek;//int veri tipinde 'eklenecek' isimli deðiþken oluþturduk
                    cout << "Eklenecek Elemani Giriniz:\n";
                    cin >> eklenecek;//Kullanýcýdan eklenecek elemaný aldýk ve bunu yazdýrdýk
                    a.StackPush(eklenecek);// Ekleme fonksiyonunu çaðýrdýk ve ekledik
                    cout << "---> " << eklenecek << " " << "Elemani yigina eklendi" << endl;//eklendi bilgisini ekrana yazdýrdýk
                }
                break;//Döngüden çýk

                case'2'://2'yi seçersek
                {
                    Stack a;// Yýðýn tipinde nesne

                    a.StackPop();// Veri silme fonksiyonunu çaðýrdýk
                    cout << "   Eleman yigindan silindi" << endl;// silindi bilgisi ekrana yazdýrdýk
                }

                break;//Döngüden çýk

                case'3'://3'ü seçersek
                {
                    Stack a;//Yýðýn tipinde nesne
                    a.StackDeleteAll();// Yýðýný temizle fonksiyonunu çaðýrdýk
                    cout << "---->Tum elemanlar Yigindan silinerek temizlendi<----" << endl;//Elemanlarýn Yýðýndan silindiði bilgisini yazdýrýr



                }

                break;// Döngüden çýk

                case'4'://4'ü seçersek
                {
                    Stack a;// Yýðýn tipinde nesne
                    a.StackWriteAll();// Yýðýný yazdýrma fonksiyonunu çaðýrdýk
                }

                break;// Döngüden çýk

                case'5'://5'i seçersek
                {
                    {
                        cout << "***Yigindaki Eleman Sayisi***\n";// Karþýmýza gelen menü 
                        Stack* pDegisken = start;//  Yýðýn tipinde deðiþken oluþturduk
                        int elemansayisi = 0;//Deðiþken oluþturup 0 deðerini atadýk
                        while (pDegisken != NULL)// Deðiþken 0 deðilse döngüye gir
                        {
                            pDegisken = pDegisken->pSonraki;//pDeðiþkenin pSonrakisini pDeðiþkene atadýk
                            elemansayisi++;//elemansayisini arttýrdýk
                        }
                        cout << "---------> " << elemansayisi << " <--------" << endl;// eleman sayisini yazdýrdýk

                        break;//Döngüden çýk
                    }
                }

                break;//Döngüden çýk

                case'6'://6'y seçersek

                    break;// Döngüden çýk
                }

                if (islem == '6')break;// eðer iþlem 6 ise döngüden çýk

            } while (true);//Döngüden veya programdan çýk komutu gelmedikçe döngüye gir

            cout << "********************************" << endl;
            break;// Döngüden çýk

        case '2':// 2'yi seçersek
            cout << "********************************" << endl;
            cout << "******** KUYRUK UYGULAMASI ********" << endl;//Ekranda KUYRUK UYGULAMASI yazacak

            do {// Döngü giriþi

                cout << "---------------------------------" << endl;
                cout << "Kuyruk icin islem seciniz:" << endl;
                cout << "1-Kuyruga Eleman Ekle" << endl;
                cout << "2-Kuyruktan Eleman Cikar" << endl;
                cout << "3-Kuyrugu Temizle" << endl;
                cout << "4-Kuyruktaki Elemanlari Goster" << endl;
                cout << "5-Kuyruktaki Eleman Sayisini Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;// Kuyruk menüsünü yazdýrdýk

                char islem;// karakter tipinde islem deðiþkeni oluþturduk
                cout << "islem:";
                cin >> islem;// iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk

                switch (islem)// iþlemi karar yapýsýna soktuk
                {
                case'1':// 1'i seçersek
                {
                    Kuyruk a;// Kuyruk tipinde nesne oluþur
                    int eklenecek;// int veri tipinde 'eklenecek' isimli deðiþken oluþturduk
                    cout << "Eklenecek Elemani Giriniz:";
                    cin >> eklenecek;// Kullanýcýdan eklenecek elemaný aldýk ve bunu yazdýrdýk

                    a.KuyrukEkle(eklenecek);// KuyrukEkle fonksiyonunu çaðýrdýk ve ekledik
                    cout << "---> " << eklenecek << " " << "Elemani kuyruga eklendi" << endl;//eleman eklendi bilgisini ekrana yazdýrdýk
                }
                break;// Döngüden çýk

                case'2':// 2'yi seçersek
                {
                    Kuyruk a;// Kuyruk tipinde nesne oluþur

                    a.KuyrukCikar();//KuyrukCikar fonksiyonunu çaðýrdýk
                    cout << "   Eleman kuyruktan silindi" << endl;//eleman silindi bilgisi ekrana yazdýrdýk
                }
                break;// Döngüden çýk

                case'3':// 3 ise gir.
                {
                    Kuyruk a;//Kuyruk tipinde nesne oluþur
                    a.KuyrukTemizle();//KuyruguTemizle fonksiyonunu çaðýrdýk
                    cout << "---->Tum elemanlar Kuyruktan silinerek temizlendi<----" << endl;//Ekrana Kuyruðun temizlendiði bilgisini yazdýrýr 


                }
                break;// Döngüden çýk

                case'4':// 4'ü seçersek
                {
                    Kuyruk a;// Kuyruk tipinde nesne oluþur
                    a.KuyrukYazdir();// KuyrukYazdir fonksiyonunu çaðýrdýk
                }
                break;// Döngüden çýk

                case'5':// 5'i seçersek
                {
                    {
                        cout << "***Kuyruktaki Eleman Sayisi***\n";// baþlýk
                        Kuyruk* pDegisken = basla;// Kuyruk tipinde deðiþken oluþturuyoz ve baslaya eþitliyoruz
                        int elemansayisi = 0;// Deðiþken oluþturup 0'a eþitliyoruz
                        while (pDegisken != NULL)//Deðiþken 0'a eþit deðil ise döngüye gir
                        {
                            pDegisken = pDegisken->pSonra;//pDegisken = pDeðiþkenin pSonrakisi yaptýk
                            elemansayisi++;// elemansayýsýný arttýrdýk
                        }
                        cout << "---------> " << elemansayisi << " <--------" << endl;// elemansayýsýný yazdýrdýk

                        break;// Döngüden çýk
                    }
                }
                break;// Döngüden çýk

                case'6'://6'yý seçersek

                    break;// Döngüden çýk
                }

                if (islem == '6')break;// Eðer islem=6 ise döngüden çýk

            } while (true);// Döngüden herhangibir çýkma iþlemi yapýlmadýðý müddetçe hep döngüye girecek

            cout << "********************************" << endl;
            break;

        case '3':
            cout << "********************************" << endl;
            cout << "******** TEK YONLU BAGLI LISTE ********" << endl;//Ekranda KUYRUK UYGULAMASI yazacak

            do {//Döngü giriþi

                cout << "---------------------------------" << endl;
                cout << "Bagli liste icin islem seciniz:" << endl;
                cout << "1-Listeye Eleman Ekle" << endl;
                cout << "2-Listeden Eleman Cikar" << endl;
                cout << "3-Listeyi Temizle" << endl;
                cout << "4-Listedeki Elemanlari Goster" << endl;
                cout << "5-Listedeki Eleman Sayisini Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Baðlý Liste menüsünü yazdýrdýk

                char islem;//karakter tipinde islem isimli deðiþkeni oluþturduk
                cout << "islem:";
                cin >> islem;//iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk

                switch (islem)//iþlemi karar yapýsýna soktuk
                {
                case'1':// 1'i seçersek 

                    do {//Döngü giriþi

                        cout << "///////////////////////////////" << endl;
                        cout << "Ekleme Turunu Seciniz:" << endl;
                        cout << "1-Araya Eleman Ekle" << endl;
                        cout << "2-Sona Eleman Ekle" << endl;
                        cout << "3-Liste Islemlerine Geri Don" << endl;
                        cout << "///////////////////////////////" << endl;//Ekleme türü menüsünü yazdýrýr

                        char islem;//karakter tipinde islem isimli deðiþkeni oluþturduk
                        cout << "islem:";
                        cin >> islem;//iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk 

                        switch (islem)//iþlemi karar yapýsýna soktuk
                        {
                        case'1'://1'i seçersek
                        {
                            BagliListe s;//BaðlýListeden s isminde bir nesne oluþturduk 
                            BagliListe* pYeni = new BagliListe();//BagliListeden bir deðiþken olusturduk
                            int eklenen;//int veri tipinde 'eklenen' isimli deðiþken oluþturduk
                            int index;//int veri tipinde 'index' isimli deðiþken oluþturduk
                            cout << "Lutfen Eklemek Istediginiz Elemani Giriniz:";
                            cin >> eklenen;//Kullanýcýdan eleman istedik ve göstedik 2 satýrda
                            pYeni->veri = eklenen;//pYeni'nin verisine kullanýcýdan aldýðýmýz deðeri verdik 
                            cout << "Lutfen kacinci indise eklemek istediginizi giriniz:";
                            cin >> index;//kullanýcýdan indis verisini girmesini istedik
                            s.BagliListeArayaEkle(p1, pYeni, index);;//BagliListeArayaEkle fonksiyonunu çaðýrdýk 
                            cout << index << ". indise" << " " << eklenen << " " << "elemani eklendi..." << endl;//hangi indise hangi elemanýn eklendiðini yazdýrýr

                            break;//Döngüden çýk
                        }
                        case'2'://2'yi seçersek
                        {
                            BagliListe s;//BaðlýListeden s isminde bir nesne oluþturduk 
                            BagliListe* pYeni = new BagliListe();//BagliListeden bir deðiþken olusturduk
                            int eklenen;//int veri tipinde 'eklenen' isimli deðiþken oluþturduk
                            cout << "Lutfen Eklemek Istediginiz Elemani Giriniz:";
                            cin >> eklenen;//kullanýcýdan deger aldýk ve gösterdik 2 satýrda
                            pYeni->veri = eklenen;//pYeni'nin verisine kullanýcýdan aldýðýmýz deðeri verdik 
                            s.BagliListeSonaEkle(p1, pYeni);//BagliListeSonaEkle fonksiyonunu çaðýrdýk
                            cout << eklenen << " " << "Elemani Listeye Eklendi..." << endl;//Bilgiyi yazdýrdýk

                            break;//Döngüden çýk
                        }

                        case'3'://3'ü seçersek 

                            break;//Döngüden çýk
                        }

                        if (secim == '3')break;//Seçim 3 ise döngüden çýk

                    } while (true);//Döngü hep devam edicek true. biz break return demezsek

                    break;//Döngüden çýk

                case'2'://2'yi seçersek

                    do {// Döngü giriþi

                        cout << "///////////////////////////////" << endl;
                        cout << "Cikarma Turunu Seciniz:" << endl;
                        cout << "1-Aradan Eleman Cikar" << endl;
                        cout << "2-Sondan Eleman Cikar" << endl;
                        cout << "3-Liste Islemlerine Geri Don" << endl;
                        cout << "///////////////////////////////" << endl;//Çýkarma menüsü ekrana yazdýrýlýr

                        char islem;//karakter tipinde 'islem' isimli deðiþkeni oluþturduk
                        cout << "islem:";
                        cin >> islem;// iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk

                        switch (islem)//iþlemi karar yapýsýna soktuk
                        {
                        case'1'://1'i seçersek
                        {
                            BagliListe s;// BaðlýListeden s isminde bir nesne oluþturduk

                            int cikarilan;// int veri tipinde 'eklenen' isimli deðiþken oluþturduk
                            int index;// int veri tipinde 'index' isimli deðiþken oluþturduk

                            cout << "Lutfen kacinci indisten eleman cikarmak istediginizi giriniz:";
                            cin >> index;//Kaçýncý oldugu bilgisini kullanýcýdan alýp gosterdik
                            s.BagliListeAradanCikar(p1, index);//BagliListeArayaEkle fonksiyonunu çaðýrdýk
                            cout << index << ". indisteki eleman cikarildi..." << endl;//hangi indisten hangi elemanýn çýkarýldýðýný yazdýrýr

                            break;//Döngüden çýk
                        }
                        case'2'://2'yi seçersek
                        {
                            BagliListe s;//BaðlýListeden s isminde bir nesne oluþturduk

                            s.BagliListeSondanCikar(p1);//BagliListeSondanCikar fonksiyonunu çaðýrdýk
                            cout << "Sondaki Eleman Listeden Cikarildi!!" << endl;//Sondan eleman çýkarýldýðý bilgisini yazdýrýr

                            break;//Döngüden çýk
                        }
                        case'3'://3'ü seçersek

                            break;//Döngüden çýk
                        }

                        if (secim == '3')break;//Seçim 3 ise döngüden çýk

                    } while (true);// Durma komutuna basmadýkça döngü sürekli tekrar eder

                    break;// Döngüden çýk

                case'3':// 3'ü seçersek
                {

                }
                break;// Döngüden çýk

                case'4'://4'ü seçersek
                {   BagliListe* pTemp = p1;
                if (pTemp == NULL)
                {
                    cout << "<<Liste Bos>>" << endl;


                }
                else
                {
                    int eleman = 1;//int veri tipinde eleman isimli deðiþken oluþturduk ve buna 1 deðerini atadýk
                    cout << "   ***Listedeki Elemanlar***\n" << endl;//Baþlýk yazdýrýlýr
                    BagliListe* pTemp = p1;//Geçici deðiþken oluþturduk ve p1'i atadýk
                    while (pTemp != NULL)// Deðiþken NULL deðilse döngüye girecek
                    {
                        cout << "\t" << eleman << ".Eleman" << " " << pTemp->veri << endl;// yazdýrdýk
                        pTemp = pTemp->pSonraki;//Geçicinin bir sonraki  deðiþkene geçmesini aradaki baðlantý ile saðladýk
                        eleman++;// elemaný arttýrdýk 
                    }
                    break;// Döngüden çýk

                }

                }
                case'5': //5'i seçersek
                {
                    cout << "***Listedeki Eleman Sayisi***\n";//baþlýk.
                    BagliListe* pTemp = p1;//Geçici deðiþken oluþturduk ve p1'i atadýk
                    int elemansayisi = 0;//int veri tipinde elemansayisi adýnda deðiþken oluþturduk ve 0 deðerini atadýk
                    while (pTemp != NULL)//Geçici NULL deðilse girecek
                    {
                        pTemp = pTemp->pSonraki;// Geçiciyi sonrakine geçecek þekilde gösterdik
                        elemansayisi++;//elemansayýsýný arttýrdýk
                    }
                    cout << "---------> " << elemansayisi << " <--------" << endl;//elemansayýsýný yazdýrdýk

                    break;//Döngüden çýk
                }
                case'6':// 6'yý seçersek



                    break;//Döngüden çýk
                }

                if (islem == '6')break;//Ýþlem 6 ise döngüden çýk

            } while (true);// Durma komutuna basmadýkça döngü sürekli tekrar eder

            cout << "********************************" << endl;
            break;//Döngüden çýk

        case '4'://4'ü seçersek

            cout << "***************************************" << endl;
            cout << "******** IKILI AGAC UYGULAMASI ********" << endl;//Ekranda IKILI AGAC UYGULAMA'sý yazacak

            do //Döngü giriþi 
            {
                cout << "---------------------------------" << endl;
                cout << "Ikili Agac icin islem seciniz:" << endl;
                cout << "1-Agaca Eleman Ekle" << endl;
                cout << "2-Agactan Eleman Sil" << endl;
                cout << "3-Agaci Temizle" << endl;
                cout << "4-Agactaki Eleman Sayisini Goster" << endl;
                cout << "5-Agaci InOrder Dolasarak Elemanlari Goster" << endl;
                cout << "6-Agaci PreOrder Dolasarak Elemanlari Goster" << endl;
                cout << "7-Agaci PostOrder Dolasarak Elemanlari Goster" << endl;
                cout << "8-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Ikili Agac menüsünü yazdýrdýk

                char islem;//karakter tipinde islem deðiþkeni oluþturduk
                cout << "islem:";
                cin >> islem;//iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk

                switch (islem)
                {
                case'1'://1'i seçersek
                {
                    int sayi;//int veri tipinde'sayi' isimli deðiþken oluþturduk
                    cout << "Eklenecek elemani girininiz:\n";
                    cin >> sayi;//Kullanýcýdan eklenecek elemaný aldýk ve bunu yazdýrdýk
                    Agac.AgacDugumEkle(sayi);//AgacDugumEkle fonksiyonunu çaðýrdýk ve ekledik
                    agacElemanSayisi++;//eleman sayýsýný artýrdýk
                    cout << "---> " << sayi << " " << "Elemani Agaca eklendi" << endl;//eklendi bilgisini ekrana yazdýrdýk
                    break;//Döngüden çýk


                }
                case'2'://2'yi seçersek
                {
                    int sayi;//int veri tipinde'sayi' isimli deðiþken oluþturduk
                    cout << "Silinecek elemani  giriniz:" << endl;
                    cin >> sayi;//Kullanýcýdan silinecek elemaný aldýk ve bunu yazdýrdýk
                    if (Agac.DugumAra(sayi)) {//dügüm ara fonksiyonu ile sayinin olup olmamasýný if bloðu ile sorgulayýp varsa elemaný sildik
                        Agac.AgacSil(sayi);//kullanýcýdan aldýðýmýz sayýyý AgacSil fonksiyonuna iþledik
                        cout << sayi << " Elemani Agactan silindi" << endl; //silindi bilgisi ekrana yazdýrdýk
                        agacElemanSayisi--;//eleman sayýsýný azalttýk
                    }
                    else
                        cout << sayi << " Elemani Agacta Yok " << endl;//Silinecek elemanýn Agaçta olmadýðý bilgisi ekrana yazdýrýlýr
                    break;//Döngüden çýk   
                }
                case'3'://3'ü seçersek
                {
                    Agac.AgaciTemizle();//Aðacý temizleme fonksiyonunu çaðýrdýk
                    agacElemanSayisi = 0;//eleman sayýmýzý 0 a eþitledik
                    cout << "---->Tum elemanlar Agactan silinerek temizlendi<----" << endl;//Elemanlarýn Aðaçtan silindiði bilgisini yazdýrýr
                }

                case'4'://4'ü seçersek
                {
                    cout << "Eleman sayisi:" << agacElemanSayisi << endl;//Eleman sayýsýný ekrana yazdýrdýk
                    break;//Döngüden çýk
                }

                case'5'://5'i seçersek
                {
                    cout << "InOrder Dolasim:" << endl;
                    Agac.InOrderDugumGoster();//InOrderDugumGoster fonksiyonunu çaðýrdýk ve gösterdik
                    break;//Döngüden çýk

                }

                case'6'://6'yý seçersek
                {
                    cout << "PreOrder Dolasim:" << endl;
                    Agac.PreOrderDugumGoster();//PreOrderDugumGoster fonksiyonunu çaðýrdýk ve gösterdik 
                    break;//Döngüden çýk
                }

                case'7'://7'yi seçersek
                {
                    cout << "PostOrder Dolasim:" << endl;
                    Agac.PostOrderDugumGoster();//PostOrderDugumGoster fonksiyonunu çaðýrdýk ve gösterdik 
                    break;//Döngüden çýk
                }

                case'8'://8'i seçersek

                    break;//Döngüden çýk
                }
                if (islem == '8')break;//eðer iþlem 8 ise döngüden çýk 

            } while (true); //Döngüden veya programdan çýk komutu gelmedikçe döngüye gir

            cout << "********************************" << endl;
            break;//Döngüden çýk


        case '5'://5'i seçersek
            cout << "**************************************" << endl;
            cout << "******** CIRPILAMA UYGULAMASI ********" << endl;//Ekranda CIRPILAMA UYGULAMASI'sý yazacak

            do //Döngü giriþi 
            {
                cout << "---------------------------------" << endl;
                cout << "Cirpilama (Hash Tablosu) icin islem seciniz:" << endl;
                cout << "1-Tabloya Eleman Ekle" << endl;
                cout << "2-Tablodan Eleman Sil" << endl;
                cout << "3-Tabloyu Temizle" << endl;
                cout << "4-Tablodaki Eleman Sayisini Goster" << endl;
                cout << "5-Tablodaki Elemanlari Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Cirpilama (Hash Tablosu) menüsünü yazdýrdýk

                char islem;//karakter tipinde islem deðiþkeni oluþturduk
                cout << "islem:";
                cin >> islem;//iþlem deðiþkenini kullanýcýdan aldýk ve yazdýrdýk

                switch (islem)
                {
                case'1'://1'i seçersek
                {
                    int sayi;//int veri tipinde'sayi' isimli deðiþken oluþturduk
                    cout << "Eklenecek elemani girininiz:\n";
                    cin >> sayi;//Kullanýcýdan eklenecek elemaný aldýk ve bunu yazdýrdýk
                    Hash.HashEkle(sayi);//HashEkle fonksiyonunu çaðýrdýk ve ekledik
                    hashElemanSayisi++;//eleman sayýsýný arttýrdýk
                    cout << "---> " << sayi << " " << "Elemani Tabloya eklendi" << endl;//eklendi bilgisini ekrana yazdýrdýk
                    break; //Döngüden çýk
                }

                case'2'://2'yi seçersek
                {
                    int sayi;//int veri tipinde'sayi' isimli deðiþken oluþturduk
                    cout << "Silinecek elemani giriniz:" << endl;
                    cin >> sayi;//Kullanýcýdan silinecek elemaný aldýk ve bunu yazdýrdýk
                    if (Hash.HashiBul(sayi)) {//HashiBul bulma fonksiyonu ile kullanýcýnýn sileceði sayý var mý diye if bloðu ile konrtol ettirdik
                        Hash.HashSil(sayi);//HashSil silme fonksiyonunu çaðýrdýk
                        cout << sayi << " Elemani Tablodan silindi" << endl; //silindi bilgisi ekrana yazdýrdýk
                        hashElemanSayisi--;//elemman sayýsýný azalttýk
                    }
                    else
                        cout << sayi << " Elemani Tabloda Yok " << endl;//Silinecek elemanýn Tabloda olmadýðý bilgisi ekrana yazdýrýlýr


                    break;//Döngüden çýk


                }

                case'3'://3'ü seçersek
                {
                    Hash.HashiTemizle();//Tabloyu temizleme fonksiyonunu çaðýrdýk
                    hashElemanSayisi = 0;//hash tablomuzun eleman sayýsýný'0 a eþitledik
                    cout << "---->Tum elemanlar Tablodan silinerek temizlendi<----" << endl;//Elemanlarýn Tablodan silindiði bilgisini yazdýrýr
                    break;//Döngüden çýk
                }

                case'4'://4'ü seçersek
                {
                    cout << "Eleman sayisi:" << hashElemanSayisi << endl;//Eleman sayýsýný ekrana yazdýrdýk                
                    break;//Döngüden çýk                                  
                }

                case'5'://5'i seçersek
                {
                    int sayi = 0;
                    for (int sayi = 0; sayi < 10; sayi++) {//0'dan baþlayýp 10'a kadar giden for döngüsü baþlattýk. sayi deðeri sýrayla aþaðýdakini yapacak
                        Hash.HashGoster(sayi);//HashGoster elemanlarý gösterme fonksiyonun çaðýrdýk ve her z deðerinde ilgili fonksiyon iþlemi yapar
                    }
                    break;//Döngüden çýk
                }

                case'6'://6'yý seçersek

                    break;//Döngüden çýk
                }
                if (islem == '6')break;//eðer iþlem 6 ise döngüden çýk

            } while (true);//Döngüden veya programdan çýk komutu gelmedikçe döngüye gir

            cout << "********************************" << endl;
            break;//Döngüden çýk


        case '6'://6'yý seçersek

            cout << "********************************" << endl;
            cout << "<<<<--PROGRAMDAN CIKILIYOR-->>>>" << endl;
            cout << "********************************" << endl;//Programdan çýkýlýyor bilgisini ekrana yazdýrdýk
            return 0;//Programdan çýkma komutu



        }

    } while (true);// Durma komutuna basmadýkça döngü sürekli tekrar eder
}// main sonu

void BagliListe::BagliListeSonaEkle(BagliListe* pBas, BagliListe* pYeni)//BagliListenin sona ekleme fonksiyonu
{
    while (pBas->pSonraki != NULL)//pBas'ýn pSonraki deðeri NULL deðilse döngüye gir 
    {
        pBas = pBas->pSonraki;//pBas'ýn pSonraki deðerini pBasa verdik 
    }

    pBas->pSonraki = pYeni;//Kullanýcýdan aldýðýmýz pYeni'yi pBas'ýn pSonrakisine verdik Döngüden dolayý en sona gelecek
}
void BagliListe::BagliListeArayaEkle(BagliListe* pBas, BagliListe* pYeni, int index)//BaðlýListe ArayaEkleme fonksiyonu taným ve giriþi
{
    for (int i = 0; i < index - 2; i++)//Kullanýcýdan aldýðýmýz indisi kullanarak for döngüsü baþlattýk
        pBas = pBas->pSonraki;// Þart saðlanana kadar pBas'a pBas'ýn pSonraki deðerine gittik

    pYeni->pSonraki = pBas->pSonraki;//Kullanýcýdan aldýðýmýz pYeni'nin pSonrakisi'ne pBas'ýn pSonrakisini verdik
    pBas->pSonraki = pYeni;//pyeniyi pbasýn psonrakisine vererek baðlantýyý kuruyoruz.
}
void BagliListe::BagliListeAradanCikar(BagliListe* pBas, int index)// BaðlýListe AradanÇýkar fonksiyonu taným ve giriþi
{
    for (int i = 0; i < index - 2; i++)//Kullanýcýdan aldýðýmýz indisi kullanarak for döngüsü baþlattýk
        pBas = pBas->pSonraki;//pBas'ýn pSonrakisi yeni pBas olacak ve þart saðlanan kadar devam eder

    pBas->pSonraki = pBas->pSonraki->pSonraki;//pBas'ýn pSonrakisi yerine  pBasýn 2 tane pSonrakisi gelerek arada bir eleman es geçilir

}

void BagliListe::BagliListeSondanCikar(BagliListe* pBas)//BaðlýListe SondanCýkar fonksiyonu taným ve giriþi
{
    while (pBas->pSonraki->pSonraki != NULL)//pBas'ýn 2 pSonrakisi NULL deðilse döngüye gir. Son elemaný gözardý edelim
        pBas = pBas->pSonraki;//pBas'a pBasýn pSonraki deðerini vererek döndür

    pBas->pSonraki = NULL;// pBas'ýn pSonrakisini NULL yap.Elemaný göz ardý etmek için

}
void Stack::StackPush(int x) {//Yýðýn ekleme fonksiyonu giriþi

    Stack* element = dugumYarat();//Yýðýn tipinde element isminde düðüm yaratýlýr
    element->veri = x;//element'in verisine kullanýcýdan aldýðýmýz deðeri vereceðiz

    temp = start;//Geçiciye baþlangýç olan NULL atýyacaðýz

    element->pSonraki = temp;//elementin pSonraki deðerine geçiciyi atayarak yeni eleman oluþturmuþ olacaðýz

    start = element;//baþlangýca elementi vereceðiz

}
void Stack::StackPop() {//Yýðýndan çýkarma fonksiyonu giriþi

    if (start != NULL)// Baþlangýç NULL deðil ise gir
    {
        if (start->pSonraki != NULL)//Baslangýçýn pSonrakisi NULL deðil ise gir
        {
            Stack* temp2 = start;//Yýðýn tipinde yeni geçici oluþtur
            start = start->pSonraki;//Baþlangýça baþlangýçýn pSonrakisi'ni ata 
            free(temp2);//geçicinin yerine null çýkardýk
        }
        else
        {//Üstteki if bloðu saðlanmazsa eðer
            free(start);//Belleðe start atanýr.
            start = NULL;//Baþlangýça NULL verilerek eleman silinir
        }

    }
    else// BaþlangIÇ NULL deðilse girer
    {
        cout << "<<<<Silinecek Eleman Yok !!>>>>" << endl;//Eleman yok bilgisi verilir
    }

}
void Stack::StackWriteAll() {//Yýðýný yazdýrma fonksiyonu giriþi

    if (start == NULL)//Baþlangiç null ise gir
    {
        cout << "<<Yigin Bos>>" << endl;//Liste boþ yazýlýr
    }
    else//if bloðu þartý saðlamazsa  
    {
        temp = start;// Geçiciye baþlangýcý verdi
        cout << "   ***Yigindaki Elemanlar***\n" << endl;//Baþlýk
        while (temp->pSonraki != NULL)//Geçicinin sonrakisi NULL deðil ise gir
        {
            cout << "\t\t" << (temp->veri) << endl;//Geçicinin verisini yazdýrýlýr
            temp = temp->pSonraki;//Geçiciye geçicinin sonrakisini vererek döndür
        }
        cout << "\t\t" << (temp->veri) << endl;//geçicinin verisini yazdýrýr
    }

}
void Stack::StackDeleteAll() {//Yýðýný temizle fonksiyonu giriþi
    start = 0; //Baþlangýca 0 deðeri atanýr
}
void Kuyruk::KuyrukEkle(int x) {//Kuyruða ekleme fonksiyonu giriþi

    Kuyruk* element = dugumYap();//Kuyruk tipinde element isminde düðüm oluþturulur

    element->veri = x;//elementin verisine kullanýcýdan alýnan deðeri verir
    element->pSonra = NULL;//elementin sonrakisine NULL deðerini ata

    if (basla == NULL)//Baþlangýc NULL ise gir
    {
        basla = element;//Baþlangýca elementten alýnan deðerleri verir
    }
    else//if bloðu þartý saðlamazsa
    {

        tempr = basla;//Geçiciye baþlangýcý verir
        while (tempr->pSonra != NULL)//Geçicicinin sonrakisi NULL deðil ise gir
        {
            tempr = tempr->pSonra;//Geçiciye geçiciden sonrakini ver
        }

        tempr->pSonra = element;//Elementteki bilgileri geçicinin sonrakisine ver ve numa eklenmiþ olur
    }


}
void Kuyruk::KuyrukCikar() {//Kuyruktan eleman çýkarma fonksiyonu giriþi

    if (basla != NULL)// Baslangýç NULL deðil ise gir
    {
        if (basla->pSonra != NULL)//Baþlangýcýn sonrakisi NULL deðil ise gir
        {
            Kuyruk* tempr2 = basla;//Kuyruk tipinde yeni geçici oluþturup baþlangýcý ata
            basla = basla->pSonra;//Baþlangýca baþlangýcýn sonrakisini ver
            free(tempr2);//Baþlangýç deðerini ayýr
        }
        else//if bloðu þartý saðlamazsa
        {
            free(basla);//Baþlangýç deðerini ayýr
            basla = NULL;//Baþlangýca NULL ver
        }
    }
    else//Baþlangýç NULL degil saðlanmaz ise gir
    {
        cout << "<<<<Silinecek Eleman Yok !!>>>>" << endl;//Silinecek eleman yok bilgisini yazdýrýr
    }

}
void Kuyruk::KuyrukYazdir() {//Kuyruktaki elemanlarý yazdýrma fonksiyonu giriþi

    if (basla == NULL)//Baþlangýç NULL ise gir
    {
        cout << "<<Kuyruk Bos>>" << endl;//Baþlangýç NULL ise liste boþtur
    }
    else//Baþlangýç NULL deðil ise gir
    {
        int eleman = 1;// int veri tipinde eleman isimli deðiþken oluþturulur ve 1 deðeri atanýr
        tempr = basla;// Geçiciye baþlangiç deðerlerini ver
        cout << "   ***Kuyruktaki Elemanlar***\n" << endl;//Baþlýk
        while (tempr->pSonra != NULL)//Geçicinin sonrakisi NULL deðil ise döngüye gir
        {

            cout << "\t" << eleman << ".Eleman -->" << " " << (tempr->veri) << endl;//Sýralý bir þekilde yazdýrýr
            tempr = tempr->pSonra;//Geçicinin sonrakisini geçiciye ata
            eleman++;//elemaný arttýrýr
        }
        cout << "\t" << eleman << ".Eleman -->" << " " << (tempr->veri) << endl;//Elemaný yazdýrýr
    }

}
void Kuyruk::KuyrukTemizle() {//Kuyruðu Temizle fonksiyonu giriþi
    basla = 0;//Baþlangýca 0 deðeri atanýr
}

void IkiliAgac::AgacDugumEkle(int sayi) {//Ikili Aðaç için düðüm ekleme fonksiyonu giriþi
    Agacdugum* yenidugum, * dugumPtr; //yenidugum yenidügümü iþaret edecek ve dugumPtr düðümler arasý dolaþým yapacak
    yenidugum = new Agacdugum;//yeni düðüm oluþturduk

    yenidugum->veri = sayi;//yenidüðümümüzün verisi sayi olacak
    yenidugum->Sol = yenidugum->Sag = NULL; //yenidugumun sol ve saðý NULL yapacaðýz
    if (!kok)//aðaç boþ mu? diye if bloðunda sorgularýz Eðer boþ ise 
        kok = yenidugum;//kokumuzun deðeri yenidugum olacak
    else//eðer boþ deðil ise 
    {   //kök'ün adresini aðacý dolaþacak iþaretçiye atayalým
        dugumPtr = kok;//kok'u dugumPtr'ye atýyacaðýz
        while (dugumPtr != NULL) //aðaçta düðüm bulunduðu sürece while döngüsüne girer 
        {
            if (sayi < dugumPtr->veri)//sola eleman eklemek için if bloðu
            {//if içinde if oluþturuyoruz
                if (dugumPtr->Sol)//solda bir eleman varsa 
                    dugumPtr = dugumPtr->Sol;//sola ekle
                else
                {
                    dugumPtr->Sol = yenidugum;//dugumPtr'nin solu yenidugumde oluþturduðumuz dugum olacak 
                    break;//Döngüden çýk
                }
            }
            else if (sayi > dugumPtr->veri)//saða eleman eklemek için kod parçasý
            {//if içinde if oluþturuyoruz
                if (dugumPtr->Sag)//saðda eleman varsa
                    dugumPtr = dugumPtr->Sag;//saða ekle
                else {
                    dugumPtr->Sag = yenidugum;//dugumPtr'nin saðý yenidugumde oluþturduðumuz dugum olacak
                    break;//Döngüden çýk
                }
            }//else if sonu
            else//Agactaki deger birbirine eþitse 
            {
                cout << "Agacta deger iki defa bulundu";//Ekrana deðerin iki defa bulunduðunu yazdýrýr
                break;//Döngüden çýk
            }

        }//while sonu

    }//else sonu

}//fonksiyon sonu

bool IkiliAgac::DugumAra(int sayi)//DugumAra fonksiyonu giriþi 
{                                 //bu metodu silme metoduyla birlikte kullanacaðýz
    Agacdugum* dugumPtr = kok;//Agacdugum tipinde dugumPtr adýnda pointer'a kok deðerini atadýk
    while (dugumPtr)//dugumumuz varsa while döngüsüne girecek
    {
        if (dugumPtr->veri == sayi)//dugumPtr'nin verisi sayýya eþitse if bloðuna girer      
            return true;//true deðerini döndürür
        else if (sayi < dugumPtr->veri)//sayýmýz dugumPtr'nin verisinden küçükse bloða girer     
            dugumPtr = dugumPtr->Sol;//aðacýn solunda bulursa true deðerini döndürür
        else
            dugumPtr = dugumPtr->Sag;//aðacýn saðýnda bulursa true deðerini döndürür
    }
    return false;//Dugum yoksa false deðerini döndürür
}

void IkiliAgac::PreOrderDolas(Agacdugum* dugumPtr)//PreOrderDolas fonksiyonu giriþi
{//kök-sol-sað
    if (dugumPtr)//Düðüm varsa
    {
        cout << dugumPtr->veri << endl;
        PreOrderDolas(dugumPtr->Sol);
        PreOrderDolas(dugumPtr->Sag);//önce kökten baþlayýp sol ve saðý dolaþýr
    }
}

void IkiliAgac::InOrderDolas(Agacdugum* dugumPtr)//InOrderDolas fonksiyonu giriþi
{//sol-kök-sað 
    if (dugumPtr)//Düðüm varsa
    {
        InOrderDolas(dugumPtr->Sol);
        cout << dugumPtr->veri << endl;
        InOrderDolas(dugumPtr->Sag);//önce soldan baþlayýp kök ve saðý dolaþýr
    }
}
void IkiliAgac::PostOrderDolas(Agacdugum* dugumPtr)//PostOrderDolas fonksiyonu giriþi
{//sol-sað-kök
    if (dugumPtr) {//Düðüm varsa
        PostOrderDolas(dugumPtr->Sol);
        PostOrderDolas(dugumPtr->Sag);
        cout << dugumPtr->veri << endl;//önce soldan baþlayýp sað ve kökü dolaþýr
    }
}

void IkiliAgac::AgaciTemizle() {//Agaci temizleme fonksiyonu giriþi
    Agacdugum* yenidugum;//yenidugum yenidügümü iþaret edecek
    yenidugum = new Agacdugum;//yeni düðüm oluþturduk
    yenidugum->Sol = yenidugum->Sag = NULL;//yenidugumun sað ve sol deðerlerini  NULL yaptýk
    kok = NULL;//kök deðerimizide NULL deðerini atadýk
    //cout << "Agac Temizlendi!!!" << endl;
}

void IkiliAgac::AgacSil(int sayi)//AgacSil fonksiyonu giriþi
{
    AgacDugumSil(sayi, kok);//Silinecek deðeri alacak ve AgacDugumSil fonksiyonuna göndermek
}
void IkiliAgac::AgacDugumSil(int no, Agacdugum*& dugumPtr)
{//bu fonksiyonu sileceðimiz düðüme ulaþmak için 
    //bir düðüm silindiðinde alt aðacý baðlayacaðýmýz için 
    if (no < dugumPtr->veri)//sayý solda ise
        AgacDugumSil(no, dugumPtr->Sol);
    else if (no > dugumPtr->veri)//sayi saðda ise 
        AgacDugumSil(no, dugumPtr->Sag);
    else //sayýya ulaþtýðýmýzda silme iþlemini yapalým
        AgacTamSil(dugumPtr);//AgacTamSil fonksiyonunu çaðýrýr-> üç farklý fonksiyon kullandýk
}
void IkiliAgac::AgacTamSil(Agacdugum*& dugumPtr)//AgacTamSil fonksiyonu giriþi 
{
    Agacdugum* temp;//Agacdugum tipinde geçici iþaretçi oluþturduk
    //sol alt aðacý gösterecek olan gecici iþaretçimiz
    if (dugumPtr == NULL)//dugumPtr deðeri NULL ise yani düðüm yok demek
        cout << "Bos Dugumu Silemezsin\n";//ekrana dugumu silemezsin yazar
    else if (dugumPtr->Sag == NULL)//dugumPtr'nin saðý NULL ise 
    {
        temp = dugumPtr;//geçici pointer'a dugumPtr'yi atayalým
        dugumPtr = dugumPtr->Sol; // dugumPtr'nin deðeri sola atanýr
        delete temp;//geçici pointer'ý siler
    }
    else if (dugumPtr->Sol == NULL)//dugumPtr'nin solu NULL ise
    {
        temp = dugumPtr;//dugumPtr'sini geçici pointer'a atadýk
        dugumPtr = dugumPtr->Sag; // dugumPtr'nin deðeri saða atanýr
        delete temp; //geçici pointer'ý siler
    }
    else//dugumun iki tane elemaný varsa 
    {
        temp = dugumPtr->Sag;//geçici pointer'a dugumPtr'nin sað deðerini atadýk
        // sol düðümün sonuna gittik
        while (temp->Sol)//geçici pointer'ýn sol deðeri varsa
            temp = temp->Sol;//geçici pointer'a geçici pointer'in sol deðerini atadýk
        // Sol altaðacý yeniden atadýk
        temp->Sol = dugumPtr->Sol;//geçici pointer'ýn soluna dugumPtr'nin sol deðerini atadýk 
        temp = dugumPtr;//dugumPtr'sini geçici pointer'a atadýk
        // Sað altaðacý yeniden atadýk
        dugumPtr = dugumPtr->Sag;
        delete temp;//geçici pointer'ý siler
    }
}
void HashTablo::HashEkle(int Anahtar) { //Hash Tablosu için ekleme fonksiyonu giriþi
    Dugum* pYeni = new Dugum(Anahtar); //Dugum tipinde pYeni isminde bir pointerýmýz  olacak ve yeni dugumun anahtarýný atayacaðýz
    int mod = Anahtar % Max;//Anahtarýn Max ile bölümünden kalan deðeri mod deðiþkenine atadýk
    if (!veri[mod]) { //burada adres olup olmadýðýný kontrol etmek için bu bloðu oluþturuyoruz.Adres yoksa içeri girer
        veri[mod] = pYeni;//veri ye hangi indis geldiyse mod iþleminin sonucunda bunu pYeni'ye ekleyeceðiz
        return;//iþlemi bitirmek için return komutu
    } //Burada ise adres varsa bundan sonraki satýrlarda bunla ilgili iþlemleri yapacaðýz
    Dugum* Ptemp = veri[mod]; //ilgili indisteki adres bilgisini pTemp'e atacaðýz
    while (Ptemp->pSonraki != NULL) {//while döngüsü ile son elemana kadar devam edeceðiz
        Ptemp = Ptemp->pSonraki;//pTemp'e Ptemp'in pSonrakisini atayacaðýz
    }
    Ptemp->pSonraki = pYeni;//Ptemp'in pSonrakisi'ne pYeni'yi atayacaðýz
}
void HashTablo::HashGoster(int Anahtar) {//Hash Tablosu için Hash gösterme fonksiyonu giriþi

    int mod = Anahtar % Max;//Anahtarýn Max ile bölümünden kalan deðeri mod deðiþkenine atadýk
    Dugum* Ptemp = veri[mod];//ilgili indisteki adres bilgisini pTemp'e atacaðýz
    while (Ptemp != NULL)//Ptemp deðeri NULL olmadýðý sürece while döngüsü ile devam eder 
    {
        cout << Ptemp->Anahtar << endl;//Ptemp'in anahtarýný yazdýrýr
        Ptemp = Ptemp->pSonraki;//Ptemp'e Ptemp'in pSonrakisini atar
    }

}
void HashTablo::HashSil(int Anahtar) {//Hash Tablosu için Hash Silme fonksiyonu giriþi
    int mod = Anahtar % Max;//Anahtarýn Max ile bölümünden kalan deðeri mod deðiþkenine atadýk
    if (!veri[mod])////burada adres olup olmadýðýný kontrol etmek için bu bloðu oluþturuyoruz.Eleman yoksa içeri girer
        return;//return eder
    if (!veri[mod]->pSonraki) {//en az bir eleman varsa bu if bloðuna girer
        if (veri[mod]->Anahtar == Anahtar) {//veri mod'un Anahtarý bizim aradýðýmýz anahtar ise aþaðýdaki kod bloðuna girer
            delete veri[mod];//veri mod'taki düðümü silecek 
            veri[mod] = NULL;//veri mod'un ilgili indisine NULL atayacaðýz

        }
        return;//return komutu ile çýkarýz
    }
    if (veri[mod]->Anahtar == Anahtar) {//birden fazla eleman varsa bu bloða girecek
        Dugum* Py = veri[mod]->pSonraki; //dugum tipinde pY ismindeki deðerine  verinin modunun pSonrakisi deðerini atadýk
        delete veri[mod];//veri modun deðerini sildik
        veri[mod] = Py;//veri modu pY'ye baðlayacak
        return;//return ederek çýkacaðýz
    }
    Dugum* Ptemp = veri[mod];//Kalan tek bir durumda dugum tipinde Ptemp'e verinin modunu atadýk
    while (Ptemp->pSonraki != NULL) {//pTemp'in pSonraki'si NULL olana kadar while döngüsüne girer
        if (Ptemp->pSonraki->Anahtar == Anahtar) {//Ptemp'in pSonrakisini Anahtarý aradýðýmýz anahtar ise bu bloða girecek
            Dugum* Py = Ptemp->pSonraki;//dugum tipinde pY ismindeki deðerine  Ptemp'in pSonrakisi deðerini atadýk
            Ptemp->pSonraki = Py->pSonraki;//Ptemp'in pSonrakisi deðerini Ptemp'in pSonrakisi deðerine atadýk
            delete Py;//Py'yi sildik
            return;//return komutu ile çýkarýz
        }
        Ptemp = Ptemp->pSonraki;//Ptemp'e Ptemp'in pSonrakisi deðerini atadýk
    }
}
Dugum* HashTablo::HashiBul(int Anahtar)//Hash Tablosu için bulma  fonksiyonu giriþi
{
    int mod = Anahtar % Max;//Anahtarýn Max ile bölümünden kalan deðeri mod deðiþkenine atadýk
    Dugum* pTemp = veri[mod];//ilgili indisteki adres bilgisini pTemp'e atacaðýz
    while (pTemp != NULL)//while döngüsü ile pTemp NULL olmadýðý sürece girecek
    {
        if (pTemp->Anahtar == Anahtar)//pTemp'in Anahtarý bizim aradýðýmýz anahtar ise aþaðýdaki kod bloðuna girer
            return pTemp;//pTemp'i return eder
        pTemp = pTemp->pSonraki;//pTemp'e pTemp'in pSonrakisini atayacaðýz
    }

    return NULL;//aradýðýný bulamazsa NULL deðerini return eder
}

void HashTablo::HashiTemizle() {//Hash Tablosu için temizle fonksiyonu giriþi
    for (int i = 0; i < Max; i++)//0'dan baþlayup Max deðerine kadar 
        veri[i] = NULL;          //verinin ilgili indisine NULL deðerini atar
}







