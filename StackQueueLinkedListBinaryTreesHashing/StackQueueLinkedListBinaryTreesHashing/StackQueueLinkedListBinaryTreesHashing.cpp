#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<string>
using namespace std;//�lk 4 sat�rda kullanaca��m�z k�t�phaneleri ekledik
static const int Max = 10;//C�rp�lama(Hash Tablosu) i�in Max de�erini 10'a e�itledik

string anamenu = "Yapmak Istediginiz Uygulamayi Seciniz:\n 1-Yigin Uygulamasi\n 2-Kuyruk Uygulamasi\n 3-Tek Yonlu Bagli Liste Uygulamasi\n 4-Ikili Agac Uygulamasi\n 5-Cirpilama Uygulamasi\n 6-Programdan Cikis";//Kullanaca��m�z Anamen�y� mainde string olarak olu�turduk

class BagliListe {// Ba�l�liste s�n�f�n� kurduk
public://Tan�mlayaca��m�z �eyin public olaca��n� belirttik
    BagliListe()//Kurucu fonksiyon
    {
        pSonraki = NULL;//pSonraki de�erine NULL de�erini atad�k
    }
    int veri;//int veri tipinde 'veri' isminde bir de�i�ken olu�turduk
    BagliListe* pSonraki;// pointer de�i�ken olu�turduk
    void BagliListeSonaEkle(BagliListe*, BagliListe*);//Sona ekleme fonksiyonu tan�mlad�k
    void BagliListeArayaEkle(BagliListe*, BagliListe*, int);//Araya ekleme fonksiyonu tan�mlad�k
    void BagliListeAradanCikar(BagliListe*, int);// Aradan ��karma fonksiyonu tan�mlad�k
    void BagliListeSondanCikar(BagliListe*);// Sondan ��karma fonksiyon tan�mlad�k

};

class Stack {////Y���n s�n�f� olu�turduk

    int veri;//int veri tipinde 'veri' isminde bir de�i�ken olu�turduk


public://Tan�mlayaca��m�z �eylerin public olaca��n� belirttik
    Stack* pSonraki;// Y���n tipinde pointer de�i�keni olu�turduk


    void StackPush(int x);//Y���na eleman ekleme fonksiyonu tan�mlad�k
    void StackPop();//Y���ndan eleman ��karma fonksiyonu tan�mlad�k
    void StackWriteAll();//Y���n� yazd�rma fonksiyonu tan�mlad�k
    void StackDeleteAll();//Y���n� temizleme fonksiyonu tan�mlad�k

};

Stack* start = NULL;//Y���n ba�lang�c�na NULL de�erini atad�k
Stack* temp;// Ge�ici bir de�i�ken olu�turduk

Stack* dugumYarat()//Y���ndan d���m yapma fonksiyonu yazd�k
{
    Stack* yenidugum = (Stack*)malloc(sizeof(Stack));//Y���n tipinde yenid���m de�i�keni olu�turup y���n uzunlu�una ekledik
    return yenidugum;//yenid���m de�i�kenini return ettik(d��ar�ya verdik)
}

class Kuyruk {//Kuyruk s�n�f� olu�turduk

    int veri;//int veri tipinde 'veri' isminde bir de�i�ken olu�turduk


public://Tan�mlayaca��m�z �eylerin public olaca��n� belirttik
    Kuyruk* pSonra;//Kuyruk tipinde pointer de�i�keni olu�turduk

    void KuyrukEkle(int x);//Kuyru�a eleman ekleme fonksiyonu tan�mlad�k
    void KuyrukCikar();//Kuyruktan eleman ��karma fonksiyonu tan�mlad�k
    void KuyrukYazdir();//Kuyru�u yazd�rma fonksiyonu tan�mlad�k
    void KuyrukTemizle();//Kuyru�u temizle fonksiyonunu tan�mlad�k
};

Kuyruk* basla = NULL;// Kuyruk ba�lang�c�na NULL de�erini atad�k
Kuyruk* tempr;//Kuyruktan ge�ici de�i�ken olu�turduk

Kuyruk* dugumYap()//Kuyruktan d���m olu�turma fonksiyonu yazd�k
{
    Kuyruk* newdugum = (Kuyruk*)malloc(sizeof(Kuyruk));//Kuyruk tipinde newdugum de�i�keni olu�turduk ve y���ndaki eleman say�s�na ekle dedik.
    return newdugum;//newdugumu return ettik(d��ar�ya verdik)
}
class IkiliAgac {//Ikili A�a� s�n�f� olu�turduk
public:
    struct Agacdugum {
        int veri;//int veri tipinde 'veri' isminde bir de�i�ken olu�turduk ve bu de�i�ken a�aca de�er almak i�in kullan�lacak
        Agacdugum* Sol;//A�ac�n solu
        Agacdugum* Sag;//A�ac�n sa��
    };
    Agacdugum* kok;//A�ac�n k�k�n� belirtiyoruz burada
    IkiliAgac() //'IkiliAgac' isminde yap�c� metot olu�turduk
    {
        kok = NULL;//k�k'e NULL de�erini veriyoruz
    }
    void AgacDugumEkle(int);//A�aca eleman ekleme fonksiyonu tan�mlad�k


    //A�a�ta dola�mak i�in gerekli fonksiyonlar
    void InOrderDolas(Agacdugum* dugumPtr);//InOrder dolasmak i�in fonskiyon tan�mlad�k
    void PreOrderDolas(Agacdugum* dugumPtr);//PreOrder dolasmak i�in fonksiyon tan�mlad�k
    void PostOrderDolas(Agacdugum* dugumPtr);//PostOrder dolasmak i�in fonksiyon tan�mlad�k

    //D���mleri g�stermek i�in gerekli fonksiyonlar
    void InOrderDugumGoster()//InOrder g�sterme fonksiyonu
    {
        InOrderDolas(kok);
    }
    void PreOrderDugumGoster()//PreOrder g�sterme fonksiyonu
    {
        PreOrderDolas(kok);
    }
    void PostOrderDugumGoster()//PostOrder g�sterme fonksiyonu
    {
        PostOrderDolas(kok);
    }

    bool DugumAra(int sayi); //bool tipinde DugumAra metodu-->A�acta arama yapmak i�in metod. Bunu sil fonksiyonu ile kullanaca��z
    void AgacSil(int sayi);//AgacSil isimli fonksiyon silinecek de�eri ve k�k� DugumSil isimli fonksiyona ge�irsin 
    void AgacDugumSil(int, Agacdugum*&);//bu fonksiyonu silece�imiz d���me ula�mak amac�yla kullanaca��z
                                        //bir d���m silindi�inde alt a�ac� ba�layaca��m�z i�in sadece 
                                        //bu yap�y� tutan i�aret�inin adresine i�aret ediyoruz
    void AgacTamSil(Agacdugum*&);//AgacTamSil isimli fonksiyon tan�m� ve bu fonksiyonu alt a�ac� ba�lamak i�in kullanaca��z

