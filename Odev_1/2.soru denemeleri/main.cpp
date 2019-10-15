#include <cstdlib>
#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

void yolEkle(vector<int> x[], int y,int z){
	x[y].push_back(z);
	x[z].push_back(y);
}


int  karsilastir(vector<int> x[],vector<int> y[], int x1){
int t=0;
for(int i =0; i < x1;++i){
	if(x[i].size() == y[i].size()){
		++t;
		cout << i << ". Sehiri Almis." <<endl;	
	}
	else{
	cout << i << ". Sehiri Alamamis." << endl;
}
}
	return t;
}

void print(vector<int> x[],int y){
	for(int i =0;i < y; ++i){
		cout << i;
		for(int t = 0;t < x[i].size();++t){
		cout << "->" << x[i].at(t); 
		}
		cout << endl;
	}

}

int main() {
	int sehir,yol1,yol2=0,girdi1,girdi2,gyolsayisi1,gyolsayisi2=0;
	cout << "Sehir Sayisini Giriniz:";
	cin >> sehir;
	vector <int> sehirler[sehir];
	vector <int> gidilenYollar[sehir];
	cout << "\nYol Sayisini Giriniz: ";
	cin >> yol1;
	cout << endl;
	while(yol2<yol1){
		cout << yol2 << ". Yolu Girin: " << endl;
		 cin >> girdi1;
		 cin >> girdi2;
		 yolEkle(sehirler,girdi1,girdi2);
		 ++yol2;
	}
	cout << "Gidilen Yol Sayisini Girin:" << endl;
	cin >> gyolsayisi1;
	while(gyolsayisi2<gyolsayisi1){
		cout << gyolsayisi2 << ". Gidilen Yolu Girin:" << endl;
		cin >> girdi1;
		cin >> girdi2;
		yolEkle(gidilenYollar,girdi1,girdi2);
		++gyolsayisi2;
	}
	print(sehirler,sehir);
	print(gidilenYollar,gyolsayisi1);	
	cout << karsilastir(sehirler,gidilenYollar,sehir);
	return 0;
}
