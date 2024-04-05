#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cctype>

using namespace std;

class Futbolcu {
private:
    string tcNo;
    string futbolcuAdı;
    string futbolcuSoyadı;
    string lisansNo;
    string oyunKonumu;
    string futbolcuÜcret;
    string futbolcuDoğumT;

public:
    static vector<Futbolcu> futbolcular;
    string getTcNo() const {
        return tcNo;
    }
    string getFutbolcuAdı() const {
        return futbolcuAdı;
    }
    string getFutbolcuSoyadı() const {
        return futbolcuSoyadı;
    }
    string getLisansNo() const {
        return lisansNo;
    }
    string getOyunKonumu() const {
        return oyunKonumu;
    }
    string getFutbolcuÜcret() const {
        return futbolcuÜcret;
    }
    string getFutbolcuDoğumT() const {
        return futbolcuDoğumT;
    }
    void setFutbolcuSoyadı(const string& soyad) {
        futbolcuSoyadı = soyad;
    }
    void setFutbolcuAdı(const string& ad) {
        futbolcuAdı = ad;
    }
    void setLisansNo(const string& lisans) {
        lisansNo = lisans;
    }
    void setOyunKonumu(const string& konum) {
        oyunKonumu = konum;
    }
    void setFutbolcuÜcret(int ücret) {
        futbolcuÜcret = ücret;
    }
    void setFutbolcuDoğumT(const string& doğumT) {
        futbolcuDoğumT = doğumT;
    }
    string futbolcuTCnoAl() const {
        return tcNo; // Burada tcNo, futbolcunun TC numarasını içeren bir değişken olarak varsayılmıştır
    }
    vector<string> futbolcuTCListesi;
    void futbolcubilgiAL() {
        bool isSayı = true;
        bool sadeceSayi;


        cout << "Oyuncunun TC kimlik numarasını giriniz (sadece 11 rakam): ";
        cin >> setw(11) >> tcNo;


        cout << "Oyuncunun adını giriniz: ";
        cin >> setw(20) >> futbolcuAdı;

        cout << "Oyuncunun Soyadı giriniz: ";
        cin >> setw(20) >> futbolcuSoyadı;



        cout << "Oyuncunun lisans numarasını giriniz: ";
        cin >> setw(11) >> lisansNo;


        cout << "Oyuncunun oynayacağı konumu giriniz: ";
        cin >> setw(20) >> oyunKonumu;




        cout << "Oyuncunun alacağı ücreti giriniz: ";
        cin >> futbolcuÜcret;

        cin.ignore();
        cout << "Oyuncunun doğum tarihini giriniz.(gün.ay.yıl)" << endl;
        getline(cin, futbolcuDoğumT);

    }
    void futbolcubilgiYaz(ofstream& dosya) const {
        dosya << "Oyuncunun TC kimlik numarası: " << tcNo << endl;
        dosya << "Oyuncunun adı: " << futbolcuAdı << endl;
        dosya << "Oyuncunun soyadı: " << futbolcuSoyadı << endl;
        dosya << "Oyuncunun lisans numarası: " << lisansNo << endl;
        dosya << "Oyuncunun oynayacağı konum: " << oyunKonumu << endl;
        dosya << "Oyuncunun alacağı ücret: " << futbolcuÜcret << endl;
        dosya << "Oyuncunun doğum tarihi: " << futbolcuDoğumT << endl << endl;
        dosya << "****************************************************************" << endl;
    }
    void futbolcuEkleDosya() {
        ifstream dosyaOku("Futbolcu.txt");

        if (!dosyaOku.is_open()) {
            cout << "Dosya açılamadı!" << endl;
            return;
        }

        Futbolcu yeniFutbolcu;
        yeniFutbolcu.futbolcubilgiAL();

        dosyaOku.close();

        // Kontrol etmek istediğiniz vektördeki durum burada yapılır
        auto it = find(futbolcuTCListesi.begin(), futbolcuTCListesi.end(), yeniFutbolcu.futbolcuTCnoAl());
        if (it != futbolcuTCListesi.end()) {
            cout << "Bu TC numarasına sahip bir futbolcu zaten var. Yeni futbolcu eklenemedi." << endl;
            return;
        }

        // Eğer vektörde yoksa, dosyaya yazma işlemi gerçekleşir ve vektöre eklenir
        ofstream futbolcuDosya("Futbolcu.txt", ios::app);

        if (!futbolcuDosya.is_open()) {
            cout << "Dosya açılamadı!" << endl;
            return;
        }

        yeniFutbolcu.futbolcubilgiYaz(futbolcuDosya);
        futbolcuDosya.close();

        // Vektöre ekleme işlemi yapılır
        futbolcuTCListesi.push_back(yeniFutbolcu.futbolcuTCnoAl());

        cout << "Yeni futbolcu başarıyla eklendi." << endl;
    }

