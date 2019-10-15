#include <iostream>
#include <vector>
#include <conio.h>				//Mehmet Bir 160204027 Algoritma Analizi Odev 5

using namespace std;

vector<vector<int> > kombinasyonlar;	//Bütün Kombinasyonlar Bu Vectorde Tutuluyor
double Deneme=0;						//Bu Degerlerim Argüman Olarak Yer Kaplamasin Diye Global
										
void yazdir(){
	for(int i = 0;i<kombinasyonlar.size();++i){
		cout<<endl;
		for(int j = 0;j<kombinasyonlar.at(i).size();++j){
			cout<<kombinasyonlar.at(i).at(j)<<" ";
		}														//Kombinasyonlari Yazdirma Fonk
	}
	cout<<"\n"<<"Devam Etmek Icin Bir Tusa Basin";
	getch();
	system("cls");
}

int  hesapla(int k){
	int deger= 0,toplam;
	for(int i =0;i<kombinasyonlar.size();i++){
		toplam = 0;								//Kombinasyonlardan K ya En Yakýn Toplamý Donduren Fonk
		for(int j=0;j<kombinasyonlar.at(i).size();j++){ toplam = toplam+kombinasyonlar.at(i).at(j);}
		if(deger<toplam&&toplam<=k){ deger = toplam;}
	}
	return deger;
}

void exhaustiveFonk(vector<int> x,int iterator,int k,vector<int> eleman){
	if(iterator==x.size()){Deneme++;kombinasyonlar.push_back(eleman);return;}
	vector<int>eleman2 = eleman;				//Kombinasyon Olusturma Fonk
	eleman2.push_back(x.at(iterator));			//Secili Elamaný Dahil Edip ve Etmeyip Kombinasyon Olusturuyor
	exhaustiveFonk(x,iterator+1,k,eleman2);
	exhaustiveFonk(x,iterator+1,k,eleman);
}

int main(){
	int test,n,k,girdi,testSayac=1,sonuc1,sonuc2,sonuc,sonuc3,sonuc4;
	vector<int> A;
	cout<<"20 Uzunlugunda Bir Diziyi Hesaplamasi 5 Saniye Suruyor"<<endl;
	cout<<"Dizi Uzunlugunu Istediginiz Kadar Girebilirsiniz"<<endl;
	cout<<"Eger 10 dan Fazla Eleman Girerseniz Yazdirmayin Cok Uzun Surer ^^"<<endl;
	cout <<"Test Degerini Girin:";
	cin >> test;
	while(testSayac<=test){
		cout <<testSayac<<". Test Icin Degerleri Girin:"<<endl;	
    	cout <<"--Dizi Uzunlugunu Yani n Sayisini Girin:";
		cin >> n;
		cout<<"--k Sayisini Girin:";
		cin >> k;
		for(int i =0;i<n;++i){
			cout <<"--A'nin " << i+1<< ". Elemanini Girin:";
			cin >>girdi;
			A.push_back(girdi);
	  	}
		vector<int> giris;
		exhaustiveFonk(A,0,k,giris);
		cout<<"\nToplam En Fazla Sonuc = "<<hesapla(k)<<endl;
		cout<<Deneme<<" Deneme Yapilarak Bulundu."<<endl;
		cout<<"Tum Kombinasyonlari Gormek Icin 1 Devam Etmek Icin Herhangi Bir Sayi Girin"<<endl;
		cin>>girdi;
		if(girdi==1){yazdir();}
		testSayac++;
		A.clear();
		kombinasyonlar.clear();
		Deneme = 0;
   	}
	return 0;
}

