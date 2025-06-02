/**       
* @file           : G231210078
* @description    : C++ dilinde bir dosyanın her satırından ikili arama ağaçları oluşturup bu ağaçları bir bağlı listeyle bağlayarak, kullanıcı etkileşimli bir sistem geliştirmektir.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 2. ÖDEV
* @date           : 18.12.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/
#include "IkiliAramaAgaci.hpp"
#include "BagliListe.hpp"
#include <conio.h> // _getch için gerekli
#include <string>
#include <fstream>
#include <cstring>

using namespace std;


int main() {   
    ifstream dosya("Agaclar.txt");

    if (!dosya.is_open()) {
        cerr << "Agaclar.txt dosyasi acilamadi." << endl;
        return 1;
    }

    BagliListe liste; // Bagli liste olustur
    string satir;

    while (getline(dosya, satir)) {
        if (!satir.empty()) {
            // Yeni bir agac olustur
            IkiliAramaAgaci* yeniAgac = new IkiliAramaAgaci();
            for (char c : satir) {
                yeniAgac->ekle(c);
            }

            // Agaci bagli listeye ekle
            liste.ekle(yeniAgac);
        }
    }

    liste.secilenIndex = 0; // Indeksi baslangicta sifirla
    liste.pageIndex = 0;
    
    // Kullanici giris dongusu
    char komut;
    do {
        system("cls"); // Konsolu temizle

        // Listeyi yazdir
        liste.yazdir();

        // Secili agaci yazdir
        std::cout << "\nSecili Agacin Cizimi:\n";
        liste.secilenAgaciCizVeYazdir();

        // Ek bilgi yazdir
        std::cout << "\nBulundugunuz Dugum Indeksi: " << liste.secilenIndex << "\n";
        std::cout << "Sayfa: " << liste.pageIndex << "\n";

        // Kullanicidan komut al
        std::cout << "Komut girin (A: sola, D: saga, S: sil, W: aynala, x: cik): ";
        komut = _getch();

        // Komutlara gore islem yap
        if (komut == 'A' || komut == 'a') {
            liste.solaGit();
        } else if (komut == 'D' || komut == 'd') {
            liste.sagaGit();
        } else if (komut == 'S' || komut == 's') {
            liste.sil();
        } else if (komut == 'W' || komut == 'w') {
               liste.secilenAgaciAynala(); 
        }
    } while (komut != 'X' && komut != 'x'); 

    dosya.close();
    return 0;
}

