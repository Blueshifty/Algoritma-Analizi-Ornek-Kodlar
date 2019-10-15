#include <iostream>
#include <string>

using namespace std;

int benzetme(char kelime1[],char kelime2[],int uzunluk){
	int gun = 0;
	for(int i=0;i<uzunluk;++i){
	if(kelime1[i]<kelime2[i]){
		if(kelime2[i]-kelime1[i]>=13){ kelime1[i]=kelime1[i]+13; gun=gun+1;}
		while(kelime1[i]!=kelime2[i]){
			kelime1[i]=kelime1[i]+1;
			gun=gun+1;
		}
	}
	if(kelime1[i]>kelime2[i]){
		if(kelime1[i]-kelime2[i]>=13){kelime1[i]=kelime1[i]-13;gun=gun+1;}
			while(kelime1[i]!=kelime2[i]){
				kelime1[i]=kelime1[i]-1;
				gun=gun+1;
			}
		}
	}
	return gun;
}

int main() {
	int uzunluk;
	cout<<"Stringlerin Uzunlugunu Girin:"<<endl;
	cin>>uzunluk;
	char kelime1[uzunluk];
	char kelime2[uzunluk];
	cout<<"Ilk Kelimeyi Girin"<<endl;
	cin>>kelime1;
	cout<<"Ikinci Kelimeyi Girin"<<endl;
	cin>>kelime2;
	cout<<"Toplam Gecen Gun Sayisi:"<<benzetme(kelime1,kelime2,uzunluk);
	return 0;
}
