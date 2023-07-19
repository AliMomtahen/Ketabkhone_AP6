FLAG = g++ -std=c++11

main: main.o 
	$(FLAG) main.o Library.o Person.o Document.o Exception.o -o main

main.o: main.cpp Library.o
	$(FLAG) -c main.cpp 

Library.o: Library.cpp Library.hpp Document.o Person.o Exception.o
	$(FLAG) -c Library.cpp 

Document.o:Document.cpp Document.hpp Exception.o
	$(FLAG) -c Document.cpp 


Person.o:Person.cpp Person.hpp Document.o Exception.o
	$(FLAG) -c Person.cpp 


Exception.o: Exception.cpp Exception.hpp	
	$(FLAG) -c Exception.cpp 

