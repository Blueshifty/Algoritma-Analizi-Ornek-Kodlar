#include <iostream>
#include <vector>
using namespace std;
double Deneme = 0;
int p = 0; 

//Bulunan Sonuclar Arasindan K Degerini Gecmeyen En Buyuk Degeri Bulmak Icin.

int buyukOlan(int x1, int x2,int k){
	if(x1+x2==k){return k;}
	if(x1==k||x2==k){return k;}
	if(x1 > k){x1 = 0;}
	if(x2 > k){x2 = 0;}
	if(x1>x2){ return x1;}
	return x2;					
}

//Dizideki Tum Kombinasyonlar Arasindan K Sayisina En Yakin Toplami Donduren Recursive Fonksiyon.

int exhaustiveFonk(vector<int> x,int iterator,int k,int durum){
 // A Dizisinde Bakicak Eleman Kalmadiginda 0 Donduruyor.
 if(iterator==x.size()){Deneme++; return 0;}
 //Bakilan Elemani Ekleyip Yada Eklemeyerek Bakiyor Boylelikle Tum Olasiliklari Degerlendiriyor.
 //Toplama Islemi Yaptigim Icin Agaca Farkli Þekillerde Bakiyorum.
 if(durum==0){p = buyukOlan(exhaustiveFonk(x,iterator+1,k,durum)+x.at(iterator),exhaustiveFonk(x,iterator+1,k,durum),k); return p;}
 if(durum==1){p = buyukOlan(exhaustiveFonk(x,iterator+1,k,durum),x.at(iterator)+exhaustiveFonk(x,iterator+1,k,durum),k); return p;}
 }
 

int main(){
	int test,n,k,girdi,testSayac=1,sonuc1,sonuc2,sonuc,sonuc3,sonuc4;
	vector<int> A;
	cout<<"20 Uzunlugunda Bir Diziyi Hesaplamayi 5 Saniye Suruyor"<<endl;
	cout<<"Dizi Uzunlugunu Istediginiz Kadar Girebilirsiniz"<<endl;
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
		sonuc1 = exhaustiveFonk(A,0,k,0);
	  	Deneme = 0; 				           
		sonuc2 = exhaustiveFonk(A,0,k,1);
		sonuc = buyukOlan(sonuc1,sonuc2,k);
		cout <<"\nToplam En Fazla Sonuc = "<<sonuc<<endl;
		cout<<Deneme<<" Deneme Yapilarak Bulundu.\n"<<endl;
		testSayac++;
		Deneme = 0;
		A.clear();
   	}
	return 0;
}


