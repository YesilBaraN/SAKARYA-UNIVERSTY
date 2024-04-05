
                          
//                                                              SAKARYA ÜNİVERSİTESİ
//                                                   BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
//                                                       BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
//                                                         PROGRAMLAMAYA GİRİŞ DERSİ
//                                          
//                                                   ÖDEV NUMARASI.....: 1
//                                                   ÖĞRENCİ ADI.......: BARAN YEŞİLYURT
//                                                   ÖĞRENCİ NUMARASI..: G231210078
//                                                   DERS GRUBU........: 2. ÖĞRETİM B


#include<iostream>	
#include<cstdlib>
#include<ctime>
#include<string>
#include<math.h>
#include <iomanip>




using namespace std;



int main() {

	setlocale(LC_ALL, "Turkish"); //Türkçe karakterlerin ekrana yazdırılması

	float vizeoran, ödevoran1, ödevoran2, kısasıanvoran1, kısasınavoran2, yıliçioran, yılsonuoran;

	int öğrencisayısı;

	struct Ögrenci {         //Öğrenci veri tipi oluşturulması
		string isim;
		string soyisim;
		int vizenotu = 0, ödevnotu1 = 0, ödevnotu2 = 0, kısasınavnotu1 = 0, kısasınavnotu2 = 0, finalnotu = 0;
		double yıliçinot = 0, yılsonupuanı = 0;
		string harfnotu;
	};

	


	cout << "Öğrenci sayısını giriniz" << endl;        //Gerekli verileri klavyeden alma
	cin >> öğrencisayısı;


	do {

		cout << "Vize notu oranını giriniz (0-1 arasında)" << endl;
		cin >> vizeoran;

		cout << "1.Ödev oranını girniz (0-1 arasında)" << endl;
		cin >> ödevoran1;

		cout << "2.Ödev oranını girniz (0-1 arasında)" << endl;
		cin >> ödevoran2;

		cout << "1.Kısa sınav oranını giriniz (0-1 arasında)" << endl;
		cin >> kısasıanvoran1;

		cout << "2.Kısa sınav oranını giriniz (0-1 arasında)" << endl;
		cin >> kısasınavoran2;

		cout << "Yıl içi puanının geçme notuna oranını giriniz (0-1 arasında)" << endl;
		cin >> yıliçioran;



		if (yıliçioran > 1 || vizeoran > 1 || kısasıanvoran1 > 1 || kısasınavoran2 > 1 || ödevoran1 > 1 || ödevoran2 > 1 ||
			vizeoran + kısasıanvoran1 + kısasınavoran2 + ödevoran1 + ödevoran2 > 1)
			cout << "Hatalı oran girdiniz ya da oranlar toplarmı 1`den büyük" << endl;

	} while (yıliçioran > 1 || vizeoran > 1 || kısasıanvoran1 > 1 || kısasınavoran2 > 1 || ödevoran1 > 1 || ödevoran2 > 1 ||
		vizeoran + kısasıanvoran1 + kısasınavoran2 + ödevoran1 + ödevoran2 > 1);


	yılsonuoran = 1 - yıliçioran;





	Ögrenci* öğrenciler = new Ögrenci[öğrencisayısı];                        //Dizi oluşturma

	string isimler[] = { "Ali","Veli","Ayşe","Fatma","Baran","Tarık","Görkem","Senem","Mahmut","Deniz",               //Öğrenci isim dizisi oluşturma
						 "Erdal","Nil","Beren","Kenan","Gözde","Işıl","Özlem","Cihan","Duygu","Aysel",
						 "Aslı","Ela","Pınar","Koray","Yunus","Kemal","Uğur","Emre","Onur","Serkan",
						 "Gökhan","Esma","Filiz","Dilek","Melek","Medine","Aynur","Hüri","Elif","Songül" };

	string soyisimler[] = { "Kaya","Yeşilyurt","Şimşek","Yıldırım","Arslan","Acar","Doğan","Turan","Tekin","Yılmaz",
						   "Kara","Köse","Aksoy","Ünal","Çelik","Korkmaz","Keskin","Şen","Işık","Özdemir",
						   "Kılıç","Aktaş","Güneş","Koç","Bulut","Yıldız","Çakır","Aydın","Atasoy","Demir",             //Öğrenci soyisim dizisi oluşturma
						   "Karahan","Şahin","Demirer","Taşdemir","Altın","Çetinkaya","Uluç","Gür","Uzun","Tekeli" };


	srand(time(NULL));                                         //Rasgele sayı oluşturmayı başlatma


	for (int i = 0; i < öğrencisayısı; i++) {               //Her öğrenci için isim ve soyisim belirleme
		öğrenciler[i].isim = isimler[rand() % 40];
		öğrenciler[i].soyisim = soyisimler[rand() % 40];
	}

	for (int i = 0; i < öğrencisayısı; i++) {                //İstenilen koşula göre rastgele not belirleme
		if (i < öğrencisayısı * 0.2) {
			öğrenciler[i].vizenotu = 80 + rand() % 21;
			öğrenciler[i].kısasınavnotu1 = 80 + rand() % 21;
			öğrenciler[i].kısasınavnotu2 = 80 + rand() % 21;
			öğrenciler[i].ödevnotu1 = 80 + rand() % 21;
			öğrenciler[i].ödevnotu2 = 80 + rand() % 21;
			öğrenciler[i].finalnotu = 80 + rand() % 21;
		}
		else if (i < öğrencisayısı * 0.7) {
			öğrenciler[i].vizenotu = 50 + rand() % 31;
			öğrenciler[i].kısasınavnotu1 = 50 + rand() % 31;
			öğrenciler[i].kısasınavnotu2 = 50 + rand() % 31;
			öğrenciler[i].ödevnotu1 = 50 + rand() % 31;
			öğrenciler[i].ödevnotu2 = 50 + rand() % 31;
			öğrenciler[i].finalnotu = 50 + rand() % 31;
		}
		else {
			öğrenciler[i].vizenotu = rand() % 50;
			öğrenciler[i].kısasınavnotu1 = rand() % 50;
			öğrenciler[i].kısasınavnotu2 = rand() % 50;
			öğrenciler[i].ödevnotu1 = rand() % 50;
			öğrenciler[i].ödevnotu2 = rand() % 50;
			öğrenciler[i].finalnotu = rand() % 50;
		}


		öğrenciler[i].yıliçinot = ((öğrenciler[i].vizenotu * vizeoran) + (öğrenciler[i].kısasınavnotu1 * kısasıanvoran1) +         //Yıl içi notu belirleme
			(öğrenciler[i].kısasınavnotu2 * kısasınavoran2) + (öğrenciler[i].ödevnotu1 * ödevoran1) + (öğrenciler[i].ödevnotu2 * ödevoran2)) * yıliçioran;


		öğrenciler[i].yılsonupuanı = öğrenciler[i].yıliçinot + (öğrenciler[i].finalnotu * yılsonuoran);                       //Yıl sonu notu belirleme

	}



	// Ortalama, standart sapma, en yüksek ve en düşük notları hesaplama
	double toplamnot = 0;
	double karetoplamnot = 0;
	double enyükseknot = 0;
	double endüşüknot = 100;
	int harfnotu[9] = { 0 }; // AA,BA,BB,CB,CC,CD,DD,DF,FF

	for (int i = 0; i < öğrencisayısı; i++) {
		toplamnot += öğrenciler[i].yılsonupuanı;
		karetoplamnot += öğrenciler[i].yılsonupuanı * öğrenciler[i].yılsonupuanı;

		if (öğrenciler[i].yılsonupuanı >= enyükseknot) {          //En yüksek notu hesaplama
			enyükseknot = öğrenciler[i].yılsonupuanı;
		}


		if (öğrenciler[i].yılsonupuanı <= endüşüknot) {           //En düşük notu hesaplama
			endüşüknot = öğrenciler[i].yılsonupuanı;
		}

		cout << setw(8) << left << öğrenciler[i].isim << setw(10) << öğrenciler[i].soyisim << " ";
		cout << "Yıl sonu notu:" << " " << fixed << setprecision(0)<<setw(3) << öğrenciler[i].yılsonupuanı;

		if (öğrenciler[i].yılsonupuanı >= 90) {                   // Hangi harf notundan kaç kişi var hesaplama
			harfnotu[0]++;
			cout << "Harf notu : AA" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 85) {
			harfnotu[1]++;
			cout << "Harf notu : BA" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 80) {
			harfnotu[2]++;
			cout << "Harf notu : BB" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 75) {
			harfnotu[3]++;
			cout << "Harf notu : CB" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 65) {
			harfnotu[4]++;
			cout << "Harf notu : CC" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 58) {
			harfnotu[5]++;
			cout << "Harf notu : CD" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 50) {
			harfnotu[6]++;
			cout << "Harf notu : DD" << endl;
		}
		else if (öğrenciler[i].yılsonupuanı >= 40) {
			harfnotu[7]++;
			cout << "Harf notu : FD" << endl;
		}
		else {
			harfnotu[8]++;
			cout << "Harf notu : FF" << endl;
		}



	}




	double ortalama = toplamnot / öğrencisayısı;
	double standartsapma = sqrt((karetoplamnot / öğrencisayısı) - (ortalama * ortalama));

	cout << setw(30) << "Sınıfın standart sapması:" << standartsapma << endl;
	cout << setw(30) << "Sınıfın ortalaması:" << ortalama << endl;
	cout << setw(30) << "Sınıfın en düşük notu:" << fixed << setprecision(0) << endüşüknot << endl;
	cout << setw(30) << "sınıfın en yüksek notu:" << fixed << setprecision(0) << enyükseknot << endl;

	cout << "AA not alan kişi sayısı:" << setw(4) << harfnotu[0] << "%" << harfnotu[0] * 100 / öğrencisayısı << endl;
	cout << "BA not alan kişi sayısı:" << setw(4) << harfnotu[1] << "%" << harfnotu[1] * 100 / öğrencisayısı << endl;
	cout << "BB not alan kişi sayısı:" << setw(4) << harfnotu[2] << "%" << harfnotu[2] * 100 / öğrencisayısı << endl;
	cout << "CB not alan kişi sayısı:" << setw(4) << harfnotu[3] << "%" << harfnotu[3] * 100 / öğrencisayısı << endl;
	cout << "CC not alan kişi sayısı:" << setw(4) << harfnotu[4] << "%" << harfnotu[4] * 100 / öğrencisayısı << endl;
	cout << "CD not alan kişi sayısı:" << setw(4) << harfnotu[5] << "%" << harfnotu[5] * 100 / öğrencisayısı << endl;
	cout << "DD not alan kişi sayısı:" << setw(4) << harfnotu[6] << "%" << harfnotu[6] * 100 / öğrencisayısı << endl;
	cout << "FD not alan kişi sayısı:" << setw(4) << harfnotu[7] << "%" << harfnotu[7] * 100 / öğrencisayısı << endl;
	cout << "FF not alan kişi sayısı:" << setw(4) << harfnotu[8] << "%" << harfnotu[8] * 100 / öğrencisayısı << endl;


}