    void AgaciTemizle();//AgaciTemizle isimli fonksiyon tan�mlad�k Bu fonksiyon A�ac� temizleyecek
    void AgacinElemanSayisi(int eleman);//AgacinElemanSayisi isimli fonksiyon tan�mlad�k Bu Aga�taki eleman say�s�n� g�sterecek bize
};
class Dugum {//Dugum s�n�f� olu�turduk 
public:
    int Anahtar; //int veri tipinde 'Anahtar' isminde bir de�i�ken olu�turduk
    Dugum* pSonraki;//Dugum tipinde bir pointer'�m�z olacak pSonraki isminde
    Dugum(int Anahtar)//Dugum olu�tururken ilk ad�m
    {
        this->Anahtar = Anahtar;//Olu�turdu�umuz d���m�n Anahtar isimli de�i�kenine Anahtar de�i�kenini atayaca��z
        pSonraki = NULL;//pSonraki de�erine NULL de�erini atad�k
    }
};
class HashTablo {
public:
    Dugum* veri[Max];//Dugum tipinde veri isimli i�aret�i olu�turuyoruz ve bu verinin Boyutu MAX olacak
    HashTablo();//'HashTablo' isminde kurucu fonksiyon olu�turduk
    void HashEkle(int Anahtar);// HashEkle isimli fonksiyon tan�mlad�k.Bu ekleme i�lemini yapacak          
    void HashiTemizle();//temizleme fonksiyonu
    void HashSil(int Anahtar);//HashSil isimli fonksiyon tan�mlad�k.Bu silme i�lemini yapacak 
    void HashGoster(int Anahtar);//elemanlar� g�sterme fonksiyonu
    Dugum* HashiBul(int Anahtar);//Dugum tipinde HashiBul isimli fonksiyon tan�mlad�k.Bu bulmay� silme i�inde kullanacak             

};
HashTablo::HashTablo() {//Tabloyu olu�turmak i�in yap�c� fonksiyon olu�turduk
    for (int i = 0; i < Max; i++)//0'dan ba�layan Max de�erine kadar for d�ng�s� olu�turduk
        veri[i] = NULL;//10 eleman� NULL yapt�k
}

