/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/
#include "IkiliAramaAgaci.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void IkiliAramaAgaci::ekle(char veri) {
    AgacDugumu** current = &kok;
    while (*current != nullptr) {
        if (veri < (*current)->veri)
            current = &((*current)->sol);
        else
            current = &((*current)->sag);
    }
    *current = new AgacDugumu(veri);
}



// Ekranı temizler
void IkiliAramaAgaci::ekraniTemizle(char ekran[YUKSEKLIK][GENISLIK]) {
    for (int i = 0; i < YUKSEKLIK; i++) {
        for (int j = 0; j < GENISLIK; j++) {
            ekran[i][j] = ' ';
        }
    }
}

// Ekranı yazdırır
void IkiliAramaAgaci::ekraniYazdir(char ekran[YUKSEKLIK][GENISLIK]) {
    for (int i = 0; i < YUKSEKLIK; i++) {
        for (int j = 0; j < GENISLIK; j++) {
            cout << ekran[i][j];
        }
        cout << endl;
    }
}

// Sol ve sağ dal arasında yatay çizgi çizer
void IkiliAramaAgaci::dalEkle(char ekran[YUKSEKLIK][GENISLIK], int satir, int solSutun, int sagSutun) {
    for (int sutun = min(solSutun, sagSutun); sutun <= max(solSutun, sagSutun); sutun++) {
        if (sutun >= 0 && sutun < GENISLIK && satir >= 0 && satir < YUKSEKLIK) {
            ekran[satir][sutun] = '*';
        }
    }
}

// Ağacın yüksekliğini hesaplar
int IkiliAramaAgaci::agacYuksekligi(AgacDugumu* kok) {
    if (kok == nullptr) {
        return 0;
    }
    return 1 + max(agacYuksekligi(kok->sol), agacYuksekligi(kok->sag));
}

// Ağacı çizdirir
void IkiliAramaAgaci::agaciCiz(AgacDugumu* kok, char ekran[YUKSEKLIK][GENISLIK], int satir, int sutun, int bosluk, int yukseklik, int seviye) {
     if (kok == nullptr || satir >= YUKSEKLIK || sutun >= GENISLIK || sutun < 0) {
        return;
    }

    ekran[satir][sutun] = kok->veri;

    // Karakterin üst kısmına * ekleyelim
    if (satir > 0 && sutun >= 0 && sutun < GENISLIK) {
        ekran[satir - 2][sutun] = '*'; // Üst satıra * ekleyelim
    }

    // Seviye sayacını kontrol et
    if (seviye > 3) {
        // 4. seviyeden sonra boşlukları sabitle
        int sabitBosluk = 2;

        // Sol dalın çizilmesi
        if (kok->sol != nullptr) {
            int yeniSutun = sutun - sabitBosluk;
            dalEkle(ekran, satir + 1, yeniSutun, sutun); // Yatay dal
            agaciCiz(kok->sol, ekran, satir + 4, yeniSutun, sabitBosluk, yukseklik, seviye + 1);
        }

        // Sağ dalın çizilmesi
        if (kok->sag != nullptr) {
            int yeniSutun = sutun + sabitBosluk;
            dalEkle(ekran, satir + 1, sutun, yeniSutun); // Yatay dal
            agaciCiz(kok->sag, ekran, satir + 4, yeniSutun, sabitBosluk, yukseklik, seviye + 1);
        }
    } else {
        // Ağacın yüksekliği 4'ten küçükse, boşluk değerini hesaplayarak çizme
        // Sol dalın çizilmesi
        if (kok->sol != nullptr) {
            int yeniSutun = sutun - bosluk;
            dalEkle(ekran, satir + 1, yeniSutun, sutun); // Yatay dal
            agaciCiz(kok->sol, ekran, satir + 4, yeniSutun, bosluk / 2, yukseklik, seviye + 1);
        }

        // Sağ dalın çizilmesi
        if (kok->sag != nullptr) {
            int yeniSutun = sutun + bosluk;
            dalEkle(ekran, satir + 1, sutun, yeniSutun); // Yatay dal
            agaciCiz(kok->sag, ekran, satir + 4, yeniSutun, bosluk / 2, yukseklik, seviye + 1);
        }
    }
}

// Ağacı çizdirip ekrana yazdırır
void IkiliAramaAgaci::cizVeYazdir() {
    int yukseklik = agacYuksekligi(kok);  // Ağacın yüksekliğini hesapla
    int bosluk = GENISLIK / (1 << yukseklik);  // Yüksekliğe göre boşluk ayarlama
    char ekran[YUKSEKLIK][GENISLIK];
    ekraniTemizle(ekran);
    agaciCiz(kok, ekran, 0, GENISLIK / 2, GENISLIK / 4, yukseklik,0);
    ekraniYazdir(ekran);
}

int IkiliAramaAgaci::levelOrderToplam() {
    if (!kok) return 0;

    int sol_toplam = 0;
    int sag_toplam = 0;

    queue<AgacDugumu*> kuyruk;
    kuyruk.push(kok);

    while (!kuyruk.empty()) {
        AgacDugumu* dugum = kuyruk.front();
        kuyruk.pop();

        if (dugum->sol) {
            sol_toplam += dugum->sol->veri;
            kuyruk.push(dugum->sol);
        }
        if (dugum->sag) {
            sag_toplam += dugum->sag->veri;
            kuyruk.push(dugum->sag);
        }
    }
    

    return 2 * sol_toplam + sag_toplam + kok->veri;
}

void IkiliAramaAgaci::agaciAynala(AgacDugumu* kok) {
    if (kok == nullptr) return;

    // Sol ve sağ çocukları yer değiştir
    AgacDugumu* temp = kok->sol;
    kok->sol = kok->sag;
    kok->sag = temp;

    // Alt ağaçları aynala
    agaciAynala(kok->sol);
    agaciAynala(kok->sag);
}


