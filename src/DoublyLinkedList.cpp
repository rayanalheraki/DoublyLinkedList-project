#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList() {
	ilkDugum = NULL;
	sonDugum = NULL;
}

//liste boyutu hesaplamak
int DoublyLinkedList::findSize()
{
	Dugum* temp=ilkDugum ;
	int res = 0;
	while (temp != NULL)
	{
		res++;
		temp = temp->sonraki;
	}
	return res;
}

//liste sonuna yeni dugum eklemek icin
void DoublyLinkedList::sonaEkle(string data) {
	Dugum *yeni = new Dugum(data);
	//eger liste null ise ilk elemen olarak ekler 
	//degilse liste sonuna yeni elemen ekler
	if (ilkDugum == NULL) {
		ilkDugum = yeni;
		sonDugum = yeni;
	}
	else {
		sonDugum->sonraki = yeni;
		yeni->onceki = sonDugum;
		sonDugum = yeni;
	}
}

void DoublyLinkedList::indexeEkle(string isim, int index) {
	int DLLBoyutu = findSize();
	//4 
	if(index >= DLLBoyutu){
		//eger index liste boyutundan buyuk yada esit ise liste sonuna eleman ekler
		sonaEkle(isim);
	}
	else if(index >= 0){
		//sona yeni bos elemen ekle
		sonaEkle("");
		
		Dugum* temp = sonDugum;
		//liste boyutu 1 artiracak ve DLLBoyutu degiskanina -1 eklemek zorunda kalmayacagiz 
		//cunku index 0 dan basliyor
		//4 - 3 > 2 
		for (int i = DLLBoyutu ; i > index && temp != nullptr; i--){
			temp->data = temp->onceki->data;
			temp = temp->onceki;
			if( index == (i-1) ){
				temp->data = isim;
			}
		}
	}
}

void DoublyLinkedList::indextenSil( int index) {
	int DLLBoyutu = findSize();
	if(index >= DLLBoyutu){
		Dugum* temp = sonDugum;
		sonDugum=sonDugum->onceki;
		//yeni olacak sonDugumun Sonraki degerini NULL olacak
		sonDugum->sonraki =nullptr;
		//silmek icin delete kullanilir
		delete temp;
	}
	else if(index >= 0){
		Dugum* temp = ilkDugum;
		//liste boyutunu 1 artiracak ve DLLBoyutu degiskanina -1 eklemek zorunda kalmayacagiz 
		//cunku index 0 dan basliyor
		for(int i = 0 ; i < DLLBoyutu-1 && temp != nullptr; i++){
			if(i >= index){
				temp->data = temp->sonraki->data;
				temp = temp->sonraki;
				if( DLLBoyutu == i+2 ){
					//son dugumu silmeden once sonDugum onceki dugum olacak
					sonDugum=sonDugum->onceki;
					//yeni olacak sonDugumun Sonraki degerini NULL olacak
					sonDugum->sonraki =nullptr;
					//silmek icin delete kullanilir
					delete temp;
					cout<<"index:" << index <<"'deki dugum silindi."<<endl;
				}
			}else{
				temp = temp->sonraki;
			}
		}
	}else{
		cout<<"index:" << index <<"de dugum yok."<<endl;

	}
	
	
}

//tum dugumleri while kullanarak yazdirmak icin
void DoublyLinkedList::yazdir() {
	Dugum *temp;
	temp = ilkDugum;
	while (temp != nullptr)
	{
		cout << temp->data ;
		if (temp->sonraki != nullptr) {
			cout << "<->";
		}
		else {
			cout << endl;
		}
		temp = temp->sonraki;
	}
}

//tum dugumleri bellekten silmek icin
void DoublyLinkedList::clear(){
	Dugum *temp;
	temp = sonDugum;
	while (temp->onceki != NULL)
	{
		sonDugum = sonDugum->onceki;
		delete temp;
		temp = sonDugum;
	}
}

DoublyLinkedList::~DoublyLinkedList(){
	clear();
	delete ilkDugum , sonDugum;
}