int main()// main fonksiyonu giri�
{
    BagliListe* p1 = new BagliListe();////Ba�l�listeden p1 eleman� olu�turduk
    p1->veri = 0;//en ba�a 0 eleman�n� atad�k
    IkiliAgac Agac;//A�a� i�in tan�mlama olu�turduk
    int agacElemanSayisi = 0;//int veri tipinde 'agacElemanSayisi' isimli de�i�ken olu�turduk ve ba�lang�� de�erine 0'� atad�k
    HashTablo Hash;//Hash Tablosu i�in tan�mlama olu�turduk
    int hashElemanSayisi = 0;//int veri tipinde 'hashElemanSayisi' isimli de�i�ken olu�turduk ve ba�lang�� de�erine 0'� atad�k

    do {//D�ng� giri�i

        cout << "########################################" << endl;
        cout << "#############              #############" << endl;
        cout << anamenu << endl;
        cout << "########################################" << endl;//Anamen�y� yazd�rd�k 3 sat�rda
        cout << "#############              #############" << endl;//�ekiller olu�turarak biraz g�rsellik katt�k 
        char secim;//karakter tipinde secim isimli de�i�ken olu�turduk
        cout << "secim:";
        cin >> secim;//Se�imi kullan�c�dan ald�k ve yazd�rd�k

        switch (secim)//Karar vermek i�in se�imimizi switch yap�s�na verdik
        {
        case '1'://1'i se�ersek
            cout << "********************************" << endl;
            cout << "******** YIGIN UYGULAMASI ********" << endl;//Ekranda YIGIN UYGULAMA's� yazacak

            do {//D�ng� giri�i

                cout << "---------------------------------" << endl;
                cout << "Yigin icin islem seciniz:" << endl;
                cout << "1-Yigina Eleman Ekle" << endl;
                cout << "2-Yigindan Eleman Cikar" << endl;
                cout << "3-Yigini Temizle" << endl;
                cout << "4-Yigindaki Elemanlari Goster" << endl;
                cout << "5-Yigindaki Eleman Sayisini Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Y���n men�s�n� yazd�rd�k

                char islem;//karakter tipinde islem de�i�keni olu�turduk
                cout << "islem:";
                cin >> islem;//i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k

                switch (islem)//i�lemi karar yap�s�na soktuk
                {
                case'1'://1'i se�ersek
                {
                    Stack a;// Y���n tipinde nesne olu�turduk
                    int eklenecek;//int veri tipinde 'eklenecek' isimli de�i�ken olu�turduk
                    cout << "Eklenecek Elemani Giriniz:\n";
                    cin >> eklenecek;//Kullan�c�dan eklenecek eleman� ald�k ve bunu yazd�rd�k
                    a.StackPush(eklenecek);// Ekleme fonksiyonunu �a��rd�k ve ekledik
                    cout << "---> " << eklenecek << " " << "Elemani yigina eklendi" << endl;//eklendi bilgisini ekrana yazd�rd�k
                }
                break;//D�ng�den ��k

                case'2'://2'yi se�ersek
                {
                    Stack a;// Y���n tipinde nesne

                    a.StackPop();// Veri silme fonksiyonunu �a��rd�k
                    cout << "   Eleman yigindan silindi" << endl;// silindi bilgisi ekrana yazd�rd�k
                }

                break;//D�ng�den ��k

                case'3'://3'� se�ersek
                {
                    Stack a;//Y���n tipinde nesne
                    a.StackDeleteAll();// Y���n� temizle fonksiyonunu �a��rd�k
                    cout << "---->Tum elemanlar Yigindan silinerek temizlendi<----" << endl;//Elemanlar�n Y���ndan silindi�i bilgisini yazd�r�r



                }

                break;// D�ng�den ��k

                case'4'://4'� se�ersek
                {
                    Stack a;// Y���n tipinde nesne
                    a.StackWriteAll();// Y���n� yazd�rma fonksiyonunu �a��rd�k
                }

                break;// D�ng�den ��k

                case'5'://5'i se�ersek
                {
                    {
                        cout << "***Yigindaki Eleman Sayisi***\n";// Kar��m�za gelen men� 
                        Stack* pDegisken = start;//  Y���n tipinde de�i�ken olu�turduk
                        int elemansayisi = 0;//De�i�ken olu�turup 0 de�erini atad�k
                        while (pDegisken != NULL)// De�i�ken 0 de�ilse d�ng�ye gir
                        {
                            pDegisken = pDegisken->pSonraki;//pDe�i�kenin pSonrakisini pDe�i�kene atad�k
                            elemansayisi++;//elemansayisini artt�rd�k
                        }
                        cout << "---------> " << elemansayisi << " <--------" << endl;// eleman sayisini yazd�rd�k

                        break;//D�ng�den ��k
                    }
                }

                break;//D�ng�den ��k

                case'6'://6'y se�ersek

                    break;// D�ng�den ��k
                }

                if (islem == '6')break;// e�er i�lem 6 ise d�ng�den ��k

            } while (true);//D�ng�den veya programdan ��k komutu gelmedik�e d�ng�ye gir

            cout << "********************************" << endl;
            break;// D�ng�den ��k

        case '2':// 2'yi se�ersek
            cout << "********************************" << endl;
            cout << "******** KUYRUK UYGULAMASI ********" << endl;//Ekranda KUYRUK UYGULAMASI yazacak

            do {// D�ng� giri�i

                cout << "---------------------------------" << endl;
                cout << "Kuyruk icin islem seciniz:" << endl;
                cout << "1-Kuyruga Eleman Ekle" << endl;
                cout << "2-Kuyruktan Eleman Cikar" << endl;
                cout << "3-Kuyrugu Temizle" << endl;
                cout << "4-Kuyruktaki Elemanlari Goster" << endl;
                cout << "5-Kuyruktaki Eleman Sayisini Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;// Kuyruk men�s�n� yazd�rd�k

                char islem;// karakter tipinde islem de�i�keni olu�turduk
                cout << "islem:";
                cin >> islem;// i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k

                switch (islem)// i�lemi karar yap�s�na soktuk
                {
                case'1':// 1'i se�ersek
                {
                    Kuyruk a;// Kuyruk tipinde nesne olu�ur
                    int eklenecek;// int veri tipinde 'eklenecek' isimli de�i�ken olu�turduk
                    cout << "Eklenecek Elemani Giriniz:";
                    cin >> eklenecek;// Kullan�c�dan eklenecek eleman� ald�k ve bunu yazd�rd�k

                    a.KuyrukEkle(eklenecek);// KuyrukEkle fonksiyonunu �a��rd�k ve ekledik
                    cout << "---> " << eklenecek << " " << "Elemani kuyruga eklendi" << endl;//eleman eklendi bilgisini ekrana yazd�rd�k
                }
                break;// D�ng�den ��k

                case'2':// 2'yi se�ersek
                {
                    Kuyruk a;// Kuyruk tipinde nesne olu�ur

                    a.KuyrukCikar();//KuyrukCikar fonksiyonunu �a��rd�k
                    cout << "   Eleman kuyruktan silindi" << endl;//eleman silindi bilgisi ekrana yazd�rd�k
                }
                break;// D�ng�den ��k

                case'3':// 3 ise gir.
                {
                    Kuyruk a;//Kuyruk tipinde nesne olu�ur
                    a.KuyrukTemizle();//KuyruguTemizle fonksiyonunu �a��rd�k
                    cout << "---->Tum elemanlar Kuyruktan silinerek temizlendi<----" << endl;//Ekrana Kuyru�un temizlendi�i bilgisini yazd�r�r 


                }
                break;// D�ng�den ��k

                case'4':// 4'� se�ersek
                {
                    Kuyruk a;// Kuyruk tipinde nesne olu�ur
                    a.KuyrukYazdir();// KuyrukYazdir fonksiyonunu �a��rd�k
                }
                break;// D�ng�den ��k

                case'5':// 5'i se�ersek
                {
                    {
                        cout << "***Kuyruktaki Eleman Sayisi***\n";// ba�l�k
                        Kuyruk* pDegisken = basla;// Kuyruk tipinde de�i�ken olu�turuyoz ve baslaya e�itliyoruz
                        int elemansayisi = 0;// De�i�ken olu�turup 0'a e�itliyoruz
                        while (pDegisken != NULL)//De�i�ken 0'a e�it de�il ise d�ng�ye gir
                        {
                            pDegisken = pDegisken->pSonra;//pDegisken = pDe�i�kenin pSonrakisi yapt�k
                            elemansayisi++;// elemansay�s�n� artt�rd�k
                        }
                        cout << "---------> " << elemansayisi << " <--------" << endl;// elemansay�s�n� yazd�rd�k

                        break;// D�ng�den ��k
                    }
                }
                break;// D�ng�den ��k

                case'6'://6'y� se�ersek

                    break;// D�ng�den ��k
                }

                if (islem == '6')break;// E�er islem=6 ise d�ng�den ��k

            } while (true);// D�ng�den herhangibir ��kma i�lemi yap�lmad��� m�ddet�e hep d�ng�ye girecek

            cout << "********************************" << endl;
            break;

        case '3':
            cout << "********************************" << endl;
            cout << "******** TEK YONLU BAGLI LISTE ********" << endl;//Ekranda KUYRUK UYGULAMASI yazacak

            do {//D�ng� giri�i

                cout << "---------------------------------" << endl;
                cout << "Bagli liste icin islem seciniz:" << endl;
                cout << "1-Listeye Eleman Ekle" << endl;
                cout << "2-Listeden Eleman Cikar" << endl;
                cout << "3-Listeyi Temizle" << endl;
                cout << "4-Listedeki Elemanlari Goster" << endl;
                cout << "5-Listedeki Eleman Sayisini Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Ba�l� Liste men�s�n� yazd�rd�k

                char islem;//karakter tipinde islem isimli de�i�keni olu�turduk
                cout << "islem:";
                cin >> islem;//i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k

                switch (islem)//i�lemi karar yap�s�na soktuk
                {
                case'1':// 1'i se�ersek 

                    do {//D�ng� giri�i

                        cout << "///////////////////////////////" << endl;
                        cout << "Ekleme Turunu Seciniz:" << endl;
                        cout << "1-Araya Eleman Ekle" << endl;
                        cout << "2-Sona Eleman Ekle" << endl;
                        cout << "3-Liste Islemlerine Geri Don" << endl;
                        cout << "///////////////////////////////" << endl;//Ekleme t�r� men�s�n� yazd�r�r

                        char islem;//karakter tipinde islem isimli de�i�keni olu�turduk
                        cout << "islem:";
                        cin >> islem;//i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k 

                        switch (islem)//i�lemi karar yap�s�na soktuk
                        {
                        case'1'://1'i se�ersek
                        {
                            BagliListe s;//Ba�l�Listeden s isminde bir nesne olu�turduk 
                            BagliListe* pYeni = new BagliListe();//BagliListeden bir de�i�ken olusturduk
                            int eklenen;//int veri tipinde 'eklenen' isimli de�i�ken olu�turduk
                            int index;//int veri tipinde 'index' isimli de�i�ken olu�turduk
                            cout << "Lutfen Eklemek Istediginiz Elemani Giriniz:";
                            cin >> eklenen;//Kullan�c�dan eleman istedik ve g�stedik 2 sat�rda
                            pYeni->veri = eklenen;//pYeni'nin verisine kullan�c�dan ald���m�z de�eri verdik 
                            cout << "Lutfen kacinci indise eklemek istediginizi giriniz:";
                            cin >> index;//kullan�c�dan indis verisini girmesini istedik
                            s.BagliListeArayaEkle(p1, pYeni, index);;//BagliListeArayaEkle fonksiyonunu �a��rd�k 
                            cout << index << ". indise" << " " << eklenen << " " << "elemani eklendi..." << endl;//hangi indise hangi eleman�n eklendi�ini yazd�r�r

                            break;//D�ng�den ��k
                        }
                        case'2'://2'yi se�ersek
                        {
                            BagliListe s;//Ba�l�Listeden s isminde bir nesne olu�turduk 
                            BagliListe* pYeni = new BagliListe();//BagliListeden bir de�i�ken olusturduk
                            int eklenen;//int veri tipinde 'eklenen' isimli de�i�ken olu�turduk
                            cout << "Lutfen Eklemek Istediginiz Elemani Giriniz:";
                            cin >> eklenen;//kullan�c�dan deger ald�k ve g�sterdik 2 sat�rda
                            pYeni->veri = eklenen;//pYeni'nin verisine kullan�c�dan ald���m�z de�eri verdik 
                            s.BagliListeSonaEkle(p1, pYeni);//BagliListeSonaEkle fonksiyonunu �a��rd�k
                            cout << eklenen << " " << "Elemani Listeye Eklendi..." << endl;//Bilgiyi yazd�rd�k

                            break;//D�ng�den ��k
                        }

                        case'3'://3'� se�ersek 

                            break;//D�ng�den ��k
                        }

                        if (secim == '3')break;//Se�im 3 ise d�ng�den ��k

                    } while (true);//D�ng� hep devam edicek true. biz break return demezsek

                    break;//D�ng�den ��k

                case'2'://2'yi se�ersek

                    do {// D�ng� giri�i

                        cout << "///////////////////////////////" << endl;
                        cout << "Cikarma Turunu Seciniz:" << endl;
                        cout << "1-Aradan Eleman Cikar" << endl;
                        cout << "2-Sondan Eleman Cikar" << endl;
                        cout << "3-Liste Islemlerine Geri Don" << endl;
                        cout << "///////////////////////////////" << endl;//��karma men�s� ekrana yazd�r�l�r

                        char islem;//karakter tipinde 'islem' isimli de�i�keni olu�turduk
                        cout << "islem:";
                        cin >> islem;// i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k

                        switch (islem)//i�lemi karar yap�s�na soktuk
                        {
                        case'1'://1'i se�ersek
                        {
                            BagliListe s;// Ba�l�Listeden s isminde bir nesne olu�turduk

                            int cikarilan;// int veri tipinde 'eklenen' isimli de�i�ken olu�turduk
                            int index;// int veri tipinde 'index' isimli de�i�ken olu�turduk

                            cout << "Lutfen kacinci indisten eleman cikarmak istediginizi giriniz:";
                            cin >> index;//Ka��nc� oldugu bilgisini kullan�c�dan al�p gosterdik
                            s.BagliListeAradanCikar(p1, index);//BagliListeArayaEkle fonksiyonunu �a��rd�k
                            cout << index << ". indisteki eleman cikarildi..." << endl;//hangi indisten hangi eleman�n ��kar�ld���n� yazd�r�r

                            break;//D�ng�den ��k
                        }
                        case'2'://2'yi se�ersek
                        {
                            BagliListe s;//Ba�l�Listeden s isminde bir nesne olu�turduk

                            s.BagliListeSondanCikar(p1);//BagliListeSondanCikar fonksiyonunu �a��rd�k
                            cout << "Sondaki Eleman Listeden Cikarildi!!" << endl;//Sondan eleman ��kar�ld��� bilgisini yazd�r�r

                            break;//D�ng�den ��k
                        }
                        case'3'://3'� se�ersek

                            break;//D�ng�den ��k
                        }

                        if (secim == '3')break;//Se�im 3 ise d�ng�den ��k

                    } while (true);// Durma komutuna basmad�k�a d�ng� s�rekli tekrar eder

                    break;// D�ng�den ��k

                case'3':// 3'� se�ersek
                {

                }
                break;// D�ng�den ��k

                case'4'://4'� se�ersek
                {   BagliListe* pTemp = p1;
                if (pTemp == NULL)
                {
                    cout << "<<Liste Bos>>" << endl;


                }
                else
                {
                    int eleman = 1;//int veri tipinde eleman isimli de�i�ken olu�turduk ve buna 1 de�erini atad�k
                    cout << "   ***Listedeki Elemanlar***\n" << endl;//Ba�l�k yazd�r�l�r
                    BagliListe* pTemp = p1;//Ge�ici de�i�ken olu�turduk ve p1'i atad�k
                    while (pTemp != NULL)// De�i�ken NULL de�ilse d�ng�ye girecek
                    {
                        cout << "\t" << eleman << ".Eleman" << " " << pTemp->veri << endl;// yazd�rd�k
                        pTemp = pTemp->pSonraki;//Ge�icinin bir sonraki  de�i�kene ge�mesini aradaki ba�lant� ile sa�lad�k
                        eleman++;// eleman� artt�rd�k 
                    }
                    break;// D�ng�den ��k

                }

                }
                case'5': //5'i se�ersek
                {
                    cout << "***Listedeki Eleman Sayisi***\n";//ba�l�k.
                    BagliListe* pTemp = p1;//Ge�ici de�i�ken olu�turduk ve p1'i atad�k
                    int elemansayisi = 0;//int veri tipinde elemansayisi ad�nda de�i�ken olu�turduk ve 0 de�erini atad�k
                    while (pTemp != NULL)//Ge�ici NULL de�ilse girecek
                    {
                        pTemp = pTemp->pSonraki;// Ge�iciyi sonrakine ge�ecek �ekilde g�sterdik
                        elemansayisi++;//elemansay�s�n� artt�rd�k
                    }
                    cout << "---------> " << elemansayisi << " <--------" << endl;//elemansay�s�n� yazd�rd�k

                    break;//D�ng�den ��k
                }
                case'6':// 6'y� se�ersek



                    break;//D�ng�den ��k
                }

                if (islem == '6')break;//��lem 6 ise d�ng�den ��k

            } while (true);// Durma komutuna basmad�k�a d�ng� s�rekli tekrar eder

            cout << "********************************" << endl;
            break;//D�ng�den ��k

        case '4'://4'� se�ersek

            cout << "***************************************" << endl;
            cout << "******** IKILI AGAC UYGULAMASI ********" << endl;//Ekranda IKILI AGAC UYGULAMA's� yazacak

            do //D�ng� giri�i 
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
                cout << "---------------------------------" << endl;//Ikili Agac men�s�n� yazd�rd�k

                char islem;//karakter tipinde islem de�i�keni olu�turduk
                cout << "islem:";
                cin >> islem;//i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k

                switch (islem)
                {
                case'1'://1'i se�ersek
                {
                    int sayi;//int veri tipinde'sayi' isimli de�i�ken olu�turduk
                    cout << "Eklenecek elemani girininiz:\n";
                    cin >> sayi;//Kullan�c�dan eklenecek eleman� ald�k ve bunu yazd�rd�k
                    Agac.AgacDugumEkle(sayi);//AgacDugumEkle fonksiyonunu �a��rd�k ve ekledik
                    agacElemanSayisi++;//eleman say�s�n� art�rd�k
                    cout << "---> " << sayi << " " << "Elemani Agaca eklendi" << endl;//eklendi bilgisini ekrana yazd�rd�k
                    break;//D�ng�den ��k


                }
                case'2'://2'yi se�ersek
                {
                    int sayi;//int veri tipinde'sayi' isimli de�i�ken olu�turduk
                    cout << "Silinecek elemani  giriniz:" << endl;
                    cin >> sayi;//Kullan�c�dan silinecek eleman� ald�k ve bunu yazd�rd�k
                    if (Agac.DugumAra(sayi)) {//d�g�m ara fonksiyonu ile sayinin olup olmamas�n� if blo�u ile sorgulay�p varsa eleman� sildik
                        Agac.AgacSil(sayi);//kullan�c�dan ald���m�z say�y� AgacSil fonksiyonuna i�ledik
                        cout << sayi << " Elemani Agactan silindi" << endl; //silindi bilgisi ekrana yazd�rd�k
                        agacElemanSayisi--;//eleman say�s�n� azaltt�k
                    }
                    else
                        cout << sayi << " Elemani Agacta Yok " << endl;//Silinecek eleman�n Aga�ta olmad��� bilgisi ekrana yazd�r�l�r
                    break;//D�ng�den ��k   
                }
                case'3'://3'� se�ersek
                {
                    Agac.AgaciTemizle();//A�ac� temizleme fonksiyonunu �a��rd�k
                    agacElemanSayisi = 0;//eleman say�m�z� 0 a e�itledik
                    cout << "---->Tum elemanlar Agactan silinerek temizlendi<----" << endl;//Elemanlar�n A�a�tan silindi�i bilgisini yazd�r�r
                }

                case'4'://4'� se�ersek
                {
                    cout << "Eleman sayisi:" << agacElemanSayisi << endl;//Eleman say�s�n� ekrana yazd�rd�k
                    break;//D�ng�den ��k
                }

                case'5'://5'i se�ersek
                {
                    cout << "InOrder Dolasim:" << endl;
                    Agac.InOrderDugumGoster();//InOrderDugumGoster fonksiyonunu �a��rd�k ve g�sterdik
                    break;//D�ng�den ��k

                }

                case'6'://6'y� se�ersek
                {
                    cout << "PreOrder Dolasim:" << endl;
                    Agac.PreOrderDugumGoster();//PreOrderDugumGoster fonksiyonunu �a��rd�k ve g�sterdik 
                    break;//D�ng�den ��k
                }

                case'7'://7'yi se�ersek
                {
                    cout << "PostOrder Dolasim:" << endl;
                    Agac.PostOrderDugumGoster();//PostOrderDugumGoster fonksiyonunu �a��rd�k ve g�sterdik 
                    break;//D�ng�den ��k
                }

                case'8'://8'i se�ersek

                    break;//D�ng�den ��k
                }
                if (islem == '8')break;//e�er i�lem 8 ise d�ng�den ��k 

            } while (true); //D�ng�den veya programdan ��k komutu gelmedik�e d�ng�ye gir

            cout << "********************************" << endl;
            break;//D�ng�den ��k


        case '5'://5'i se�ersek
            cout << "**************************************" << endl;
            cout << "******** CIRPILAMA UYGULAMASI ********" << endl;//Ekranda CIRPILAMA UYGULAMASI's� yazacak

            do //D�ng� giri�i 
            {
                cout << "---------------------------------" << endl;
                cout << "Cirpilama (Hash Tablosu) icin islem seciniz:" << endl;
                cout << "1-Tabloya Eleman Ekle" << endl;
                cout << "2-Tablodan Eleman Sil" << endl;
                cout << "3-Tabloyu Temizle" << endl;
                cout << "4-Tablodaki Eleman Sayisini Goster" << endl;
                cout << "5-Tablodaki Elemanlari Goster" << endl;
                cout << "6-Ana Menuye Geri Don" << endl;
                cout << "---------------------------------" << endl;//Cirpilama (Hash Tablosu) men�s�n� yazd�rd�k

                char islem;//karakter tipinde islem de�i�keni olu�turduk
                cout << "islem:";
                cin >> islem;//i�lem de�i�kenini kullan�c�dan ald�k ve yazd�rd�k

                switch (islem)
                {
                case'1'://1'i se�ersek
                {
                    int sayi;//int veri tipinde'sayi' isimli de�i�ken olu�turduk
                    cout << "Eklenecek elemani girininiz:\n";
                    cin >> sayi;//Kullan�c�dan eklenecek eleman� ald�k ve bunu yazd�rd�k
                    Hash.HashEkle(sayi);//HashEkle fonksiyonunu �a��rd�k ve ekledik
                    hashElemanSayisi++;//eleman say�s�n� artt�rd�k
                    cout << "---> " << sayi << " " << "Elemani Tabloya eklendi" << endl;//eklendi bilgisini ekrana yazd�rd�k
                    break; //D�ng�den ��k
                }

                case'2'://2'yi se�ersek
                {
                    int sayi;//int veri tipinde'sayi' isimli de�i�ken olu�turduk
                    cout << "Silinecek elemani giriniz:" << endl;
                    cin >> sayi;//Kullan�c�dan silinecek eleman� ald�k ve bunu yazd�rd�k
                    if (Hash.HashiBul(sayi)) {//HashiBul bulma fonksiyonu ile kullan�c�n�n silece�i say� var m� diye if blo�u ile konrtol ettirdik
                        Hash.HashSil(sayi);//HashSil silme fonksiyonunu �a��rd�k
                        cout << sayi << " Elemani Tablodan silindi" << endl; //silindi bilgisi ekrana yazd�rd�k
                        hashElemanSayisi--;//elemman say�s�n� azaltt�k
                    }
                    else
                        cout << sayi << " Elemani Tabloda Yok " << endl;//Silinecek eleman�n Tabloda olmad��� bilgisi ekrana yazd�r�l�r


                    break;//D�ng�den ��k


                }

                case'3'://3'� se�ersek
                {
                    Hash.HashiTemizle();//Tabloyu temizleme fonksiyonunu �a��rd�k
                    hashElemanSayisi = 0;//hash tablomuzun eleman say�s�n�'0 a e�itledik
                    cout << "---->Tum elemanlar Tablodan silinerek temizlendi<----" << endl;//Elemanlar�n Tablodan silindi�i bilgisini yazd�r�r
                    break;//D�ng�den ��k
                }

                case'4'://4'� se�ersek
                {
                    cout << "Eleman sayisi:" << hashElemanSayisi << endl;//Eleman say�s�n� ekrana yazd�rd�k                
                    break;//D�ng�den ��k                                  
                }

                case'5'://5'i se�ersek
                {
                    int sayi = 0;
                    for (int sayi = 0; sayi < 10; sayi++) {//0'dan ba�lay�p 10'a kadar giden for d�ng�s� ba�latt�k. sayi de�eri s�rayla a�a��dakini yapacak
                        Hash.HashGoster(sayi);//HashGoster elemanlar� g�sterme fonksiyonun �a��rd�k ve her z de�erinde ilgili fonksiyon i�lemi yapar
                    }
                    break;//D�ng�den ��k
                }

                case'6'://6'y� se�ersek

                    break;//D�ng�den ��k
                }
                if (islem == '6')break;//e�er i�lem 6 ise d�ng�den ��k

            } while (true);//D�ng�den veya programdan ��k komutu gelmedik�e d�ng�ye gir

            cout << "********************************" << endl;
            break;//D�ng�den ��k


        case '6'://6'y� se�ersek

            cout << "********************************" << endl;
            cout << "<<<<--PROGRAMDAN CIKILIYOR-->>>>" << endl;
            cout << "********************************" << endl;//Programdan ��k�l�yor bilgisini ekrana yazd�rd�k
            return 0;//Programdan ��kma komutu



        }

    } while (true);// Durma komutuna basmad�k�a d�ng� s�rekli tekrar eder
}// main sonu

