#include <iostream>
#include <vector>

using namespace std;


void kombinasyon(vector<int> dizi,int uzunluk1,int uzunluk2,int start,vector<bool> dizi2,&vector<vector<int> > kombinasyonlar){
	if(uzunluk1>uzunluk2){ return;}
	else if(uzunluk1 == uzunluk 2){
		vector<int> kombi;
		for(int i = 0; i< dizi.size();++i){
			if(dizi.at(i)){
				
			}
		}
	}
	
	
	
	
}










int main() {
	int n,k,test,testSayac=1,girdi;
	cout<<"Test Sayisini Giriniz:";
	cin>>test;
	vector<vector<int> >kombinasyonlar;
	vector<int>dizi1;
	vector<bool> dizi2;
	while(testSayac<=test){
		cout<<test<<". Test Icin Degerleri Girin:"<<endl;
		cout<<"Dizinin Uzunlugunu, 'n' Saysini Giriniz:";
		cin>>n;
		cout<<"K Sayisini Giriniz:";
		cin>>k;
		for(int i =0; i<n;++i){
			cout<<"Dizinin"<<i+1<<". Elemanýný Giriniz";
			cin>>girdi;
			dizi1.push_back(girdi);
		}
		
		for(int i = 1; i<=dizi1.size();i++){
		kombinasyon(dizi1,dizi.size(),0,0,dizi2,kombinasyonlar);
		
		}
	
	}		
	
	
	
	
	return 0;
}
