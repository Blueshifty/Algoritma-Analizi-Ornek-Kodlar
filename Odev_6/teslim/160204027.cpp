#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;									//Mehmet BÝR 160204027
														
void menuFonk();
bool sayilar[10];
vector<int> asalSayilar;

/*bool recursive(int x){
	if(x==0){ return true;}
	if(x==1){ return false;} 1. Sorunun Dynamic Approach Yapilmadan Recursion Hali
	recursive(x-2);
}*/

bool dynamic(int x){
	if(sayilar[x]!=NULL){ return sayilar[x];}
	sayilar[0] = true;
	sayilar[1] = false;											//Dynamic Approach
	for(int i = 2;i<=x;++i){ sayilar[i] = sayilar[i-2]; }
	return sayilar[x];
}

void fonk1(){
	int deger = 0,deger2;
	string girdi;	
	cout<<"String'i Giriniz:";
	cin>>girdi;
	for(int i=0;i<girdi.size();++i){ if(dynamic(girdi[i]-48)){deger++;} } //Rakamlar ASCII Tablosunda 48'den Basliyor
	deger2 = deger;
	cout<<"       Sayi Seti:";
	for(int i = 0;i<girdi.size();++i){
	cout<<deger2;	
	if(dynamic(girdi[i]-48)){deger2--;}}
	cout<<"\n"<<deger<< " Tane Cift Sayi Bulunuyor"<<endl;	
	cout<<"Menuye Donmek Icin Bir Tusa Basin...";
	getch();
	return menuFonk();								
}

/*bool recursiveAsal(int x,int y){
	if(y*y>x){return true;}
    if(x%y==0){return false;}  2.Sorunun Dynamic Approach Yapilmadan Recursion Hali
	recursiveAsal(x,y+1);
}*/

//Asal Olup Olmadýgýný Onceki Asallara Bolup Buluyorum 
bool asalMi(int x){
	for(int k = 0;asalSayilar[k]*asalSayilar[k]<=x;k++){ 
		if(x%asalSayilar[k]==0) return false;}
	return true;	
}

//1 milyonun altýndaki her asal sayi 6k-1 veya 6k+1(Ardýþýk Olmak Zorunda Deil Bu Yuzden Asalmi Fonksiyonuna Sokuyorum)
//Dynamic Programmingle Onceki Asal Sayilarý Tekrar Bulmadan,
//Yeni Asal Sayilarý Bulduruyorum.
void dynamic2(int x){
	asalSayilar.push_back(2);
	asalSayilar.push_back(3);	
	for(int i=6;i<=x+1;i+=6){
		if(asalMi(i-1)){asalSayilar.push_back(i-1);}
		if(asalMi(i+1)){asalSayilar.push_back(i+1);}
	} 
}

bool kontrol(int x){
	for(int i = 0; i < asalSayilar.size();++i){
		if(asalSayilar.at(i)==x){return true;}
		if(asalSayilar.at(i)>x){return false;}
	}
}
	
void fonk2(){
	int prob,puan,toplamPuan=0;
	cout <<"Problem Sayisini Giriniz:"<<endl;
	cin>>prob;
	int sorular[prob];
	for(int i = 0; i<prob;++i){
		cout<<i+1<<". Problemin Puanini Giriniz:"<<endl;
		cin>>puan;
	    sorular[i] = puan;
	}
	dynamic2(prob);
	for(int i = 0;i<prob;++i){ if(kontrol(i+1)){toplamPuan+=sorular[i];} }
	cout<<"Canin Aldigi Toplam Puan: "<<toplamPuan<<endl;
	cout<<"Menuye Donmek Icin Bir Tusa Basin..."<<endl;
	getch();
	return menuFonk();
}

//Fonksiyon Dogrulugu Icin
void asalBulma(){
	int x;
	cout<<"Sayiyi Girin"<<endl;
	cin>>x;
	dynamic2(x);
	for(int i =0;i<asalSayilar.size();++i){ cout<<asalSayilar.at(i)<<endl;}
}

void menuFonk(){
	system("cls");
	int girdi;
	cout<<"***        MENU        ***"<<endl;
	cout<<"**************************"<<endl;
	cout<<"1. Soru"<<endl;
	cout<<"2. Soru"<<endl;
	cout<<"3--Exit"<<endl;
	cout<<"\n	Islem Numarasi Giriniz:"<<endl;
	cin >>girdi;
	switch(girdi){
		case 1: fonk1();
		case 2: fonk2();
		case 3: exit(0);
		case 4: asalBulma();
		default:cout<<"Islem Numarasi Girmeliydiniz.... Menuye Donmek Icin Bir Tusa Basin"; getch(); return menuFonk();
    }
}

int main(){ menuFonk(); return 0;}
