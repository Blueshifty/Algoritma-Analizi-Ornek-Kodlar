#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>										//Mehmet Bir 160204027
#include <sstream>										//Algoritma Analizi Quiz C++ Programi				
#include <vector>										//Olasilik Cok Olduðu Icin Sayilari Bulmasý 1 Dakika Surebilir.
#include <math.h>

using namespace std;

int degerAta(int deger[],int uzunluk){
	int donen = 0;
	int basamak = 1;
	for(int i = 0; i<uzunluk;i++ ){
		basamak = pow(10,(uzunluk-1)-i);
		if(i == uzunluk-1) { basamak = 1; }
		donen += deger[i]*basamak;
	}
	return donen;
}

bool bulunuyorMu(vector<int> x,int y){
	if(x.size()==0){ return false; }
	for(int i = 0;i<x.size();++i){
		if(y==x.at(i)){
			return true;
		}
	}
	return false;
}

int main() {

srand(time(NULL));

double deneme = 0;	
vector<int> sayilar;
int y1=0,y2=1,y3=0;	
	
string string1x ="SEND";
string string2x ="MORE";
string string3x ="MONEY";
string string4x ="SENDMORY";

int deger1[string1x.size()];
int deger2[string2x.size()];
int deger3[string3x.size()];
int deger4[string4x.size()];


while((y1+y2) != y3){


	deger4[4] = 1;	
	deger4[0] = 9;							    //M ve S nin Degerleri Degismiyor Cunku 4 Basamakli Iki Sayinin Toplaminin 5.ci Basamagi 1 Olmali. 
	sayilar.push_back(1);					    //M = 1 ise S = 9 Olmalý Cünkü Toplamý 2 Basamakli Bir Sayi Olmak Zorunda
	sayilar.push_back(9);                       //Bu Tanimlamalari Yapmadanda Yaptirabilirdim Ama O Zaman Bulmasý Asiri Uzun Surerdi.
							
	
	for(int i = 0; i<string4x.size();++i){ 
	if(i==4||i==0){continue;}
	deger4[i]= rand()%10;									     //Sayilar Birbirinden Farkli Olsun Diye Onceden Secilen Sayilari Vektore Ekledim.
	while(bulunuyorMu(sayilar,deger4[i])){deger4[i]=rand()%10;}
	sayilar.push_back(deger4[i]);
	} 
	
	cout <<"\n"<< deneme+1 << ". Deneme:"<<endl;
	deneme ++;
	cout<<"  ";
	for(int i = 0; i<string4x.size();++i){
		cout<<string4x[i]<<"="<<deger4[i]<<"\t";
	}
	
	for(int i = 0; i<string1x.size();++i){
		for(int j = 0; j<string4x.size();++j){
			if(string1x[i]==string4x[j]){
				deger1[i] = deger4[j];
				break;
			}
		}
	}
	
	for(int i = 0; i<string2x.size();++i){
		for(int j = 0; j<string4x.size();++j){
			if(string2x[i]==string4x[j]){
				deger2[i] = deger4[j];
				break;
			}
		}
	}
	for(int i = 0; i<string3x.size();++i){
		for(int j = 0; j<string4x.size();++j){
			if(string3x[i]==string4x[j]){
				deger3[i] = deger4[j];
				break;
			}
		}
	}		
   y1 = degerAta(deger1,string1x.size());
   y2 = degerAta(deger2,string2x.size());
   y3 = degerAta(deger3,string3x.size());
   cout<<"\n"<<"  SEND = "<<y1<<"\n  MORE = "<<y2<<"\n  MONEY = "<<y3<<"\n  SEND + MORE = "<<y1+y2;
   sayilar.clear();
}

cout<<"\n\n\n"<<deneme<<" Kere Deneme Yapildi.";
	
	return 0;
}
