/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include "AgacDugumu.hpp"
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;


class IkiliAramaAgaci {
public:
    AgacDugumu* kok;
 
    static constexpr int YUKSEKLIK = 50; // Sabitlerin derleme zamanında belirlenmesi için
    static constexpr int GENISLIK = 80;  // Aynı şekilde



    IkiliAramaAgaci() : kok(nullptr) {}
    
    void ekle(char veri);
    void agaciSil(AgacDugumu* dugum);
    void ekraniTemizle(char ekran[YUKSEKLIK][GENISLIK]);
    void ekraniYazdir(char ekran[YUKSEKLIK][GENISLIK]);
    void dalEkle(char ekran[YUKSEKLIK][GENISLIK], int satir, int solSutun, int sagSutun);
    int agacYuksekligi(AgacDugumu* kok);
    void agaciCiz(AgacDugumu* kok, char ekran[YUKSEKLIK][GENISLIK], int satir, int sutun, int bosluk, int yukseklik, int seviye);
    void cizVeYazdir();
    int levelOrderToplam();
    void agaciAynala(AgacDugumu* kok);

   
};

#endif // IKILIARAMAAGACI_HPP
