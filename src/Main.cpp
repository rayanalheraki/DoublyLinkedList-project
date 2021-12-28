#include "DoublyLinkedList.hpp"
#include <fstream>
#include <string>

using namespace std;
int main()
{
	ifstream file;
	//dosyayi acma
	file.open("Veri.txt");
	string line;
	string isim;
	int index;

	// iki yonlu bagli listeyi cagirma
	DoublyLinkedList *liste = new DoublyLinkedList();
	//dosyadan okuma 
	if (file.is_open()) {
		//line by line okuma 
		while (getline(file, line) ){
			if(line[0] == 'E'){

				// '(' ve # arasindaki sayi index degiskaninda saklar
				index= stoi(line.substr(2 , line.find("#") - line.find("(")-1 ));

				// '#' ve ')' arasindaki isim index degiskaninda saklar
				isim = line.substr(line.find("#")+1, line.find(")")-(line.find("#")+1));

				//ekleme fonksiyonu 
				liste->indexeEkle(isim,index);

			}else if(line[0] == 'S'){

				// '(' ve ')' arasindaki sayi index degiskaninda saklar
				index =stoi(line.substr(line.find("(")+1, line.length()-line.find("(")-2));
				//silme fonksiyonu
				liste->indextenSil(index);

			}else{
				cout << "Hatali islem." <<endl;

			}
		}
	}
	else {
		cout << "Error" <<endl;
	}
	//dosyayi kapatima
	file.close();
	cout << endl;
	//listeyi yazdir 
	liste->yazdir();
	delete liste;

	system("pause");
	return 0;
}