void BagliListe::BagliListeSonaEkle(BagliListe* pBas, BagliListe* pYeni)//BagliListenin sona ekleme fonksiyonu
{
    while (pBas->pSonraki != NULL)//pBas'�n pSonraki de�eri NULL de�ilse d�ng�ye gir 
    {
        pBas = pBas->pSonraki;//pBas'�n pSonraki de�erini pBasa verdik 
    }

    pBas->pSonraki = pYeni;//Kullan�c�dan ald���m�z pYeni'yi pBas'�n pSonrakisine verdik D�ng�den dolay� en sona gelecek
}
void BagliListe::BagliListeArayaEkle(BagliListe* pBas, BagliListe* pYeni, int index)//Ba�l�Liste ArayaEkleme fonksiyonu tan�m ve giri�i
{
    for (int i = 0; i < index - 2; i++)//Kullan�c�dan ald���m�z indisi kullanarak for d�ng�s� ba�latt�k
        pBas = pBas->pSonraki;// �art sa�lanana kadar pBas'a pBas'�n pSonraki de�erine gittik

    pYeni->pSonraki = pBas->pSonraki;//Kullan�c�dan ald���m�z pYeni'nin pSonrakisi'ne pBas'�n pSonrakisini verdik
    pBas->pSonraki = pYeni;//pyeniyi pbas�n psonrakisine vererek ba�lant�y� kuruyoruz.
}
void BagliListe::BagliListeAradanCikar(BagliListe* pBas, int index)// Ba�l�Liste Aradan��kar fonksiyonu tan�m ve giri�i
{
    for (int i = 0; i < index - 2; i++)//Kullan�c�dan ald���m�z indisi kullanarak for d�ng�s� ba�latt�k
        pBas = pBas->pSonraki;//pBas'�n pSonrakisi yeni pBas olacak ve �art sa�lanan kadar devam eder

    pBas->pSonraki = pBas->pSonraki->pSonraki;//pBas'�n pSonrakisi yerine  pBas�n 2 tane pSonrakisi gelerek arada bir eleman es ge�ilir

}

