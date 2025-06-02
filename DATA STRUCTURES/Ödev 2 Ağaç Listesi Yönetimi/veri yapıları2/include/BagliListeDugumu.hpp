/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#ifndef BAGLILISTEDUGUMU_HPP
#define BAGLILISTEDUGUMU_HPP

#include "IkiliAramaAgaci.hpp"


class BagliListeDugumu {
public:
    IkiliAramaAgaci* agac;
    int toplamDeger;
    BagliListeDugumu* sonraki;

    BagliListeDugumu(IkiliAramaAgaci* agac, int toplamDeger)
        : agac(agac), toplamDeger(toplamDeger), sonraki(nullptr) {}
    ~BagliListeDugumu() {
        // Agac pointer'ı dinamik olarak tahsis edildiği için burada delete edilmelidir
        delete agac;
    }
};

#endif // BAGLILISTEDUGUMU_HPP
