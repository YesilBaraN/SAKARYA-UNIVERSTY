/**       
* @file           : G231210078
* @description    : C++ dilinde DNA kromozom ve genler üzerinde çaprazlama mutasyon gibi işlemler yapan program.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 1
* @date           : 12.11.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#ifndef DNA_H
#define DNA_H
#include <string>
#include <fstream>  // Dosya işlemleri için
#include <sstream>  // Satır işlemleri için
#include "Kromozom.h"
#include"Gen.h"
class DNA {
public:
    Kromozom* ilk; // İlk kromozoma işaretçi
    Kromozom* son; // Son kromozoma işaretçi

    DNA();               // Yapıcı
    ~DNA();              // Yıkıcı
    void kromozomEkle(Kromozom* yeniKromozom); // Kromozom ekle
    void yazdir();  
    void caprazlama(int index1, int index2); // Çaprazlama fonksiyonu
    void dosyadanOku(const std::string& dosyaAdi); // Dosyadan okuma fonksiyonu
    void mutasyon(int kromozomIndex, int genIndex) ;
    void otomatikIslemler(const std::string& dosyaAdi);
};

#endif