void BagliListe::BagliListeSondanCikar(BagliListe* pBas)//Ba�l�Liste SondanC�kar fonksiyonu tan�m ve giri�i
{
    while (pBas->pSonraki->pSonraki != NULL)//pBas'�n 2 pSonrakisi NULL de�ilse d�ng�ye gir. Son eleman� g�zard� edelim
        pBas = pBas->pSonraki;//pBas'a pBas�n pSonraki de�erini vererek d�nd�r

    pBas->pSonraki = NULL;// pBas'�n pSonrakisini NULL yap.Eleman� g�z ard� etmek i�in

}
void Stack::StackPush(int x) {//Y���n ekleme fonksiyonu giri�i

    Stack* element = dugumYarat();//Y���n tipinde element isminde d���m yarat�l�r
    element->veri = x;//element'in verisine kullan�c�dan ald���m�z de�eri verece�iz

    temp = start;//Ge�iciye ba�lang�� olan NULL at�yaca��z

    element->pSonraki = temp;//elementin pSonraki de�erine ge�iciyi atayarak yeni eleman olu�turmu� olaca��z

    start = element;//ba�lang�ca elementi verece�iz

}
void Stack::StackPop() {//Y���ndan ��karma fonksiyonu giri�i

    if (start != NULL)// Ba�lang�� NULL de�il ise gir
    {
        if (start->pSonraki != NULL)//Baslang���n pSonrakisi NULL de�il ise gir
        {
            Stack* temp2 = start;//Y���n tipinde yeni ge�ici olu�tur
            start = start->pSonraki;//Ba�lang��a ba�lang���n pSonrakisi'ni ata 
            free(temp2);//ge�icinin yerine null ��kard�k
        }
        else
        {//�stteki if blo�u sa�lanmazsa e�er
            free(start);//Belle�e start atan�r.
            start = NULL;//Ba�lang��a NULL verilerek eleman silinir
        }

    }
    else// Ba�langI� NULL de�ilse girer
    {
        cout << "<<<<Silinecek Eleman Yok !!>>>>" << endl;//Eleman yok bilgisi verilir
    }

}
void Stack::StackWriteAll() {//Y���n� yazd�rma fonksiyonu giri�i

    if (start == NULL)//Ba�langi� null ise gir
    {
        cout << "<<Yigin Bos>>" << endl;//Liste bo� yaz�l�r
    }
    else//if blo�u �art� sa�lamazsa  
    {
        temp = start;// Ge�iciye ba�lang�c� verdi
        cout << "   ***Yigindaki Elemanlar***\n" << endl;//Ba�l�k
        while (temp->pSonraki != NULL)//Ge�icinin sonrakisi NULL de�il ise gir
        {
            cout << "\t\t" << (temp->veri) << endl;//Ge�icinin verisini yazd�r�l�r
            temp = temp->pSonraki;//Ge�iciye ge�icinin sonrakisini vererek d�nd�r
        }
        cout << "\t\t" << (temp->veri) << endl;//ge�icinin verisini yazd�r�r
    }

}
void Stack::StackDeleteAll() {//Y���n� temizle fonksiyonu giri�i
    start = 0; //Ba�lang�ca 0 de�eri atan�r
}
void Kuyruk::KuyrukEkle(int x) {//Kuyru�a ekleme fonksiyonu giri�i

    Kuyruk* element = dugumYap();//Kuyruk tipinde element isminde d���m olu�turulur

    element->veri = x;//elementin verisine kullan�c�dan al�nan de�eri verir
    element->pSonra = NULL;//elementin sonrakisine NULL de�erini ata

    if (basla == NULL)//Ba�lang�c NULL ise gir
    {
        basla = element;//Ba�lang�ca elementten al�nan de�erleri verir
    }
    else//if blo�u �art� sa�lamazsa
    {

        tempr = basla;//Ge�iciye ba�lang�c� verir
        while (tempr->pSonra != NULL)//Ge�icicinin sonrakisi NULL de�il ise gir
        {
            tempr = tempr->pSonra;//Ge�iciye ge�iciden sonrakini ver
        }

        tempr->pSonra = element;//Elementteki bilgileri ge�icinin sonrakisine ver ve numa eklenmi� olur
    }


}
void Kuyruk::KuyrukCikar() {//Kuyruktan eleman ��karma fonksiyonu giri�i

    if (basla != NULL)// Baslang�� NULL de�il ise gir
    {
        if (basla->pSonra != NULL)//Ba�lang�c�n sonrakisi NULL de�il ise gir
        {
            Kuyruk* tempr2 = basla;//Kuyruk tipinde yeni ge�ici olu�turup ba�lang�c� ata
            basla = basla->pSonra;//Ba�lang�ca ba�lang�c�n sonrakisini ver
            free(tempr2);//Ba�lang�� de�erini ay�r
        }
        else//if blo�u �art� sa�lamazsa
        {
            free(basla);//Ba�lang�� de�erini ay�r
            basla = NULL;//Ba�lang�ca NULL ver
        }
    }
    else//Ba�lang�� NULL degil sa�lanmaz ise gir
    {
        cout << "<<<<Silinecek Eleman Yok !!>>>>" << endl;//Silinecek eleman yok bilgisini yazd�r�r
    }

}
void Kuyruk::KuyrukYazdir() {//Kuyruktaki elemanlar� yazd�rma fonksiyonu giri�i

    if (basla == NULL)//Ba�lang�� NULL ise gir
    {
        cout << "<<Kuyruk Bos>>" << endl;//Ba�lang�� NULL ise liste bo�tur
    }
    else//Ba�lang�� NULL de�il ise gir
    {
        int eleman = 1;// int veri tipinde eleman isimli de�i�ken olu�turulur ve 1 de�eri atan�r
        tempr = basla;// Ge�iciye ba�langi� de�erlerini ver
        cout << "   ***Kuyruktaki Elemanlar***\n" << endl;//Ba�l�k
        while (tempr->pSonra != NULL)//Ge�icinin sonrakisi NULL de�il ise d�ng�ye gir
        {

            cout << "\t" << eleman << ".Eleman -->" << " " << (tempr->veri) << endl;//S�ral� bir �ekilde yazd�r�r
            tempr = tempr->pSonra;//Ge�icinin sonrakisini ge�iciye ata
            eleman++;//eleman� artt�r�r
        }
        cout << "\t" << eleman << ".Eleman -->" << " " << (tempr->veri) << endl;//Eleman� yazd�r�r
    }

}
void Kuyruk::KuyrukTemizle() {//Kuyru�u Temizle fonksiyonu giri�i
    basla = 0;//Ba�lang�ca 0 de�eri atan�r
}

