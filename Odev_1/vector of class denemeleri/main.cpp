#include <cstdlib>
#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

class dugum{
 public:
 	dugum(char x,int y);
	int ad;
	int agirlik;
	char getAd();
	int getAgirlik();
};

dugum::dugum(char x,int y){
	ad=x;
	agirlik=y;
}


char dugum::getAd(){
	return ad;
}

int dugum::getAgirlik(){
	return agirlik;
}

void printDugum(vector <dugum> x){
	for(int i=0;i<x.size();++i){
		cout<<"Dugum :"<< x[i].ad << "\t";
		cout<<"Agirligi:"<<x[i].agirlik<<endl;
	}
	
}

void edgeEkle(vector<dugum> x[],int z,int y,vector<dugum> t){
 x[z].push_back(t.at(y));
 x[y].push_back(t.at(z));
}

void edgeYazdir(vector<dugum> x[],int y){
	for(int i = 0;i<y;i++){
		cout << i;
		for(int r=0;r < x[i].size();++r){
			cout<< "->"<< x[i].at(r).ad;
		}
		cout<<endl;
	}
}

bool sortDugum(dugum x,dugum y){
	return(x.agirlik > y.agirlik);
}

void sortDizi(vector<dugum> x[],int y){
	for(int i= 0;i<y;++i){
		sort(x[i].begin(),x[i].end(), sortDugum);
	}
}

void kDegeri(vector<dugum> x[],int k, int y){
		for(int i=0;i<y;++i){
			cout << i << "  Icin " << k << ". Sirada Bulunan Eleman:";
			if(k<x[i].size()){
				cout << " "<< x[i].at(k).ad<<endl;
			}
			else{
				cout << "-1"<<endl;
			}
		}
}


int main() {
	int x1,x2=0;
	int z,y,agirlik,e1,e2,e3,e4=0,k;
	vector<dugum> dugumler;
	cout << "Dugum Sayisini Girin: ";
	cin >> x1;
    vector<dugum> dizi[x1];
	while(x2<x1){
		cout << "\n"<<x2<<".Dugumun Agirligini Girin: ";
		cin >>agirlik;
	    dugumler.push_back(dugum(x2,agirlik));
		x2++;			
	}
	cout <<"\nEdge Sayisini Girin: ";
	cin >> e3;
	while(e4<e3){
		cout << "\n"<< e4 <<". Edge'i Girin: ";
		cin >> e1;
		cin >> e2;
		edgeEkle(dizi,e1,e2,dugumler);
		e4++;
	}
	cout <<"\nK Sayisini Giriniz: ";
	cin >>k;
	sortDizi(dizi,x1);
	edgeYazdir(dizi,x1);
	kDegeri(dizi,k,x1);
    return 0;
}