    void futbolcuSil(const string& tcNo) {
        for (int i = 1; i <= 100; ++i) {
            string dosyaAdi = "takim_" + to_string(i) + ".txt";
            ifstream dosyaOku(dosyaAdi);

            if (!dosyaOku.is_open()) {
                continue;
            }

            string tempDosyaAdi = "temp_" + dosyaAdi;
            ofstream tempDosya(tempDosyaAdi);

            string satir;
            bool oyuncuBulundu = false;

            while (getline(dosyaOku, satir)) {
                if (satir.find(tcNo) == string::npos) {
                    tempDosya << satir << endl;
                }
                else {
                    oyuncuBulundu = true;
                }
            }

            dosyaOku.close();
            tempDosya.close();

            if (!oyuncuBulundu) {
                remove(tempDosyaAdi.c_str());
            }
            else {
                remove(dosyaAdi.c_str());
                rename(tempDosyaAdi.c_str(), dosyaAdi.c_str());
                cout << "Oyuncu başarıyla takımdan silindi." << endl;
            }
        }

        ifstream futbolcuDosya("futbolcu.txt");
        ofstream tempFutbolcuDosya("temp_futbolcu.txt");

        if (!futbolcuDosya.is_open() || !tempFutbolcuDosya.is_open()) {
            cout << "futbolcu.txt dosyaları açılamadı!" << endl;
            return;
        }

        bool oyuncuBulundu = false;
        string satir;

        while (getline(futbolcuDosya, satir)) {
            if (satir.find(tcNo) == string::npos) {
                tempFutbolcuDosya << satir << endl;
            }
            else {
                oyuncuBulundu = true;
            }
        }

        futbolcuDosya.close();
        tempFutbolcuDosya.close();

        if (!oyuncuBulundu) {
            remove("temp_futbolcu.txt");
        }
        else {
            remove("futbolcu.txt");
            rename("temp_futbolcu.txt", "futbolcu.txt");
            cout << "Oyuncu başarıyla futbolcu.txt'den silindi." << endl;
        }
        auto it = find(futbolcuTCListesi.begin(), futbolcuTCListesi.end(), tcNo);
        if (it != futbolcuTCListesi.end()) {
            futbolcuTCListesi.erase(it);
            cout << "Oyuncu başarıyla vektörden silindi." << endl;
        }
    }
    void futbolcuGuncelle(const string& tcNo) {
        // Takım dosyalarını kontrol et
         // Yeni bilgileri al
        Futbolcu yeniBilgiler;
        yeniBilgiler.futbolcubilgiAL();
        for (int i = 1; i <= 100; ++i) {
            string dosyaAdi = "takim_" + to_string(i) + ".txt";
            ifstream dosyaOku(dosyaAdi);

            if (!dosyaOku.is_open()) {
                continue;
            }

            string tempDosyaAdi = "temp_" + dosyaAdi;
            ofstream tempDosya(tempDosyaAdi);

            string satir;
            bool oyuncuBulundu = false;

            while (getline(dosyaOku, satir)) {
                if (satir.find(tcNo) == string::npos) {
                    tempDosya << satir << endl;
                }
                else {


                    // Yeni bilgileri dosyaya yaz
                    tempDosya << yeniBilgiler.getTcNo() << endl
                        << yeniBilgiler.getFutbolcuAdı() << endl
                        << yeniBilgiler.getFutbolcuSoyadı() << endl
                        << yeniBilgiler.getLisansNo() << endl
                        << yeniBilgiler.getOyunKonumu() << endl
                        << yeniBilgiler.getFutbolcuÜcret() << endl
                        << yeniBilgiler.getFutbolcuDoğumT() << endl;

                    oyuncuBulundu = true;
                }
            }

            dosyaOku.close();
            tempDosya.close();

            if (oyuncuBulundu) {
                remove(dosyaAdi.c_str());
                rename(tempDosyaAdi.c_str(), dosyaAdi.c_str());
                cout << "Oyuncu başarıyla takımdan güncellendi." << endl;
                break;
            }
            else {
                remove(tempDosyaAdi.c_str());
            }
        }

        // Futbolcu.txt dosyasını güncelle
        ifstream futbolcuDosya("futbolcu.txt");
        ofstream tempFutbolcuDosya("temp_futbolcu.txt");

        if (!futbolcuDosya.is_open() || !tempFutbolcuDosya.is_open()) {
            cout << "futbolcu.txt dosyaları açılamadı!" << endl;
            return;
        }

        string satir;
        bool oyuncuBulundu = false;

        while (getline(futbolcuDosya, satir)) {
            if (satir.find(tcNo) == string::npos) {
                tempFutbolcuDosya << satir << endl;
            }
            else {

                tempFutbolcuDosya << yeniBilgiler.getTcNo() << endl
                    << yeniBilgiler.getFutbolcuAdı() << endl
                    << yeniBilgiler.getFutbolcuSoyadı() << endl
                    << yeniBilgiler.getLisansNo() << endl
                    << yeniBilgiler.getOyunKonumu() << endl
                    << yeniBilgiler.getFutbolcuÜcret() << endl
                    << yeniBilgiler.getFutbolcuDoğumT() << endl;

                oyuncuBulundu = true;
            }
        }

        futbolcuDosya.close();
        tempFutbolcuDosya.close();

        if (oyuncuBulundu) {
            remove("futbolcu.txt");
            rename("temp_futbolcu.txt", "futbolcu.txt");
            cout << "Oyuncu başarıyla futbolcu.txt'den güncellendi." << endl;
        }
        else {
            remove("temp_futbolcu.txt");
        }
    }
    void futbolculariListele() {
        ifstream futbolcuDosya("futbolcu.txt");

        if (!futbolcuDosya.is_open()) {
            cout << "futbolcu.txt dosyası açılamadı!" << endl;
            return;
        }

        string satir;
        while (getline(futbolcuDosya, satir)) {
            cout << satir << endl;
        }

        futbolcuDosya.close();
    }
};

