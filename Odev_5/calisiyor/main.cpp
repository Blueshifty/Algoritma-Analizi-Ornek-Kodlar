#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

void uyumlu(vector<int> x,int k,int& enbuyuk){
	int toplam=0;
	for(int i = 0;i<x.size();i++) { toplam = toplam + x.at(i);}
	if(toplam<=k&&toplam>enbuyuk) { enbuyuk = toplam; }
}

// perm[] : perm[i] is 1 if a[i] is considered, else 0
// index : subscript of perm which is to be 0ed and 1ed
// n     : length of the given input array
// k     : length of the permuted string
void combinate(vector<int> sayilar, vector<int> perm,int index, int n, int p,int k,int& enbuyuk)
{
    static int count = 0;
	vector<int> anlik;
   if( count == p )
   { 
      for(int i=0; i<n; i++){ if( perm[i]==1){ anlik.push_back(sayilar.at(i));}}
      uyumlu(anlik,k,enbuyuk);
    } 
	else if( (n-index)>= (p-count) ){

         perm[index]=1;
         count++;
         combinate(sayilar,perm,index+1,n,p,k,enbuyuk);

         perm[index]=0;
         count--;
         combinate(sayilar,perm,index+1,n,p,k,enbuyuk);

   }
}

int main()
{
   int boyut,girdi,k,enbuyuk=0;
   vector<int> sayilar;
   vector<int> perm;
   cout <<"Dizinin Buyuklugunu, 'n' Sayisini Girin:";
   cin >> boyut;
   cout<< "K Sayisini Girin:";
   cin >> k;
   for(int i = 0;i <boyut;++i){
   	cout<<i+1<<". Elemaný Giriniz";
   	cin>>girdi;
   	sayilar.push_back(girdi);
   	perm.push_back(0);
   }
   for(int i = 1; i<=sayilar.size();++i){ combinate(sayilar,perm,0,sayilar.size(),i,k,enbuyuk);}
   cout<<"En Buyuk Deger ="<<enbuyuk;

   return 0;
}
