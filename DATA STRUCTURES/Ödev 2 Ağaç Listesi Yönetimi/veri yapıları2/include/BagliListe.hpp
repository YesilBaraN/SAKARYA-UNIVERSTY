/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include "BagliListeDugumu.hpp"
#include <iostream>
#include <string>

class BagliListe {
public:
    BagliListeDugumu* bas;
    BagliListeDugumu* secilenDugum;
    int secilenIndex; // Seçili düğümün indeksi
    int pageIndex;     // Hangi sayfanın gösterildiğini tutar


    BagliListe() : bas(nullptr) {}
    ~BagliListe();

    void ekle(IkiliAramaAgaci* agac);
    void yazdir(); // Düğümleri ve altındaki işareti yazdırır
    void solaGit(); // `A` için: bir önceki düğüme geç
    void sagaGit(); // `D` için: bir sonraki düğüme geç
    void sil();        // Seçilen düğümü sil
    void secilenAgaciCizVeYazdir();
    void secilenAgaciAynala();
   
};

#endif // BAGLILISTE_HPP
