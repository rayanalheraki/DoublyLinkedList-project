hepsi:derle calistir
	
derle:
	g++ -c ./src/Dugum.cpp -I ./include -L ./lib -o ./lib/Dugum.o
	g++ -c ./src/DoublyLinkedList.cpp -I ./include -L ./lib -o ./lib/DoublyLinkedList.o
	g++ ./src/Main.cpp ./src/Dugum.cpp ./src/DoublyLinkedList.cpp  -I ./include -L ./lib -o ./bin/Main.exe
calistir:
	./bin/Main.exe
