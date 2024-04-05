//                                                              SAKARYA ÜNİVERSİTESİ
//                                                   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
//                                                       BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
//                                                         PROGRAMLAMAYA GİRİŞ DERSİ
//                                          
//                                                   ÖDEV NUMARASI.....: 2
//                                                   ÖĞRENCİ ADI.......: BARAN YEŞİLYURT
//                                                   ÖĞRENCİ NUMARASI..: G231210078
//                                                   DERS GRUBU........: 2. ÖĞRETİM B



#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Hesap {
private:
	int hesapNumara;
	double kriptoMiktar;
	time_t acilisTarih;
	bool ozelHesap;
	double oranGenel = 1;
	double oranÖzel = 1;
	int rastgeleGün[3];

public:

	Hesap(int numara, bool ozel = false) : hesapNumara(numara), ozelHesap(ozel) {
		kriptoMiktar = 1.0;
		acilisTarih = time(0);
	}
	bool isimOzelHesap() const {
		return ozelHesap;
	}
	int getHesapNumara() const {
		return hesapNumara;
	}

	void genelAl(double miktar) { // Genel hesap için dışarıdan para alınması
		kriptoMiktar += miktar * oranGenel;
		cout << miktar * oranGenel << " kripto paranız alındı" << endl;
	}
	void özelAl(double miktar) {// Özel hesap için dışarıdan para alınması
		kriptoMiktar += miktar * oranÖzel;
		cout << miktar * oranÖzel << " kripto paranız alındı" << endl;
	}

    void genelSat(double miktar) {// Genel hesap için para satılması için anyı zamanda bakiye kontrolü
        if (kriptoMiktar < miktar * oranGenel) {
            cout << "Bakiyeniz yetersiz" << endl;
        }
        else {
            kriptoMiktar -= miktar * oranGenel;
            cout << miktar * oranGenel << " kripto paranız satıldı" << endl;

        }
    }
    void ozelSat(double miktar) {// Özel hesap için para satılması için anyı zamanda bakiye kontrolü
        if (kriptoMiktar < miktar * oranÖzel) {
            cout << "Bakiyeniz yetersiz" << endl;
        }
        else {
            kriptoMiktar -= miktar * oranÖzel;
            cout << miktar * oranÖzel << " kripto paranız satıldı" << endl;
        }
    }
	void bakiye() {//Genel ve özel hesapların hesap numaraları ve bakiyelerin gösterilmesi
		cout << "Hesap numarası: " << hesapNumara << endl;
		if (ozelHesap) {
			cout << "Bakiye (Özel): " << kriptoMiktar * oranÖzel << endl; // Özel oranla çarpılarak gösteriliyor
		}
		else {
			cout << "Bakiye (Genel): " << kriptoMiktar * oranGenel << endl; // Genel oranla çarpılarak gösteriliyor
		}

	}

	void genelKar(int günSayısı) {// Genel hesap kar hesaplanışı 
        for (int i = 1; i <= günSayısı; i++) {
            if (i % 15 == 0) {
                oranGenel -= oranGenel * 0.05;
            }
            else {
                oranGenel += oranGenel * 0.01;
            };
        }
        

	}
	void özelKar(int günSayısı) {// Özel hesap kar hesaplanışı 
		
		for (int i = 0; i < 3; i++) {
			rastgeleGün[i] = rand() % 30 + 1;
		}
		for (int j = 0; j < günSayısı; j++) {
			if (j == rastgeleGün[0] || j == rastgeleGün[1] || j == rastgeleGün[2]) {
                oranÖzel -= oranÖzel * 0.1;
			}
			else {
                oranÖzel += oranÖzel * 0.05;
			}
		}

	}
};
int main() {
    setlocale(LC_ALL, "Turkish"); // Türkçe karakter kullanımı
    vector<Hesap> hesaplar;   // Girilen verilerin vector ile tutulması
    time_t simdiki_tarih;   
    time(&simdiki_tarih);// Sistem tarihinin alınması
    int secim;

    do {  // doğru sayıların girildiğini kontrol eden blok
        cout << "\n-----MENU-----\n";
        cout << "(1) GENEL HESAP AÇ\n";
        cout << "(2) ÖZEL HESAP AÇ\n";
        cout << "(3) PARA EKLE\n";
        cout << "(4) PARA ÇEK\n";
        cout << "(5) TARİH\n";
        cout << "(6) LİSTELE\n";
        cout << "(0) ÇIKIŞ\n";
        cout << "Yapmak istediğiniz işlemin başındaki sayıyı tuşlayınız: " << endl;
        cin >> secim;

        switch (secim) {
        case 1: { //Genel hesap açılıması ve bunun hesaplar vektörüne kaydedilmesi
            int hesapNo;
            cout << "Hesap numarasını giriniz: ";
            cin >> hesapNo;
            Hesap yeni_hesap(hesapNo);
            hesaplar.push_back(yeni_hesap);
            break;
        }
        case 2: {//Özel hesap açılıması ve bunun hesaplar vektörüne kaydedilmesi
            int hesapNo;
            cout << "Hesap numarasını giriniz: ";
            cin >> hesapNo;
            Hesap yeni_hesap(hesapNo, true);
            hesaplar.push_back(yeni_hesap);
            break;
        }
        case 3: { //Genel ve özel hesap için para eklenmesi
            int hesapNo;
            double eklenecekPara;
            cout << "Hesap numarasını giriniz: ";
            cin >> hesapNo;

            // Hesap bulunması ve para ekleme işlemi
            bool hesapVar = false;
            for (Hesap& hesap : hesaplar) {
                if (hesap.getHesapNumara() == hesapNo) {
                    hesapVar = true;
                    cout << "Eklenecek miktarı giriniz: ";
                    cin >> eklenecekPara;
                   
                   
                    if (hesap.isimOzelHesap()) {
                        hesap.özelAl(eklenecekPara); // Özel hesap ise özelAl fonksiyonunu çağır
                    }
                    else {
                        hesap.genelAl(eklenecekPara); // Genel hesap ise genelAl fonksiyonunu çağır
                    } 
                    break;
                
                }
            }
            if (!hesapVar) {//Hesabın bulunmaması durumunda çalışan blok
                cout << "Hesap bulunamadı!" << endl;
            }

            break;
        }
        case 4: { //Genel ve özel hesap için para çekilmesi
             int hesapNo;
            double cekilecekPara;
            cout << "Hesap numarasını giriniz: ";
            cin >> hesapNo;

            // Hesap bulunması ve para çekme işlemi
            bool hesapVar = false;
            for (Hesap& hesap : hesaplar) {
                if (hesap.getHesapNumara() == hesapNo) {
                    hesapVar = true;
                    cout << "Çekilecek miktarı giriniz: ";
                    cin >> cekilecekPara;
                    if (hesap.isimOzelHesap()) {
                        hesap.ozelSat(cekilecekPara); // Özel hesap ise özelSat fonksiyonunu çağır
                    }
                    else {
                        hesap.genelSat(cekilecekPara); // Genel hesap ise genelSat fonksiyonunu çağır
                    }
                    break;
                }
            }

            if (!hesapVar) { //Hesabın bulunmaması durumunda çalışan blok
                cout << "Hesap bulunamadı!" << endl;
            }
            break;
            }
        case 5: {
            struct tm zaman;
            localtime_s(&zaman, &simdiki_tarih);

            char tarihStr[11]; // Tarih için yeterli boyutta bir karakter dizisi
            strftime(tarihStr, sizeof(tarihStr), "%d-%m-%Y", &zaman); // Gün-Ay-Yıl formatında tarih oluşturulması
            cout << "İleri alınmış tarih: " << tarihStr << endl;

            // Kaç gün ileri alınacağını sor
            int gun_ileri;
            cout << "Kaç gün ileri gitmek istiyorsunuz: ";
            cin >> gun_ileri;

            // Sistemi belirtilen gün sayısı kadar ileri taşı ve yeni sistem tarihi olarak ayarlanması
            simdiki_tarih += (gun_ileri * 24 * 60 * 60);
            localtime_s(&zaman, &simdiki_tarih);
            strftime(tarihStr, sizeof(tarihStr), "%d-%m-%Y", &zaman); // Gün-Ay-Yıl formatında tarih oluşturulması
            cout << gun_ileri << " gün ileri tarih: " << tarihStr << endl;

            // Tüm hesapların bakiyesini güncellenmesi
            for (Hesap& hesap : hesaplar) {
                hesap.genelKar(gun_ileri);
            }
            for (Hesap& hesap : hesaplar) {
                hesap.özelKar(gun_ileri);
            }

            break;
        }
        case 6: {// Hesapların listelenmesi
            if (hesaplar.empty()) {// hesapların açılıp açılmadığı kontrolü
                cout << "Henüz hesap açılmamış!" << endl;
            }
            else {// Açılan hesapların listelenmesi
                cout << "Açılan hesaplar:" << endl;
                for (size_t i = 0; i < hesaplar.size(); ++i) {
                    cout << "-------------------------" << endl;
                    cout << "Hesap numarası: " << hesaplar[i].getHesapNumara() << endl;
                    if (hesaplar[i].isimOzelHesap()) {
                        cout << "Hesap türü: Özel Hesap" << endl;
                    }
                    else {
                        cout << "Hesap türü: Genel Hesap" << endl;
                    }
                    hesaplar[i].bakiye();
                    cout << "-------------------------" << endl;
                }
            }
            break;
        }
        case 0:// Menüden çıkması kullanılan blok
            break;
        default:// hatalı sayı girdiğinde kullanılan blok
            cout << "HATALI SAYI GİRİDİNİZ!!" << endl;
            break;
        }
    } while (secim != 0);

    return 0;
}