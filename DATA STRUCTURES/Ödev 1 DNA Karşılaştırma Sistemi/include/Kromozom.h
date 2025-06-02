/**       
* @file           : G231210078
* @description    : C++ dilinde DNA kromozom ve genler üzerinde çaprazlama mutasyon gibi işlemler yapan program.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 1
* @date           : 12.11.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#ifndef KROMOZOM_H
#define KROMOZOM_H

#include "Gen.h"


class Kromozom {
public:
   
    Gen* ilk; // İlk gene işaretçi
    Gen* son; // Son gene işaretçi
    Kromozom* sonraki; // Sonraki kromozoma işaretçi
    Kromozom* onceki;  // Önceki kromozoma işaretçi

    Kromozom();              // Yapıcı
    ~Kromozom();             // Yıkıcı
    void genEkle(char veri); // Kromozoma gen ekle
    void yazdir();           // Kromozomu yazdır
};

#endif
