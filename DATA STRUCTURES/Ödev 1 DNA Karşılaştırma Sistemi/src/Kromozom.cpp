/**       
* @file           : G231210078
* @description    : C++ dilinde DNA kromozom ve genler üzerinde çaprazlama mutasyon gibi işlemler yapan program.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 1
* @date           : 12.11.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#include "Kromozom.h"
#include <iostream>

Kromozom::Kromozom() : ilk(nullptr), son(nullptr), sonraki(nullptr), onceki(nullptr) {}

Kromozom::~Kromozom() {
    Gen* gecici = ilk;
    while (gecici != nullptr) {
        Gen* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}

void Kromozom::genEkle(char veri) {
    Gen* yeniGen = new Gen(veri);
    if (ilk == nullptr) {
        ilk = son = yeniGen;
    } else {
        son->sonraki = yeniGen;
        yeniGen->onceki = son;
        son = yeniGen;
    }
}

void Kromozom::yazdir() {
    Gen* gecici = ilk;
    while (gecici != nullptr) {
        std::cout << gecici->veri << " ";
        gecici = gecici->sonraki;
    }
    std::cout << std::endl;
}
