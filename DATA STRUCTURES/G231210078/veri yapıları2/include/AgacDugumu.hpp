/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/


#ifndef AGACDUGUMU_HPP
#define AGACDUGUMU_HPP


class AgacDugumu {
public:
    char veri;
    AgacDugumu* sol;
    AgacDugumu* sag;

    AgacDugumu(char veri) : veri(veri), sol(nullptr), sag(nullptr) {}
};

#endif // AGACDUGUMU_HPP
