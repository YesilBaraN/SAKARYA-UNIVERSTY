/**       
* @file           : G231210078
* @description    : C++ dilinde DNA kromozom ve genler üzerinde çaprazlama mutasyon gibi işlemler yapan program.
* @course         : 2. ÖĞRETİM C grubu
* @assignment     : 1
* @date           : 12.11.2024          
* @author         : Baran Yeşilyurt baran.yesilyurt@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <string>
#include "DNA.h"

using namespace std;

bool isNumber(const string& str) {
    // Eğer string boşsa veya boşluk varsa geçerli değil
    if (str.empty() || str.find_first_not_of("0123456789") != string::npos) {
        return false;
    }
    return true;
}

void menu() {
    DNA dna;
    int islem = 0;
    dna.dosyadanOku("Dna.txt");

    do {
        cout << "********** MENU **********" << endl;
        cout << "1. Caprazlama" << endl;
        cout << "2. Mutasyon" << endl;
        cout << "3. Otomatik Islemler" << endl;
        cout << "4. Ekrana Yazdir" << endl;
        cout << "5. Cikis" << endl;
        cout << "Seciminizi girin: ";

        string input;
        cin >> input;

        // Sayı kontrolü: Eğer input sayıya dönüştürülebiliyorsa işlemi yap
        if (!isNumber(input)) {
            cout << "Gecersiz bir giris yaptiniz. Lutfen bir sayi giriniz." << endl;
            continue; // Döngüye devam et
        }

        islem = stoi(input); // String'i int'e dönüştür

        switch (islem) {
            case 1: {
                int index1, index2;
                cout << "Caprazlama islemi icin 1. kromozom satirini girin: ";
                cin >> index1;
                cout << "Caprazlama islemi icin 2. kromozom satirini girin: ";
                cin >> index2;
                dna.caprazlama(index1, index2);
                cout << "Caprazlama tamamlandi. Yeni kromozomlar eklendi.\n";
                break;
            }
            case 2: {
                int kromozomIndex, genIndex;
                cout << "Mutasyon islemi icin kromozom satirini giriniz:";
                cin >> kromozomIndex;
                cout << "Mutasyon islemi icin genin sirasini giriniz:";
                cin >> genIndex;
                dna.mutasyon(kromozomIndex, genIndex);
                cout << "Mutasyon basariyla gerceklestirildi.\n";
                break;
            }
            case 3: {
                cout << "Islemler.txt dosyasindaki otomatik islemler yapiliyor.";
                dna.otomatikIslemler("Islemler.txt");
                cout << "Otomatik islemler tamamlandi.\n";
                break;
            }
            case 4:
                dna.yazdir();
                break;
            case 5:
                cout << "Cikis yapiliyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim! Tekrar deneyin." << endl;
                break;
        }

        cout << endl;

    } while (islem != 5);
}

int main() {

    menu();

    return 0;
}