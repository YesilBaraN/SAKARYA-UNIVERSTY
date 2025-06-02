# Varsayılan hedef
hepsi: derle calistir

# Derleme işlemi
derle:
	g++ -I ./include/ -c ./src/AgacDugumu.cpp -o ./lib/AgacDugumu.o
	g++ -I ./include/ -c ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -I ./include/ -c ./src/BagliListeDugumu.cpp -o ./lib/BagliListeDugumu.o
	g++ -I ./include/ -c ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -I ./include/ -c ./src/main.cpp -o ./lib/main.o
	g++ ./lib/AgacDugumu.o ./lib/BagliListe.o ./lib/BagliListeDugumu.o ./lib/IkiliAramaAgaci.o ./lib/main.o -o ./bin/main

# Çalıştırma işlemi
calistir:
	./bin/main

# Temizlik
temizle:
	rm -rf ./lib/*.o ./bin/main

# Hedef temizleme
temiz: temizle
