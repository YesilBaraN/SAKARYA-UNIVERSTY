# Varsayılan hedef
hepsi: derle calistir

# Derleme işlemi
derle:
	g++ -I ./include/ -c ./src/Gen.cpp -o ./lib/Gen.o
	g++ -I ./include/ -c ./src/Kromozom.cpp -o ./lib/Kromozom.o
	g++ -I ./include/ -c ./src/DNA.cpp -o ./lib/DNA.o
	g++ -I ./include/ -c ./src/Test.cpp -o ./lib/Test.o
	g++ ./lib/Gen.o ./lib/Kromozom.o ./lib/DNA.o ./lib/Test.o -o ./bin/Test

# Çalıştırma işlemi
calistir:
	./bin/Test

# Temizlik
temizle:
	rm -rf ./lib/*.o ./bin/Test

# Hedef temizleme
temiz: temizle
