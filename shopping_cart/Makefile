FLAG = g++ -std=c++11

main: main.o 
	$(FLAG) main.o Cargo.o CartManager.o -o main

main.o: main.cpp CartManager.o
	$(FLAG) -c main.cpp 

CartManager.o: CartManager.hpp CartManager.cpp  Cargo.o
	$(FLAG) -c CartManager.cpp

Cargo.o: Cargo.hpp Cargo.cpp
	$(FLAG) -c Cargo.cpp