void IkiliAgac::AgacDugumEkle(int sayi) {//Ikili A�a� i�in d���m ekleme fonksiyonu giri�i
    Agacdugum* yenidugum, * dugumPtr; //yenidugum yenid�g�m� i�aret edecek ve dugumPtr d���mler aras� dola��m yapacak
    yenidugum = new Agacdugum;//yeni d���m olu�turduk

    yenidugum->veri = sayi;//yenid���m�m�z�n verisi sayi olacak
    yenidugum->Sol = yenidugum->Sag = NULL; //yenidugumun sol ve sa�� NULL yapaca��z
    if (!kok)//a�a� bo� mu? diye if blo�unda sorgular�z E�er bo� ise 
        kok = yenidugum;//kokumuzun de�eri yenidugum olacak
    else//e�er bo� de�il ise 
    {   //k�k'�n adresini a�ac� dola�acak i�aret�iye atayal�m
        dugumPtr = kok;//kok'u dugumPtr'ye at�yaca��z
        while (dugumPtr != NULL) //a�a�ta d���m bulundu�u s�rece while d�ng�s�ne girer 
        {
            if (sayi < dugumPtr->veri)//sola eleman eklemek i�in if blo�u
            {//if i�inde if olu�turuyoruz
                if (dugumPtr->Sol)//solda bir eleman varsa 
                    dugumPtr = dugumPtr->Sol;//sola ekle
                else
                {
                    dugumPtr->Sol = yenidugum;//dugumPtr'nin solu yenidugumde olu�turdu�umuz dugum olacak 
                    break;//D�ng�den ��k
                }
            }
            else if (sayi > dugumPtr->veri)//sa�a eleman eklemek i�in kod par�as�
            {//if i�inde if olu�turuyoruz
                if (dugumPtr->Sag)//sa�da eleman varsa
                    dugumPtr = dugumPtr->Sag;//sa�a ekle
                else {
                    dugumPtr->Sag = yenidugum;//dugumPtr'nin sa�� yenidugumde olu�turdu�umuz dugum olacak
                    break;//D�ng�den ��k
                }
            }//else if sonu
            else//Agactaki deger birbirine e�itse 
            {
                cout << "Agacta deger iki defa bulundu";//Ekrana de�erin iki defa bulundu�unu yazd�r�r
                break;//D�ng�den ��k
            }

        }//while sonu

    }//else sonu

}//fonksiyon sonu

