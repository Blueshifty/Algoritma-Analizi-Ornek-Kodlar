#include <iostream>
#include <vector>

using namespace std;

float tur_ortalama(vector<float> x){
	float toplam = 0;
	for(int i = 0;i <x.size();++i){			//Her Turun Olasiliklarini Yazdirip Topluyorum.
		printf("\nSinem'in %d. Cekisinde Kazanma Olasiligi = %.8f",i+1,x.at(i));
		toplam += x.at(i);
	}
	return toplam;
}

void fonk(float kirmizi,float yesil){
	float ihtimal[int(kirmizi)+1][int(yesil)+1];
	for(int i=0;i<=kirmizi;++i){
		for(int j=0;j<=yesil;++j){
			if(i==0||j==0){ ihtimal[i][j] = 1;}
			else{ihtimal[i][j] = float(i)/(float(i)+float(j));}
		}
	}
	for(int i =0;i<kirmizi+1;++i){
		cout<<endl;
		for(int j = 0;j<yesil+1;++j){
			printf("%.2f\t",ihtimal[i][j]);
		}
	}

	//Yesil Top Sayisi Kadar Tur Sayisi Olabilir.
	//Turlarin Uzamasi Icin Her Iki Tarafta Yesil Top Cekmelidir.
	//Sinem'in 1. Cekisinde Kazanma Olasiligi = (kirmizi/toplam)
	//Sinem'in 2. Cekisinde Kazanma Olasiligi = (yesil/toplam).(yesil-1/toplam-1).(kirmizi/toplam-2) 
	//Sinem'in 3. Cekisinde Kazanma Olasiligi = (yesil/toplam).(yesil-1/toplam-1).(yesil-2/toplam-2).(yesil-3/toplam-3).(kirmizi/toplam-4)
	//Her Turun Olasiliklarinin Toplami  = Sinem'in Kazanma Olasiligi
	//Toplami Cunku Herbiri Ayri Bir Uzayi Temsil Ediyor. 

	vector<float> tur_olasilik;//her turun olasiliklarini bu vectore kaydediyorum.
	float tur=1; //etkisiz eleman
	for(int i = 0;i<=int(yesil);i=i+2){
		for(int j = 0; j<i;++j){
			tur = tur*(1-ihtimal[int(kirmizi)][(int(yesil)-j)]);//Tur Sayisi 1 den Fazla Ise Turu Kaybetme Olasýlýklarini 1 den Table Degerini Cýkartarak Buluyorum.
		}
		tur = tur*ihtimal[int(kirmizi)][(int(yesil)-i)];
		tur_olasilik.push_back(tur);
		tur = 1;
	}
	
	float kazanma_olasilik = tur_ortalama(tur_olasilik);
	printf("\nSinem'in Oyunu Kazanma Olasiligi = %.3f",kazanma_olasilik);
}


int main() {
	float yesil_top,kirmizi_top;
	cout<<"Kirmizi Top Sayisini Giriniz:"<<endl;
	cin>>kirmizi_top;
	cout<<"Yesil Top Sayisini Giriniz:"<<endl;
	cin>>yesil_top;
	fonk(kirmizi_top,yesil_top);
	return 0;
}
