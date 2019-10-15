#include <iostream>
#include <vector>
using namespace std;

double Deneme = 0; 

//Bulunan Sonuclar Arasindan K Degerini Gecmeyen En Buyuk Degeri Bulmak Icin.

int buyukOlan(int x1, int x2,int k){
	if(x1>k){ x1 = 0;}
	if(x2>k){ x2 = 0;}
	if(x1 > x2){ return x1;}
	return x2;								
}

//Dizideki Tum Kombinasyonlar Arasindan K Sayisina En Yakin Toplami Donduren Recursive Fonksiyon.

int exhaustiveFonk(vector<int> x,int iterator,int k){
 // A Dizisinde Bakicak Eleman Kalmadiginda 0 Donduruyor.

 if(iterator==0){ Deneme++; return 0;}
 //Bakilan Elemani Ekleyip Yada Eklemeyerek Bakiyor Boylelikle Tum Olasiliklari Degerlendiriyor.
 
 else{  return buyukOlan(x.at(iterator-1) + exhaustiveFonk(x,iterator-1,k),exhaustiveFonk(x,iterator-1,k),k); }
  
}

int main(){
	int test,n,k,girdi,testSayac=1;
	vector<int> A;
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
		int sonuc = exhaustiveFonk(A,n,k);
		cout <<"\nToplam En Fazla Sonuc = "<<sonuc<<endl;
		cout<< Deneme<<" Deneme Yapilarak Bulundu.\n"<<endl;
		testSayac++;
		Deneme = 0;
		A.clear();
   	}
	return 0;
}