bool IkiliAgac::DugumAra(int sayi)//DugumAra fonksiyonu giri�i 
{                                 //bu metodu silme metoduyla birlikte kullanaca��z
    Agacdugum* dugumPtr = kok;//Agacdugum tipinde dugumPtr ad�nda pointer'a kok de�erini atad�k
    while (dugumPtr)//dugumumuz varsa while d�ng�s�ne girecek
    {
        if (dugumPtr->veri == sayi)//dugumPtr'nin verisi say�ya e�itse if blo�una girer      
            return true;//true de�erini d�nd�r�r
        else if (sayi < dugumPtr->veri)//say�m�z dugumPtr'nin verisinden k���kse blo�a girer     
            dugumPtr = dugumPtr->Sol;//a�ac�n solunda bulursa true de�erini d�nd�r�r
        else
            dugumPtr = dugumPtr->Sag;//a�ac�n sa��nda bulursa true de�erini d�nd�r�r
    }
    return false;//Dugum yoksa false de�erini d�nd�r�r
}

void IkiliAgac::PreOrderDolas(Agacdugum* dugumPtr)//PreOrderDolas fonksiyonu giri�i
{//k�k-sol-sa�
    if (dugumPtr)//D���m varsa
    {
        cout << dugumPtr->veri << endl;
        PreOrderDolas(dugumPtr->Sol);
        PreOrderDolas(dugumPtr->Sag);//�nce k�kten ba�lay�p sol ve sa�� dola��r
    }
}

void IkiliAgac::InOrderDolas(Agacdugum* dugumPtr)//InOrderDolas fonksiyonu giri�i
{//sol-k�k-sa� 
    if (dugumPtr)//D���m varsa
    {
        InOrderDolas(dugumPtr->Sol);
        cout << dugumPtr->veri << endl;
        InOrderDolas(dugumPtr->Sag);//�nce soldan ba�lay�p k�k ve sa�� dola��r
    }
}
void IkiliAgac::PostOrderDolas(Agacdugum* dugumPtr)//PostOrderDolas fonksiyonu giri�i
{//sol-sa�-k�k
    if (dugumPtr) {//D���m varsa
        PostOrderDolas(dugumPtr->Sol);
        PostOrderDolas(dugumPtr->Sag);
        cout << dugumPtr->veri << endl;//�nce soldan ba�lay�p sa� ve k�k� dola��r
    }
}

void IkiliAgac::AgaciTemizle() {//Agaci temizleme fonksiyonu giri�i
    Agacdugum* yenidugum;//yenidugum yenid�g�m� i�aret edecek
    yenidugum = new Agacdugum;//yeni d���m olu�turduk
    yenidugum->Sol = yenidugum->Sag = NULL;//yenidugumun sa� ve sol de�erlerini  NULL yapt�k
    kok = NULL;//k�k de�erimizide NULL de�erini atad�k
    //cout << "Agac Temizlendi!!!" << endl;
}

