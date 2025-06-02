/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>



BagliListe::~BagliListe() {
   
}

void BagliListe::ekle(IkiliAramaAgaci* agac) {
   BagliListeDugumu* yeniDugum = new BagliListeDugumu(agac, agac->levelOrderToplam());

    if (bas == nullptr) {
        // Liste boşsa, yeni düğümü baş olarak ayarla
        bas = yeniDugum;
    } else {
        // Listenin sonuna git ve yeni düğümü ekle
        BagliListeDugumu* gecici = bas;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
    }
}

void BagliListe::yazdir() {
      BagliListeDugumu* dugum = bas;
    int sayac = 0;
    int baslangic = pageIndex * 10; // Sayfanın ilk düğümü
    int bitis = baslangic + 10;     // Sayfanın son düğümü

    // Yazdırma için string stream
    std::stringstream ustCizgi;
    std::stringstream adresSatiri;
    std::stringstream toplamDegerSatiri;
    std::stringstream sonrakiAdresSatiri;
    std::stringstream altIsaret;  // Ok başı
    std::stringstream altCizgi;   // Ok gövdesi

    while (dugum) {
        // Yalnızca sayfa aralığındaki düğümleri göster
        if (sayac >= baslangic && sayac < bitis) {
            // Ortak üst çizgi
            ustCizgi << "+************+   ";

            // Adres bilgisi
            adresSatiri << "| " << std::setw(10) << dugum << " |   ";

            // Toplam değer bilgisi
            toplamDegerSatiri << "| " << std::setw(10) << dugum->toplamDeger << " |   ";

            // Sonraki düğüm adresi bilgisi
            sonrakiAdresSatiri << "| " << std::setw(10)
                               << (dugum->sonraki ? dugum->sonraki : 0) << " |   ";

            // Alt işaret satırı (ok başı ve gövde)
            if (sayac == secilenIndex) {
                altIsaret << " ^^^^^^^^^^^^   ";
                altCizgi <<  " ||||||||||||   ";
            } else {
                altIsaret << "                 "; // Diğer düğümler için boş bırak
                altCizgi <<  "                 "; // Diğer düğümler için boş bırak
            }
        }

        dugum = dugum->sonraki;
        sayac++;
    }

    // Tüm satırları ekrana yazdır
    std::cout << ustCizgi.str() << "\n"
              << adresSatiri.str() << "\n"
              << ustCizgi.str() << "\n"
              << toplamDegerSatiri.str() << "\n"
              << ustCizgi.str() << "\n"
              << sonrakiAdresSatiri.str() << "\n"
              << ustCizgi.str() << "\n"
              << altIsaret.str() << "\n"
              << altCizgi.str() << "\n"; // Alt çizgi satırını yazdır
}

void BagliListe::solaGit() {
     if (secilenIndex > 0) {
        secilenIndex--; // Bir önceki düğüme geç
        if (secilenIndex < pageIndex * 10) {
            pageIndex--; // Önceki sayfaya geç
        }
    }
}

void BagliListe::sagaGit() {
   BagliListeDugumu* dugum = bas;
    int maxIndex = 0;

    // Maksimum indeks değerini bulmak için tüm listeyi dolaş
    while (dugum) {
        dugum = dugum->sonraki;
        maxIndex++;
    }

    if (secilenIndex < maxIndex - 1) {
        secilenIndex++; // Bir sonraki düğüme geç
        if (secilenIndex >= (pageIndex + 1) * 10) {
            pageIndex++; // Sonraki sayfaya geç
        }
    }
}

void BagliListe::sil() {
    if (!bas) {
        std::cout << "Liste zaten boş.\n";
        return;
    }

    BagliListeDugumu* onceki = nullptr;
    BagliListeDugumu* dugum = bas;

    // İlgili düğümü bul
    for (int i = 0; i < secilenIndex && dugum; ++i) {
        onceki = dugum;
        dugum = dugum->sonraki;
    }

    if (!dugum) {
        std::cout << "Hatalı index. Silinecek düğüm bulunamadı.\n";
        return;
    }

    // Bağlantıları güncelle
    if (onceki) {
        onceki->sonraki = dugum->sonraki;
    } else {
        bas = dugum->sonraki; // İlk düğüm siliniyorsa
    }

    // Belleği serbest bırak
    delete dugum->agac;
    delete dugum;

    // İndeksi güncelle
    if (secilenIndex > 0) {
        secilenIndex--;
    }

    // Sayfa kontrolü
    int toplamDugum = 0;
    BagliListeDugumu* tmp = bas;
    while (tmp) {
        toplamDugum++;
        tmp = tmp->sonraki;
    }

    pageIndex = secilenIndex / 10;

    if (!bas) {
        std::cout << "Tüm düğümler silindi. Liste boş.\n";
    }
}

void BagliListe::secilenAgaciCizVeYazdir() {
    BagliListeDugumu* gecici = bas;
    int index = 0;

    // Seçilen düğüme git
    while (gecici != nullptr) {
        if (index == secilenIndex) {
           
            gecici->agac->cizVeYazdir(); // Ağacı çiz ve yazdır
            return;
        }
        gecici = gecici->sonraki;
        index++;
    }

    std::cout << "Secilen dugum bulunamadi.\n";
}

void BagliListe::secilenAgaciAynala() {
    BagliListeDugumu* gecici = bas;
    int index = 0;

    // Seçilen düğümü bul
    while (gecici != nullptr) {
        if (index == secilenIndex) {
            std::cout << "Seçilen düğümün ağacı aynalanıyor...\n";
            gecici->agac->agaciAynala(gecici->agac->kok); // Ağacı yerinde aynala
            gecici->toplamDeger = gecici->agac->levelOrderToplam();
            return;
        }
        gecici = gecici->sonraki;
        index++;
    }

    std::cout << "Seçilen düğüm bulunamadı.\n";
}


