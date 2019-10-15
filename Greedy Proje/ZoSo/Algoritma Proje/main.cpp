#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void optimizeEtme(char k[], int x, int y){
	int kelimeDeger[x],sayac = 0,point1=0,point2,pointDeger,gecici,flag = 0;
	for(int i=0;i<x;++i){	kelimeDeger[i]=k[i]; }
	while(sayac<y){
		pointDeger = k[point1];
		for(int i=point1+1; i<x;++i){
			if(pointDeger>k[i]){
				point2 = i;
				pointDeger =k[i];
				flag = 1;
			}		
	}
	if(flag == 1){
	gecici = k[point2];
	k[point2] = k[point1];
	k[point1] = gecici;
	cout << "\n" << point1 << " ile " << point2 << "yer degistirdi."<<endl;
	sayac++;
    }
	point1++;
	flag = 0;
}
cout << "\n kelimenin son hali: " << k; 
}
	


int main() {
	int uzunluk,K;
	cout <<"Giriceginiz Kelimenin Uzunlugunu Girin:"<<endl;
	cin >> uzunluk;
	char kelime[uzunluk];
	cout << "K Sayisini Giriniz"<<endl;
	cin >> K;
	cout <<"Kelimeyi Girin"<<endl;
	cin >> kelime;
	optimizeEtme(kelime,uzunluk,K);	
	return 0;
}
