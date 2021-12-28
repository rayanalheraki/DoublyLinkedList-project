#ifndef DUGUM_HPP
#define DUGUM_HPP

#include<iostream>
#include<string>

using namespace std;

class Dugum{
public:
	string data;
	Dugum *sonraki ;
	Dugum *onceki;

	Dugum(string isim);
	
};

#endif 