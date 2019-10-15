#include <cstdlib>
#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>                                 //Mehmet Bir 160204027

using namespace std;

void menu_fonk();

class dugum{
 public:
 	dugum(char x,int y);
	int ad;
	int agirlik;
	char getAd();
	int getAgirlik();                                                                    // 3. Soru Ýçin Class Tanýmlamam.
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

void soru1Fonk(){	
	int vertex,derece1,derece2=0,x=1;
	cout << "Dugum Sayisini Giriniz (1<= N <=100)" << endl;
	cin >> vertex;
	while(vertex<1 || vertex >100){
		cout<<"Gireceginiz Sayi 1 ile 100 Arasinda Olmalidir" <<endl;
		cout<<"Dugum Sayisini Tekrar Giriniz:" << endl;
		cin >> vertex;
	}
	while(x<=vertex){
		cout << x << ". Dugumun Derecesini Girin:" << endl;                                           //1. Soru
		cin>>derece1;
		derece2=derece2+derece1;
		++x;
	}
	if(derece2==2*(vertex-1)){
		cout<<"Girilen Graf Bir Agac"<<endl;
	    cout<<"Menuye Donmek Icin Bir Tusa Basin";
	    getch();
	    return menu_fonk();
		}
	  cout<<"Girilen Graf Agac Deil"<<endl;
	  cout<<"Ana Menuye Donmek Icin Bir Tusa Basin";
	  getch();
	  return menu_fonk();
}

int  karsilastir(vector<int> x[],vector<int> y[], int x1){
int t=0;
for(int i =0; i < x1;++i){
	if(x[i].size() == y[i].size()){
		++t;                                                                              //2. Soruda Adamýn Gittiði Yolla Þehirlerin Grafini Karþýlaþtýrýyorum, Bir Þehre Baðlý Tüm Yollardan Geçmiþse O Þehri Almýþ Demektir.
		cout << i << ". Sehiri Almis." <<endl;	                                          //Bu Yüzden Adamýn Grafindaki Vertexlerin Edge Sayisi ile Þehirlerin Grafindaki Vertexlerin Edge Sayilarini Karþýlaþtýrýyorum.
	}
	else{
	cout << i << ". Sehiri Alamamis." << endl;
}
}
	return t;
}

void yolEkle(vector<int> x[], int y,int z){
	x[y].push_back(z);
	x[z].push_back(y);
}

void soru2Fonk(){
	int test1 = 0,test2;
	int sehir,yol1,yol2=0,girdi1,girdi2,gyolsayisi1,gyolsayisi2=0;
	vector <int> testSonuclari;       
	cout << "Test Sayisini Giriniz:" <<endl;
	cin >> test2;
	while(test1<test2){
		cout << "Test "<< test1+1 <<" Icin Sehir Sayisini Giriniz:";
		cin >> sehir;
		vector <int> sehirler[sehir];
		vector <int> gidilenYollar[sehir];                                                       //Gidilen Yolda Bir Graf
		cout << "\nYol Sayisini Giriniz: ";
		cin >> yol1;
		cout << endl;
	while(yol2<yol1){
		cout << yol2+1 << ". Yolu Girin (Arada Bosluk Olmali):  " << endl;
		cin >> girdi1;
		cin >> girdi2;                                                                                      //2. Soru
		yolEkle(sehirler,girdi1,girdi2);
		++yol2;
		}
	cout << "Gidilen Yol Sayisini Girin:" << endl;
	cin >> gyolsayisi1;
	while(gyolsayisi2<gyolsayisi1){
		cout << gyolsayisi2+1 << ". Gidilen Yolu Girin (Arada Bosluk Olmali):" << endl;
		cin >> girdi1;
		cin >> girdi2;
		yolEkle(gidilenYollar,girdi1,girdi2);
		++gyolsayisi2;
	}
	testSonuclari.push_back(karsilastir(sehirler,gidilenYollar,sehir));
	++test1;
	yol2=0,gyolsayisi2=0;
    if(test1<test2){
    	cout << test1+1 << ". Testin Degerlerini Girmek Icin Bir Tusa Basin";
	}
	else{
		cout << "Test Sonuclarini Gormek Icin Bir Tusa Basin";
	} 
	getch();
	system("cls");
    }
    cout<<"Test Sonuclari:"<<endl;
    for(int i =0;i< testSonuclari.size();i++){
    	cout<<i+1<<".Testin Sonucu:"<<testSonuclari.at(i)<<endl;
	}
	cout << "Ana Menuye Donmek Icin Bir Tusa Basin";
	getch();
	return menu_fonk();
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

bool sortDugum(dugum x,dugum y){                                                          //3. Soruda Vertexlerin Baðlý Olduðu Vertexleri Aðýrlýklarýna Gore Sýralamak Ýçin Sort Fonksiyonuna Kendi Kuralýmý Yazdým
	return(x.agirlik > y.agirlik);                                                         //Bu Fonksiyonun Dondurgu Deger False Olursa Swap Islemini Yapýyor
}                                                                                                             
                                                                                                              
void sortDizi(vector<dugum> x[],int y){
	for(int i= 0;i<y;++i){
		sort(x[i].begin(),x[i].end(), sortDugum);                                                                        //Kuralý Burda Kullanýyorum                 
	}
}

void kDegeri(vector<dugum> x[],int k, int y){
		for(int i=0;i<y;++i){
			cout << i << "  Icin " << k+1 << ". Sirada Bulunan Eleman:";
			if(k<x[i].size()){
				cout << " "<< x[i].at(k).ad<<endl;
			}                                                                                     //Her Vertex Icin K. Elemaný Bulup Yazdiriyorum, Eger K. Elemaný Yoksa -1 Yazýyor.
			else{
				cout << "-1"<<endl;
			}
		}
		cout<< "Ana Menuye Donmek Icin Bir Tusa Basin";
		getch();
		return menu_fonk();
}

void soru3Fonk(){
	int x1,x2=0;
	int z,y,agirlik,e1,e2,e3,e4=0,k;
	vector<dugum> dugumler;
	cout << "Vertex Sayisini Girin: ";
	cin >> x1;
    vector<dugum> dizi[x1];
	while(x2<x1){
		cout << "\n"<<x2<<".Vertex'in Agirligini Girin: ";
		cin >>agirlik;
	    dugumler.push_back(dugum(x2,agirlik));
		x2++;			
	}                                                                                                       //3. Soru
	cout <<"\nEdge Sayisini Girin: ";
	cin >> e3;
	while(e4<e3){
		cout << "\n"<< e4 <<". Edge'i Girin (Arada Bosluk Olmali): ";
		cin >> e1;
		cin >> e2;
		edgeEkle(dizi,e1,e2,dugumler);
		e4++;
	}
	cout <<"\nK Sayisini Giriniz: ";
	cin >>k;
	sortDizi(dizi,x1);
	edgeYazdir(dizi,x1);
	kDegeri(dizi,k-1,x1);
	e4=0,x2=0;
	}

void menu_fonk(){
	system("cls");
	int x;
    cout << "** MENU **"<<endl;
    cout << "1. Soru"<<endl;
    cout << "2. Soru"<<endl;
    cout << "3. Soru"<<endl;
    cout << "4--Cikis"<<endl;
    cout << "Soru Numarasi Giriniz:\t";
    cin >> x;
    switch(x){
		case 1:
			system("cls");
			soru1Fonk();
		case 2:
		 	system("cls");
			soru2Fonk();                                                                                //Menu
		case 3:
			system("cls");
			soru3Fonk();
		case  4:
			return;
		default:
			cout<<"1-2-3-4 Girdilerinden Birini Girmeliydiniz."<< endl;
			cout<<"Menuye Donmek Icin Bir Tusa Basin.";
			getch();
			return menu_fonk();
		}
}

int main() {
    menu_fonk();
    return 0;
}

