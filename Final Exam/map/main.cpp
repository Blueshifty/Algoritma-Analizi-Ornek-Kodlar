#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;
/*Kelime Class'im, Hem Kelimeyi Hemde Bulundugu Satiri Barindiriyor*/
class kelime{
public:
	string kelime;
	int satir;
	int getSatir();
	string getKelime();	
};

int kelime:: getSatir(){
	return this->satir;
}

string kelime::getKelime(){
	return this->kelime;
}

/*Buyuk Harfleri Kucuk Harflere Donusturen Fonksiyon */
void convertToLowercase(string &x){
	for(int i = 0; i<x.length();++i){
		if(isupper(x[i])){ x[i] = tolower(x[i]);}
	}
}

/*Vectordeki Harfleri Stringe Ceviren Fonksiyon*/
string vectorToString(vector<char> x){
	string donen;
	donen.resize(x.size());
	for(int i = 0; i<x.size();++i){ donen[i] = x.at(i);}
	return donen;
}

/*Sozluk Dosyasini Okuyup Map'e Ekleyen Fonksiyon */
map<string,int> dosyaOkuma(string y){
	int mapDeger=1;
	map<string,int> dicti;
	vector<char> really;
	string okunan;
	ifstream okuyucu;
	string line;
	okuyucu.open(y.c_str());
	while(getline(okuyucu,okunan)){ 
		convertToLowercase(okunan);
		for(int i = 0; i< okunan.length();++i){
			if(okunan[i]>31 && okunan[i]<48){
				dicti[vectorToString(really)] = mapDeger;
				really.clear();
			}
			else if(i+1==okunan.length()){
				really.push_back(okunan[i]);
				dicti[vectorToString(really)] = mapDeger;
				really.clear();
			}
			else{really.push_back(okunan[i]);}
		}
		mapDeger++;
      }
    okuyucu.close();
	return dicti;
}

/* Yazim Denetlemesi Yapilacak Olan Dosyayi Okuyup Kelimeleri Vectore Ekleyen Fonksiyon  */
vector<kelime> dosyaOkumaVector(string x){
	kelime anlik;
	int satir = 1;
	string okunan;
	ifstream okuyucu;
	string line;
	vector<char> really;
	vector<kelime> all; 
	okuyucu.open(x.c_str());
	while(getline(okuyucu,okunan)){
		convertToLowercase(okunan);
		for(int i = 0; i<okunan.length();++i){
			if(okunan[i]>31 && okunan[i]<48){
				anlik.kelime = vectorToString(really);
				anlik.satir = satir;						
				all.push_back(anlik);
				really.clear();
				continue;
			}
			else if(i+1==okunan.length()){
				really.push_back(okunan[i]);
				anlik.kelime = vectorToString(really);
				anlik.satir = satir;
				all.push_back(anlik);
				really.clear();
			}
			else{really.push_back(okunan[i]);}
		}
		satir++;
	}
	okuyucu.close();
	return all;
}

/*Sozluk Dosyasindan Okudugum Kelimeleri, Karsilastirilacak Kelimelerle Karsilastiran Fonksiyon*/
map<string, vector<int> > karsilastir(map<string,int> x,vector<kelime> y){
	map<string,vector<int> >donen;
	map<string,int>::iterator it;
	string secilen;
	for(int i = 0;i < y.size();++i){
		it = x.find(y.at(i).getKelime());
		if(it==x.end()){
			donen[y.at(i).getKelime()].push_back(y.at(i).getSatir());
		}
	}
	return donen;
}

int main(){

	map<string,vector<int> > last;
	map<string,int>::iterator it;
	string line,line2;
	cout<<"Dosya Adini Giriniz:"<<endl;
	cin>>line;
	cout<<"Yazim Denetlemesi Yapilacak Dosyanin Adini Giriniz:"<<endl;
	cin>>line2;	
	
	last = karsilastir(dosyaOkuma(line),dosyaOkumaVector(line2));
	
	map<string, vector<int> >::iterator it2;
	cout<<"\nKelime:"<<"\tBulunduklari Satir:"<<endl;
	for(it2 = last.begin();it2!=last.end();++it2){
		cout<<" "<<it2->first<<"\t";
		for(int i = 0; i<it2->second.size();++i){
			cout<<it2->second.at(i)<<" ";
		}
		cout<<endl;
	}
		
}