class Takim {
private:
    int takımNumara;
    string takımAdı;
    string takımAdresi;
    string takımTelefon;
    int oyuncuSayı;
    string yoneticiİsim;
    vector<Futbolcu> futbolcular;

public:
    Takim() : takımNumara(), takımAdı(), takımAdresi(), takımTelefon(), oyuncuSayı(), yoneticiİsim() {}

    void takımbilgiGir() {
        do {
            cout << "Takım Numarasını giriniz. (Sadece sayı ve 1 ile 100 arasında olmalı)" << endl;
            if (!(cin >> takımNumara)) {
                cout << "Geçersiz giriş! Lütfen sadece sayısal bir değer girin." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (takımNumara < 1 || takımNumara > 100) {
                cout << "Takım numarası 1 ila 100 arasında olmalıdır!!" << endl;
            }
        } while (takımNumara < 1 || takımNumara > 100);

        cout << "Takım adını giriniz: ";
        cin >> takımAdı;

        cin.ignore();
        cout << "Takım Adresini giriniz." << endl;
        getline(cin, takımAdresi);

        cout << "Takımın telefon numarasını giriniz (Sadece sayı): ";
        cin >> takımTelefon;

        cout << "Takımın oyuncu sayısını giriniz (Sadece sayı): ";
        cin >> oyuncuSayı;

        cout << "Takımın yöneticisinin adını giriniz: ";
        cin >> yoneticiİsim;

    }

    void dosyayaYaz(ofstream& dosya) {
        dosya << setw(20) << "Takım Numarası: " << takımNumara << endl;
        dosya << setw(20) << "Takım Adı: " << takımAdı << endl;
        dosya << setw(20) << "Takım Adresi: " << takımAdresi << endl;
        dosya << setw(20) << "Takım Telefonu: " << takımTelefon << endl;
        dosya << setw(20) << "Oyuncu Sayısı: " << oyuncuSayı << endl;
        dosya << setw(20) << "Yönetici İsim: " << yoneticiİsim << endl << endl;
        dosya << "OYUNCULAR" << endl;
        dosya << "----------------------" << endl;
        for (const auto& futbolcu : futbolcular) {
            futbolcu.futbolcubilgiYaz(dosya);
        }
    }

    void oyuncuEkle(const Futbolcu& yeniOyuncu) {
        futbolcular.push_back(yeniOyuncu);
    }

    void takımBilgileriniGoster() const {
        cout << "Takım Numarası: " << takımNumara << endl;
        cout << "Takım Adı: " << takımAdı << endl;
        cout << "Takım Adresi: " << takımAdresi << endl;
        cout << "Takım Telefonu: " << takımTelefon << endl;
        cout << "Oyuncu Sayısı: " << oyuncuSayı << endl;
        cout << "Yönetici İsim: " << yoneticiİsim << endl;
        cout << "Oyuncular:" << endl;
        for (const auto& futbolcu : futbolcular) {
            cout << futbolcu.getFutbolcuAdı() << " " << futbolcu.getFutbolcuSoyadı() << endl;
        }
    }
    static void takimEkle() {
        Takim yeniTakim;
        yeniTakim.takımbilgiGir();
        string dosyaAdi = "takim_" + to_string(yeniTakim.takımNumara) + ".txt";

        bool dosyaVarMi = false; // Dosyanın zaten var olup olmadığını kontrol etmek için bir bayrak

        ifstream dosyaOku(dosyaAdi.c_str());
        if (dosyaOku.is_open()) {
            cout << "Bu takım numarasına sahip takım zaten mevcut. Varolan dosyadan okunacak." << endl;

            dosyaOku.close();
            dosyaVarMi = true; // Dosyanın zaten var olduğunu işaretleyelim
        }
        else {
            cout << "Yeni bir takım dosyası oluşturulacak: " << dosyaAdi << endl;
        }

        if (!dosyaVarMi) { // Dosya zaten varsa yeniden açmayalım
            ofstream dosyaYaz(dosyaAdi.c_str());
            if (dosyaYaz.is_open()) {
                yeniTakim.dosyayaYaz(dosyaYaz);
                dosyaYaz.close();
                cout << "Takım dosyası oluşturuldu veya güncellendi: " << dosyaAdi << endl;
            }
            else {
                cout << "Takım dosyası açılamadı veya oluşturulamadı!" << endl;
            }
        }
    }
    static void takimSil(int silTakımNo) {
        string dosyaAdi = "takim_" + to_string(silTakımNo) + ".txt";
        if (remove(dosyaAdi.c_str()) == 0) {
            cout << "Takım silindi." << endl;
        }
        else {
            cout << "Takım silinemedi veya bulunamadı!" << endl;
        }
    }

    void takimfutbolcuEkle(Futbolcu futbolcu) {
        string takimNumara;
        cout << "Futbolcu eklemek istediğiniz takım numarasını giriniz: ";
        cin >> takimNumara;

        string dosyaAdi = "takim_" + takimNumara + ".txt";
        ofstream takimDosya(dosyaAdi, ios::app);

        if (takimDosya.is_open()) {
            futbolcu.futbolcubilgiAL();
            futbolcu.futbolcubilgiYaz(takimDosya);
            futbolcular.push_back(futbolcu);

            // Futbolcu.txt dosyasına oyuncu bilgilerini ekle
            ofstream futbolcuDosya("Futbolcu.txt", ios::app);
            if (futbolcuDosya.is_open()) {
                futbolcu.futbolcubilgiYaz(futbolcuDosya);
                futbolcuDosya.close();
                cout << "Yeni futbolcu bilgileri 'Futbolcu.txt' dosyasına yazıldı." << endl;
            }
            else {
                cout << "Futbolcu.txt dosyası açılamadı veya oluşturulamadı!" << endl;
            }

            takimDosya.close();
        }
        else {
            cout << "Takım dosyası açılamadı veya oluşturulamadı!" << endl;
        }
    }

    void takimfutbolcuSil() {
        Futbolcu futbolcular;

        string silinecekTakımNo;
        cout << "Futbolcu bilgisini silmek istediğiniz takım numarasını giriniz: ";
        cin >> silinecekTakımNo;

        string dosyaAdi = "takim_" + silinecekTakımNo + ".txt";

        string silinecekFutbolcuTc;
        cout << "Silinecek futbolcunun TC kimlik numarasını giriniz: ";
        cin >> silinecekFutbolcuTc;

        ifstream dosyaOku(dosyaAdi);
        ofstream geciciDosya("gecici.txt");

        if (!dosyaOku || !geciciDosya) {
            cout << "Dosya açılamadı veya geçici dosya oluşturulamadı!" << endl;
            return;
        }

        string satir;
        bool bulundu = false;

        while (getline(dosyaOku, satir)) {
            if (satir.find(silinecekFutbolcuTc) != string::npos) {
                cout << "Oyuncu bilgileri silindi." << endl;
                bulundu = true;
                // İlgili TC'ye ait satırı atla ve diğer bilgileri sil
                for (int i = 0; i < 6; ++i) {
                    getline(dosyaOku, satir);
                }
            }
            else {
                geciciDosya << satir << endl;
            }
        }

        dosyaOku.close();
        geciciDosya.close();

        if (bulundu) {
            remove(dosyaAdi.c_str());
            rename("gecici.txt", dosyaAdi.c_str());

            // Vektörden de oyuncuyu sil
            auto it = find_if(Futbolcu::futbolcular.begin(), Futbolcu::futbolcular.end(), [&](const Futbolcu& futbolcu) {
                return futbolcu.getTcNo() == silinecekFutbolcuTc;
                });

            if (it != Futbolcu::futbolcular.end()) {
                Futbolcu::futbolcular.erase(it);
            }
        }
        else {
            remove("gecici.txt");
            cout << "TC kimlik numarasına sahip oyuncu bulunamadı." << endl;
        }
    }

    void takimfutbolcuGuncelle(int takimNumara, const string& guncellenecekTcNo) {

        bool oyuncuBulundu = false;
        Futbolcu yeniBilgiler;

        for (int i = 1; i <= 100; ++i) { // Varsayılan olarak 100 takım dosyası olduğunu varsayalım
            string takimDosyaAdi = "takim_" + to_string(i) + ".txt";
            ifstream takimDosyaOku(takimDosyaAdi);

            if (takimDosyaOku.is_open()) {
                string satir;
                while (getline(takimDosyaOku, satir)) {
                    if (satir.find(guncellenecekTcNo) != string::npos) {
                        cout << "Oyuncu bulundu. Lütfen yeni bilgileri giriniz:" << endl;


                        yeniBilgiler.futbolcubilgiAL();

                        takimDosyaOku.close();
                        ofstream tempTakimDosya("temp_takim.txt");
                        ifstream takimDosyaOku2(takimDosyaAdi);

                        if (tempTakimDosya.is_open() && takimDosyaOku2.is_open()) {
                            string takimSatir;
                            while (getline(takimDosyaOku2, takimSatir)) {
                                if (takimSatir.find(guncellenecekTcNo) != string::npos) {
                                    // Takım bilgilerini güncelle
                                    yeniBilgiler.futbolcubilgiYaz(tempTakimDosya);
                                }
                                else {

                                    tempTakimDosya << takimSatir << endl;
                                }
                            }
                            takimDosyaOku2.close();
                            tempTakimDosya.close();

                            remove(takimDosyaAdi.c_str());
                            rename("temp_takim.txt", takimDosyaAdi.c_str());

                            cout << "Takım bilgileri güncellendi." << endl;
                        }
                        else {
                            cout << "Takım dosyası açılamadı veya oluşturulamadı!" << endl;
                        }

                        oyuncuBulundu = true;
                        break;
                    }
                }
                takimDosyaOku.close();
            }

            if (oyuncuBulundu) {
                break;
            }
        }
        if (oyuncuBulundu) {

            // Futbolcu.txt dosyasını aç
            string futbolcuDosyaAdi = "Futbolcu.txt";
            ifstream futbolcuDosyaOku(futbolcuDosyaAdi);
            ofstream tempFutbolcuDosya("temp_futbolcu.txt");

            if (futbolcuDosyaOku.is_open() && tempFutbolcuDosya.is_open()) {
                string futbolcuSatir;
                while (getline(futbolcuDosyaOku, futbolcuSatir)) {
                    if (futbolcuSatir.find(guncellenecekTcNo) != string::npos) {
                        // TCNO'ya göre bulunan satırı atla (sil)
                        continue;
                    }
                    tempFutbolcuDosya << futbolcuSatir << endl;
                }
                futbolcuDosyaOku.close();
                tempFutbolcuDosya.close();

                remove(futbolcuDosyaAdi.c_str());
                rename("temp_futbolcu.txt", futbolcuDosyaAdi.c_str());

                // Yeni bilgileri Futbolcu.txt dosyasına ekle
                ofstream futbolcuDosyaEkle(futbolcuDosyaAdi, ios::app);
                if (futbolcuDosyaEkle.is_open()) {
                    yeniBilgiler.futbolcubilgiYaz(futbolcuDosyaEkle);
                    futbolcuDosyaEkle.close();
                }
                else {
                    cout << "Futbolcu dosyası açılamadı veya oluşturulamadı!" << endl;
                }

                cout << "Futbolcu bilgileri güncellendi." << endl;
            }
            else {
                cout << "Futbolcu dosyası açılamadı veya oluşturulamadı!" << endl;
            }
        }
        else {
            cout << "Oyuncu bulunamadı." << endl;
        }



    }



};
vector<Futbolcu> Futbolcu::futbolcular;
vector<string> tcOku(const string& dosyaAdi) {
    vector<string> futbolcuTCListesi;
    ifstream dosya(dosyaAdi);

    if (dosya.is_open()) {
        string tc;
        while (getline(dosya, tc)) {
            futbolcuTCListesi.push_back(tc);
        }
        dosya.close();
    }
    else {
        cout << "Dosya açma hatası!" << endl;
    }

    return futbolcuTCListesi;
}
static void takimDosyalariListele() {
    for (int i = 1; i <= 100; ++i) { // varsayılan takım sayısı için 1 ile 100 arası kontrol
        string dosyaAdi = "takim_" + to_string(i) + ".txt";
        ifstream dosya(dosyaAdi);

        if (dosya.is_open()) {
            string satir;
            cout << "Dosya Adı: " << dosyaAdi << endl;
            while (getline(dosya, satir)) {
                cout << satir << endl;
            }
            cout << "-----------------------------------------" << endl;
            dosya.close();
        }
        else {
            // Dosya açılamadıysa devam et
            continue;
        }
    }
}

void rastgeleSkorEkle(ofstream& maclarDosya, const vector<string>& futbolcuTCListesi) {
    srand(static_cast<unsigned int>(time(nullptr)));

    for (const string& tc : futbolcuTCListesi) {
        int skor = rand() % 6; // Rastgele skor oluşturuluyor
        maclarDosya << "TC: " << tc << " Skor: " << skor << endl;
    }
}


void macYaptir() {  //Burada maç.txt açar ve takım dosyaları içinden ilk satırı alır bu satıda takım numaraları vardır ve bu numaralar rastgele bir biçimde karştırıp yazırılır ve yanlarına rast gele biçimde skor oluşturulur
    ofstream maclarDosya("maclar.txt");

    if (!maclarDosya.is_open()) {
        cout << "Maç dosyası açılamadı veya oluşturulamadı!" << endl;
        return;
    }

    for (int i = 1; i <= 100; ++i) {//takım dosyalarından takım numarası çekme işlemi
        string takimDosyaAdi1 = "takim_" + to_string(i) + ".txt";

        ifstream takimDosya1(takimDosyaAdi1);
        if (!takimDosya1.is_open()) {
            continue;
        }

        string satir1;
        getline(takimDosya1, satir1);

        for (int j = i + 1; j <= 100; ++j) { //takım dosyalarından takım numarası çekme işlemi
            string takimDosyaAdi2 = "takim_" + to_string(j) + ".txt";

            ifstream takimDosya2(takimDosyaAdi2);
            if (!takimDosya2.is_open()) {
                continue;
            }

            string satir2;
            getline(takimDosya2, satir2);

            int skor1 = rand() % 6; // Rastgele skorlar oluştur (0-5 arası)
            int skor2 = rand() % 6;

            maclarDosya << satir1 << "  vs  " << satir2 << " Skorlar: " << skor1 << "-" << skor2 << " " << endl;


        }

        takimDosya1.close();
    }

    maclarDosya.close();
    cout << "Maçlar oluşturuldu ve 'maclar.txt' dosyasına yazıldı." << endl;
}


void oyuncuMenu() {
    int secim;
    Futbolcu futbolcu;

    do {
        cout << "OYUNCU MENU" << endl;
        cout << "1. Yeni Futbolcu Ekle" << endl;
        cout << "2. Futbolcu Sil" << endl;
        cout << "3. Futbolcu Güncelle" << endl;
        cout << "4. Futbolcuları Listele" << endl;
        cout << "0. Ana Menu" << endl;
        cout << "Seciminizi girin: ";
        cin >> secim;

        switch (secim) {
        case 1:
            futbolcu.futbolcuEkleDosya();
            break;
        case 2:
        {
            string silinecektcNo;
            cout << "Silinicek oyunucun TC numarasını giriniz." << endl;
            cin >> silinecektcNo;
            futbolcu.futbolcuSil(silinecektcNo);
        }
        break;
        case 3: {
            string güncellenecektcNo;
            cout << "Silinicek oyunucun TC numarasını giriniz." << endl;
            cin >> güncellenecektcNo;
            futbolcu.futbolcuGuncelle(güncellenecektcNo);
        }
        case 4:
            futbolcu.futbolculariListele();
            break;
        case 0:
            cout << "Ana Menu'ye donuluyor." << endl;
            break;
        default:
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
            break;
        }
    } while (secim != 0);
}

void takimMenu() {
    int secim;
    Takim yeniTakim;
    Futbolcu yeniFutbolcu;
    do {
        cout << "TAKIM MENU" << endl;
        cout << "1. Takim Olustur" << endl;
        cout << "2. Takim Sil" << endl;
        cout << "3. Takimları Listele" << endl;
        cout << "4. Takima Futbolcu Ekle" << endl;
        cout << "5. Takimdan Futbolcu Sil" << endl;
        cout << "6. Takima Futbolcu Guncelle" << endl;
        cout << "0. Ana Menu" << endl;
        cout << "Seciminizi girin: ";
        cin >> secim;

        switch (secim) {
        case 1:
            yeniTakim.takimEkle();
            break;
        case 2: {
            int silicenektakımNo;
            cout << "Silinecek takım numarasını giriniz." << endl;
            cin >> silicenektakımNo;
            yeniTakim.takimSil(silicenektakımNo);
        }
              break;
        case 3:
            takimDosyalariListele();
            break;
        case 4:
            yeniTakim.takimfutbolcuEkle(yeniFutbolcu);
            break;
        case 5:
            yeniTakim.takimfutbolcuSil();
            break;
        case 6: {
            int takimNumara;
            string futbolcuTc;
            cout << "Güncellenecek futbolcunun olduğu takim numaraısnı giriniz." << endl;
            cin >> takimNumara;
            cout << "Güncellencek futbolcunun TC kimlik numarasını giriniz." << endl;
            cin >> futbolcuTc;
            yeniTakim.takimfutbolcuGuncelle(takimNumara, futbolcuTc);
        }
              break;
        case 0:
            cout << "Ana Menu'ye donuluyor." << endl;
            break;
        default:
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
            break;
        }
    } while (secim != 0);
}
void ekranaYazdır() {

    int secim;

    do {
        cout << "ANA MENU" << endl;
        cout << "1. Oyuncu Menusu" << endl;
        cout << "2. Takim Menusu" << endl;
        cout << "3. Mac Yaptir" << endl;
        cout << "0. Cikis" << endl;
        cout << "Seciminizi girin: ";
        cin >> secim;

        switch (secim) {
        case 1:
            oyuncuMenu();
            break;
        case 2:
            takimMenu();
            break;
        case 3:
            macYaptir();
            break;
        case 0:
            cout << "Programdan cikiliyor." << endl;
            break;
        default:
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
            break;
        }
    } while (secim != 0);

    return;
}

int main() {
    setlocale(LC_ALL, "turkish");
    ekranaYazdır();

}