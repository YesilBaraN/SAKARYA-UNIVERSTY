/**       
* @file           : G231210078
* @description    : C++ dilinde DNA kromozom ve genler üzerinde çaprazlama mutasyon gibi işlemler yapan program.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 1
* @date           : 12.11.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#include "DNA.h"
#include <iostream>
#include <cmath> 

DNA::DNA() : ilk(nullptr), son(nullptr) {}

DNA::~DNA() {
    Kromozom* gecici = ilk;
    while (gecici != nullptr) {
        Kromozom* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}
void DNA::dosyadanOku(const std::string& dosyaAdi) {
       std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        std::cerr << "Hata: Dosya acilamadi!" << std::endl;
        return;
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        // Eğer satır boşsa, atla
        if (satir.empty()) continue;

        std::istringstream satirStream(satir);
        char gen;
        Kromozom* yeniKromozom = new Kromozom();

        // Satırdaki her bir geni oku ve kromozoma ekle
        while (satirStream >> gen) {
            yeniKromozom->genEkle(gen);
        }

        // Kromozomu DNA'ya ekle
        kromozomEkle(yeniKromozom);
    }

    dosya.close();
}

void DNA::kromozomEkle(Kromozom* yeniKromozom) {
    if (ilk == nullptr) {
        ilk = son = yeniKromozom;
    } else {
        son->sonraki = yeniKromozom;
        yeniKromozom->onceki = son;
        son = yeniKromozom;
    }
}

void DNA::yazdir() {
     Kromozom* gecici = ilk; // İlk kromozomdan başla

    while (gecici != nullptr) {
        Gen* genGecici = gecici->son; // Sağdan (sondan) başla
        char enKucukGen = gecici->ilk->veri; // Varsayılan olarak ilk geni en küçük kabul et
        char secilenGen = enKucukGen;       // Yazdırılacak gen

        while (genGecici != nullptr) {
            if (genGecici->veri < enKucukGen) {
                secilenGen = genGecici->veri; // Daha küçük bir gen bulundu
                break; // İşlem tamam, bu kromozom için başka genlere bakma
            }
            genGecici = genGecici->onceki; // Geriye doğru ilerle
        }

        // Seçilen geni yazdır
        std::cout << secilenGen << " ";

        // Sonraki kromozoma geç
        gecici = gecici->sonraki;
    }

    // Yeni bir satır ekle
    std::cout << std::endl;
}

void DNA::mutasyon(int kromozomIndex, int genIndex) {
    // Kromozomu bul
    Kromozom* kromozom = ilk; // Başlangıçta ilk kromozomu al
    int sayac = 0;

    // Kromozomu belirtilen index'e kadar ilerle
    while (sayac < kromozomIndex && kromozom != nullptr) {
        kromozom = kromozom->sonraki;
        sayac++;
    }

    // Eğer kromozom bulunamazsa, hata mesajı ver ve çık
    if (kromozom == nullptr) {
        std::cerr << "Hata: Geçersiz kromozom indexi!" << std::endl;
        return;
    }

    // Genleri kontrol et, ilk gen üzerinden başla
    Gen* gen = kromozom->ilk; // Kromozomun ilk genine başla
    sayac = 0;

    // İlgili gen indexine kadar ilerle
    while (sayac < genIndex && gen != nullptr) {
        gen = gen->sonraki; // Bir sonraki gene geç
        sayac++;
    }

    // Eğer gen bulunamazsa, hata mesajı ver ve çık
    if (gen == nullptr) {
        std::cerr << "Hata: Geçersiz gen indexi!" << std::endl;
        return;
    }

    // Seçilen geni 'X' ile değiştir
    gen->veri = 'X'; // 'veri' burada genin harf değerini temsil eder

    
}


void DNA::caprazlama(int index1, int index2) {
    // Kromozomları bul
    Kromozom* kromozom1 = ilk;
    Kromozom* kromozom2 = ilk;
    for (int i = 0; i < index1 && kromozom1 != nullptr; i++) {
        kromozom1 = kromozom1->sonraki;
    }
    for (int i = 0; i < index2 && kromozom2 != nullptr; i++) {
        kromozom2 = kromozom2->sonraki;
    }

    if (!kromozom1 || !kromozom2) {
        std::cerr << "Hata: Geçersiz indeks!" << std::endl;
        return;
    }

    // Gen sayısını bul
    int genSayisi1 = 0, genSayisi2 = 0;
    Gen* temp = kromozom1->ilk;
    while (temp != nullptr) {
        genSayisi1++;
        temp = temp->sonraki;
    }
    temp = kromozom2->ilk;
    while (temp != nullptr) {
        genSayisi2++;
        temp = temp->sonraki;
    }

    // Ortayı bul
    int solOrta1 = genSayisi1 / 2; // Sol kısım için sınır
    int sagOrta1 = (genSayisi1 % 2 == 0) ? solOrta1 : solOrta1 + 1; // Sağ kısım için başlangıç

    int solOrta2 = genSayisi2 / 2;
    int sagOrta2 = (genSayisi2 % 2 == 0) ? solOrta2 : solOrta2 + 1;

    // Geçici kromozomlar oluştur
    Kromozom* solKromozom1 = new Kromozom();
    Kromozom* sagKromozom1 = new Kromozom();
    Kromozom* solKromozom2 = new Kromozom();
    Kromozom* sagKromozom2 = new Kromozom();

    // Kromozom1'in sol ve sağ parçalarını ayır
    temp = kromozom1->ilk;
    for (int i = 0; i < solOrta1; i++) {
        solKromozom1->genEkle(temp->veri);
        temp = temp->sonraki;
    }
    if (genSayisi1 % 2 != 0) temp = temp->sonraki; // Ortadaki geni atla
    while (temp != nullptr) {
        sagKromozom1->genEkle(temp->veri);
        temp = temp->sonraki;
    }

    // Kromozom2'nin sol ve sağ parçalarını ayır
    temp = kromozom2->ilk;
    for (int i = 0; i < solOrta2; i++) {
        solKromozom2->genEkle(temp->veri);
        temp = temp->sonraki;
    }
    if (genSayisi2 % 2 != 0) temp = temp->sonraki; // Ortadaki geni atla
    while (temp != nullptr) {
        sagKromozom2->genEkle(temp->veri);
        temp = temp->sonraki;
    }

    // Yeni kromozomlar oluştur
    Kromozom* yeniKromozom1 = new Kromozom();
    Kromozom* yeniKromozom2 = new Kromozom();

    // 1. yeni kromozom: sol1 + sag2
    temp = solKromozom1->ilk;
    while (temp != nullptr) {
        yeniKromozom1->genEkle(temp->veri);
        temp = temp->sonraki;
    }
    temp = sagKromozom2->ilk;
    while (temp != nullptr) {
        yeniKromozom1->genEkle(temp->veri);
        temp = temp->sonraki;
    }

    // 2. yeni kromozom: sag1 + sol2
    temp = sagKromozom1->ilk;
    while (temp != nullptr) {
        yeniKromozom2->genEkle(temp->veri);
        temp = temp->sonraki;
    }
    temp = solKromozom2->ilk;
    while (temp != nullptr) {
        yeniKromozom2->genEkle(temp->veri);
        temp = temp->sonraki;
    }

    // Yeni kromozomları listeye ekle
    kromozomEkle(yeniKromozom1);
    kromozomEkle(yeniKromozom2);

    // Geçici kromozomları sil
    delete solKromozom1;
    delete sagKromozom1;
    delete solKromozom2;
    delete sagKromozom2;
}


void DNA::otomatikIslemler(const std::string& dosyaAdi) {
    std::ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        std::cerr << "Hata: Dosya açılamadı!\n";
        return;
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        // Satırdan harfi ve sayıları ayrıştır
        char islemTuru;
        int index1, index2;

        std::istringstream iss(satir);
        if (!(iss >> islemTuru >> index1 >> index2)) {
            std::cerr << "Hata: Geçersiz satır formatı: " << satir << "\n";
            continue;
        }

        // İşleme göre uygun fonksiyonu çağır
        if (islemTuru == 'C') {
            caprazlama(index1, index2);
        } else if (islemTuru == 'M') {
            mutasyon(index1, index2); // Varsayılan bir mutasyon fonksiyonu
        } else {
            std::cerr << "Hata: Tanınmayan işlem türü: " << islemTuru << "\n";
        }
    }

    dosya.close();
    
}
