/**       
* @file           : G231210078
* @description    : C++ dilinde DNA kromozom ve genler üzerinde çaprazlama mutasyon gibi işlemler yapan program.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 1
* @date           : 12.11.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#ifndef GEN_H
#define GEN_H

class Gen {
public:
    char veri; // Genin içeriği (örneğin A, T, G, C)
    Gen* sonraki; // Sonraki gene işaretçi
    Gen* onceki;  // Önceki gene işaretçi

    Gen(char veri); // Yapıcı
};

#endif
