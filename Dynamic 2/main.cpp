#include <iostream>
#include <vector>
using namespace std;

int hesaplama(int A[],int B[],int input1,int input2,int input3,int uzunluk){
	vector<int> yazilacak;
	int A2[uzunluk],B2[uzunluk],toplam=0,flag=0;
	for(int i = 0; i<uzunluk;++i){
		switch(flag){
			case 0: A2[i]=A[i]; flag=1; break;
			case 1: A2[i]=B[i]; flag=0; break;
		} 
	}
	flag = 0;
	for(int i = 0; i<uzunluk;++i){
		switch(flag){
			case 0: B2[i]=B[i]; flag=1; break;
			case 1: B2[i]=A[i]; flag=0; break;
		} 
	}
	//Olusturdugum diziler aslinda olusabilecek tum olasiliklari barindiriyor.
	//Istenilen durumu cekebilmek icin toplama sartlarini degistirdim.
	//Sadece 1 for donuyor.
	if(input1==1&&(input2+1)%2!=0){ for(int i = input2;i<input3;++i){toplam+=A2[i]; yazilacak.push_back(A2[i]);}}
	if(input1==2&&(input2+1)%2!=0){ for(int i = input2;i<input3;++i){toplam+=B2[i]; yazilacak.push_back(B2[i]);}}
	if(input1==1&&(input2+1)%2==0){ for(int i = input2;i<input3;++i){toplam+=B2[i]; yazilacak.push_back(B2[i]);}}  
	if(input1==2&&(input2+1)%2==0){ for(int i = input2;i<input3;++i){toplam+=A2[i]; yazilacak.push_back(A2[i]);}} 
	cout<<"Secilen Elemanlar ";
	for(int i = 0;i<yazilacak.size();++i){cout<<yazilacak.at(i)<<"\t";} 
	return toplam;					
}
	
int main() {
	int uzunluk,girdi,input1,input2,input3;
	cout<<"Dizilerin Uzunlugunu Girin:"<<endl;
	cin>>uzunluk;
	int A[uzunluk];
	int B[uzunluk];
	for(int i =0; i<uzunluk;++i){ 
		cout<<"A Dizisinin "<<i+1<<". elemanini giriniz:"<<endl;	
		cin>>girdi;
		A[i]=girdi;
	  }
	for(int i =0; i<uzunluk;++i){ 
		cout<<"B Dizisinin "<<i+1<<". elemanini giriniz:"<<endl; 	
		cin >>girdi;
		B[i] = girdi;
	  }
	cout<<"Parametreleri girin:"<<endl;
	cin>>input1>>input2>>input3;
	cout<<"\nToplam:"<<hesaplama(A,B,input1,input2-1,input3,uzunluk);
	return 0;
}