void IkiliAgac::AgacSil(int sayi)//AgacSil fonksiyonu giri�i
{
    AgacDugumSil(sayi, kok);//Silinecek de�eri alacak ve AgacDugumSil fonksiyonuna g�ndermek
}
void IkiliAgac::AgacDugumSil(int no, Agacdugum*& dugumPtr)
{//bu fonksiyonu silece�imiz d���me ula�mak i�in 
    //bir d���m silindi�inde alt a�ac� ba�layaca��m�z i�in 
    if (no < dugumPtr->veri)//say� solda ise
        AgacDugumSil(no, dugumPtr->Sol);
    else if (no > dugumPtr->veri)//sayi sa�da ise 
        AgacDugumSil(no, dugumPtr->Sag);
    else //say�ya ula�t���m�zda silme i�lemini yapal�m
        AgacTamSil(dugumPtr);//AgacTamSil fonksiyonunu �a��r�r-> �� farkl� fonksiyon kulland�k
}
void IkiliAgac::AgacTamSil(Agacdugum*& dugumPtr)//AgacTamSil fonksiyonu giri�i 
{
    Agacdugum* temp;//Agacdugum tipinde ge�ici i�aret�i olu�turduk
    //sol alt a�ac� g�sterecek olan gecici i�aret�imiz
    if (dugumPtr == NULL)//dugumPtr de�eri NULL ise yani d���m yok demek
        cout << "Bos Dugumu Silemezsin\n";//ekrana dugumu silemezsin yazar
    else if (dugumPtr->Sag == NULL)//dugumPtr'nin sa�� NULL ise 
    {
        temp = dugumPtr;//ge�ici pointer'a dugumPtr'yi atayal�m
        dugumPtr = dugumPtr->Sol; // dugumPtr'nin de�eri sola atan�r
        delete temp;//ge�ici pointer'� siler
    }
    else if (dugumPtr->Sol == NULL)//dugumPtr'nin solu NULL ise
    {
        temp = dugumPtr;//dugumPtr'sini ge�ici pointer'a atad�k
        dugumPtr = dugumPtr->Sag; // dugumPtr'nin de�eri sa�a atan�r
        delete temp; //ge�ici pointer'� siler
    }
    else//dugumun iki tane eleman� varsa 
    {
        temp = dugumPtr->Sag;//ge�ici pointer'a dugumPtr'nin sa� de�erini atad�k
        // sol d���m�n sonuna gittik
        while (temp->Sol)//ge�ici pointer'�n sol de�eri varsa
            temp = temp->Sol;//ge�ici pointer'a ge�ici pointer'in sol de�erini atad�k
        // Sol alta�ac� yeniden atad�k
        temp->Sol = dugumPtr->Sol;//ge�ici pointer'�n soluna dugumPtr'nin sol de�erini atad�k 
        temp = dugumPtr;//dugumPtr'sini ge�ici pointer'a atad�k
        // Sa� alta�ac� yeniden atad�k
        dugumPtr = dugumPtr->Sag;
        delete temp;//ge�ici pointer'� siler
    }
}
void HashTablo::HashEkle(int Anahtar) { //Hash Tablosu i�in ekleme fonksiyonu giri�i
    Dugum* pYeni = new Dugum(Anahtar); //Dugum tipinde pYeni isminde bir pointer�m�z  olacak ve yeni dugumun anahtar�n� atayaca��z
    int mod = Anahtar % Max;//Anahtar�n Max ile b�l�m�nden kalan de�eri mod de�i�kenine atad�k
    if (!veri[mod]) { //burada adres olup olmad���n� kontrol etmek i�in bu blo�u olu�turuyoruz.Adres yoksa i�eri girer
        veri[mod] = pYeni;//veri ye hangi indis geldiyse mod i�leminin sonucunda bunu pYeni'ye ekleyece�iz
        return;//i�lemi bitirmek i�in return komutu
    } //Burada ise adres varsa bundan sonraki sat�rlarda bunla ilgili i�lemleri yapaca��z
    Dugum* Ptemp = veri[mod]; //ilgili indisteki adres bilgisini pTemp'e ataca��z
    while (Ptemp->pSonraki != NULL) {//while d�ng�s� ile son elemana kadar devam edece�iz
        Ptemp = Ptemp->pSonraki;//pTemp'e Ptemp'in pSonrakisini atayaca��z
    }
    Ptemp->pSonraki = pYeni;//Ptemp'in pSonrakisi'ne pYeni'yi atayaca��z
}
void HashTablo::HashGoster(int Anahtar) {//Hash Tablosu i�in Hash g�sterme fonksiyonu giri�i

    int mod = Anahtar % Max;//Anahtar�n Max ile b�l�m�nden kalan de�eri mod de�i�kenine atad�k
    Dugum* Ptemp = veri[mod];//ilgili indisteki adres bilgisini pTemp'e ataca��z
    while (Ptemp != NULL)//Ptemp de�eri NULL olmad��� s�rece while d�ng�s� ile devam eder 
    {
        cout << Ptemp->Anahtar << endl;//Ptemp'in anahtar�n� yazd�r�r
        Ptemp = Ptemp->pSonraki;//Ptemp'e Ptemp'in pSonrakisini atar
    }

}
void HashTablo::HashSil(int Anahtar) {//Hash Tablosu i�in Hash Silme fonksiyonu giri�i
    int mod = Anahtar % Max;//Anahtar�n Max ile b�l�m�nden kalan de�eri mod de�i�kenine atad�k
    if (!veri[mod])////burada adres olup olmad���n� kontrol etmek i�in bu blo�u olu�turuyoruz.Eleman yoksa i�eri girer
        return;//return eder
    if (!veri[mod]->pSonraki) {//en az bir eleman varsa bu if blo�una girer
        if (veri[mod]->Anahtar == Anahtar) {//veri mod'un Anahtar� bizim arad���m�z anahtar ise a�a��daki kod blo�una girer
            delete veri[mod];//veri mod'taki d���m� silecek 
            veri[mod] = NULL;//veri mod'un ilgili indisine NULL atayaca��z

        }
        return;//return komutu ile ��kar�z
    }
    if (veri[mod]->Anahtar == Anahtar) {//birden fazla eleman varsa bu blo�a girecek
        Dugum* Py = veri[mod]->pSonraki; //dugum tipinde pY ismindeki de�erine  verinin modunun pSonrakisi de�erini atad�k
        delete veri[mod];//veri modun de�erini sildik
        veri[mod] = Py;//veri modu pY'ye ba�layacak
        return;//return ederek ��kaca��z
    }
    Dugum* Ptemp = veri[mod];//Kalan tek bir durumda dugum tipinde Ptemp'e verinin modunu atad�k
    while (Ptemp->pSonraki != NULL) {//pTemp'in pSonraki'si NULL olana kadar while d�ng�s�ne girer
        if (Ptemp->pSonraki->Anahtar == Anahtar) {//Ptemp'in pSonrakisini Anahtar� arad���m�z anahtar ise bu blo�a girecek
            Dugum* Py = Ptemp->pSonraki;//dugum tipinde pY ismindeki de�erine  Ptemp'in pSonrakisi de�erini atad�k
            Ptemp->pSonraki = Py->pSonraki;//Ptemp'in pSonrakisi de�erini Ptemp'in pSonrakisi de�erine atad�k
            delete Py;//Py'yi sildik
            return;//return komutu ile ��kar�z
        }
        Ptemp = Ptemp->pSonraki;//Ptemp'e Ptemp'in pSonrakisi de�erini atad�k
    }
}
Dugum* HashTablo::HashiBul(int Anahtar)//Hash Tablosu i�in bulma  fonksiyonu giri�i
{
    int mod = Anahtar % Max;//Anahtar�n Max ile b�l�m�nden kalan de�eri mod de�i�kenine atad�k
    Dugum* pTemp = veri[mod];//ilgili indisteki adres bilgisini pTemp'e ataca��z
    while (pTemp != NULL)//while d�ng�s� ile pTemp NULL olmad��� s�rece girecek
    {
        if (pTemp->Anahtar == Anahtar)//pTemp'in Anahtar� bizim arad���m�z anahtar ise a�a��daki kod blo�una girer
            return pTemp;//pTemp'i return eder
        pTemp = pTemp->pSonraki;//pTemp'e pTemp'in pSonrakisini atayaca��z
    }

    return NULL;//arad���n� bulamazsa NULL de�erini return eder
}

void HashTablo::HashiTemizle() {//Hash Tablosu i�in temizle fonksiyonu giri�i
    for (int i = 0; i < Max; i++)//0'dan ba�layup Max de�erine kadar 
        veri[i] = NULL;          //verinin ilgili indisine NULL de�erini atar
}







