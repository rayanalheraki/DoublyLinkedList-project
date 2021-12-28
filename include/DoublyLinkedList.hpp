#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Dugum.hpp"

class DoublyLinkedList {
private:
	Dugum *ilkDugum;
	Dugum *sonDugum;
	
public:

	DoublyLinkedList();	

	int findSize();
	
	void sonaEkle(string data);

	void indexeEkle(string data, int index);

	void indextenSil(int index);

	void yazdir();
	
	void clear();
	
	~DoublyLinkedList();
};

#endif