#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <cmath>
using std::sqrt;
using std::pow;

#include <conio.h>//getch()

void menu();//menu fonk imzasi

class koordinat{
 public:
	int x,y,fail;
    koordinat(int x, int y,int fail){
		this->x = x;
		this->y = y;
		this->fail = fail;
	}
};

int uzunluk(int x1,int y1,int x2,int y2){
	return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

int en_fail(vector<koordinat> koordinatlar){
	int enbuyuk = 0,index;
	for(int i = 0;i<koordinatlar.size();++i){
		if(enbuyuk < koordinatlar.at(i).fail){enbuyuk = koordinatlar.at(i).fail; index = i;}
	} 
	if(enbuyuk==0){return -1;}else{return index;}
}

vector<koordinat> fail_listesi(vector<koordinat> koordinatlar, int d){
	for(int i = 0; i < koordinatlar.size(); ++i){koordinatlar.at(i).fail = 0;}
	for(int i = 0; i<koordinatlar.size();++i){
		for(int j = 0; j<koordinatlar.size();++j){
			if(i==j){continue;}
			else{
				if(d>uzunluk(koordinatlar.at(i).x,koordinatlar.at(i).y,koordinatlar.at(j).x,koordinatlar.at(j).y)){
				koordinatlar.at(i).fail+=1;
				}
			}
		}
	}
	return koordinatlar;
}

vector<koordinat> soru1fonk(vector<koordinat> koordinatlar, int d){
	koordinatlar = fail_listesi(koordinatlar,d);
	int index = en_fail(koordinatlar);
	while(index != -1){
		koordinatlar.erase(koordinatlar.begin()+index);
		koordinatlar = fail_listesi(koordinatlar, d);
		index = en_fail(koordinatlar);
	}
	return koordinatlar;
}

void soru1(){
	int d,n,x,y;
	vector<koordinat> koordinatlar;
	cout<<"Toplam Baz Istasyonu Sayisini Giriniz:"<<endl;
	cin>>n;
	cout<<"'d' Uzunlugunu Giriniz:"<<endl,
	cin>>d;
	for(int i = 0; i<n;++i){
		cout<<i+1<<". Baz Istasyonunun X ve Y Koordinatlarini Giriniz(Arada Bosluk Birakin):"<<endl;
		cin>>x>>y;
		koordinatlar.push_back(koordinat(x,y,0));
	}
	cout<<"\nGirilen Baz Istasyonlarinin Koordinatlari:"<<endl;
	for(int i = 0; i< koordinatlar.size();++i){
		cout<<koordinatlar.at(i).x<<"\t"<<koordinatlar.at(i).y<<endl;
	}
	koordinatlar = soru1fonk(koordinatlar,d);
	cout<<"Kalan Baz Istasyonlarinin Koordinatlari:"<<endl;
	for(int i =0; i< koordinatlar.size();++i){
		cout<<koordinatlar.at(i).x<<"\t"<<koordinatlar.at(i).y<<endl;
	}
	cout<<"Kaldirilmasi Gereken Minimum Baz Istasyonu Sayisi: "<<n-koordinatlar.size()<<endl;
	cout<<"\n\nMenuye Donmek Icin Bir Tusa Basin.....";
	getch();
	return menu();
}

class Kale{
 public:
	int n,m;
	vector<vector<int> > adj;
	void gezme();
	void addEdge(int v, int w);
	Kale(int n, int m);
	void minBulma();
	void baslangic();
};

Kale::Kale(int n,int m){
	adj = vector<vector<int> >(m,vector<int>(m));
	this->n = n;
	this->m =m;
	for(int i = 0; i<m;++i){
		for(int j = 0; j<m;++j){
			adj.at(i).at(j) = 1;	
		}
	}
}

void Kale::gezme(){
	for(int i = 0; i<this->adj.size();++i){
		cout<<i<<"- ";
		for(int j = 0; j<this->adj.at(i).size();++j){
			cout<<this->adj.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
}

void Kale::addEdge(int v, int w){
	adj.at(v).at(w) = 0;
}




void Kale::minBulma(){
	
	for(int i = 0; i < this->m;++i){
		
	}
	
	
}



void soru2(){
	int n,m,n1,n2;
	cout<<"Toplam Oda Sayisi Giriniz:"<<endl;
	cin>>m;
	cout<<"Odalar Arasindaki Baglanti Sayisini Giriniz:"<<endl;
	cin>>n;
	Kale gizemliKale(n,m);
	for(int i = 0; i<n;++i){
		cout<<i+1<<". Baglantiyi Giriniz(Arada Bosluk Birakin):"<<endl;
		cin>>n1>>n2;
		gizemliKale.addEdge(n1,n2);
	}
	gizemliKale.gezme();
	getch();
	return menu();
}

void menu(){
	int girdi;
	system("cls");
	cout<<"*****MENU*****\n"<<endl;
	cout<<"1-- 1.Soru"<<endl;
	cout<<"2-- 2.Soru"<<endl;
	cout<<"3-- Exit"<<endl;
	cout<<"\nIslem Numarasi Giriniz:"<<endl;
	cin>>girdi;
	switch(girdi){
		case 1:soru1();break;
		case 2:soru2();break;
		case 3:cout<<"\nProgram Kapaniyor.."; return exit(1);	
		default:cout<<"Islem Numarasi Girmeliydiniz..\nMenuye Donmek Icin Bir Tusa Basin!";getch();return menu();
	}

}

int main() { menu(); return 0; }
