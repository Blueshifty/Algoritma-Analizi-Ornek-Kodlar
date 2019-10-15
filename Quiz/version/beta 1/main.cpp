#include <iostream>
#include <string>
#include <algorithm>		 												
#include <vector>

using namespace std;

//Kucuk fonksiyonunun dongurdugu degiskenin classi.
class donen{
	public:
		int index;
		int deger;				
};

//Vector icerisinde secilen elemanýn bulunup bulunmadigini kontrol eden fonksiyon.
bool bulunuyormu(vector<int> x,int y){
	for(int i=0;i<x.size();++i){
		if(y==x[i]){
			return true;
		}
	}
	return false;
}
//Vectoru yazdiran fonksiyon.
void yazdir(vector<int> x){
	cout<<"\n";
	for(int i = 0; i<x.size();++i){
		cout<<x[i]<<"\t";
	}
}
//Vectorde girilen degerden kucuk deger varmi diye bakan fonksiyon.
bool buyukmu(vector<int> x,char k[],int y){
	for(int i =0;i<x.size();++i){
		if(k[x[i]]<y){
			return true;
		}
	}
	return false;
}
//Vectorun icerisinden en kucuk degeri donduren fonksiyon.
donen kucuk(vector<int> x, char k[]){
	int j = 5000;
	donen y;
	for(int i =0;i<x.size();++i){
		if(j>k[x.at(i)]){
			j=k[x.at(i)];
			y.index =  i;
			y.deger = k[x.at(i)];
		}
	}
	return y;
}
//Dizi yazdiran fonksiyon.
void yazdirKelime(char k[],int x){
	cout<<"\n";
	for(int i=0;i<x;++i){
		cout<<k[i]<<"\t";
	}
	
}
//Degismesi gereken harfleri secen fonksiyon.
void karakterSecme(char k[], int x, int y){
	int z=0,point1,point2,point3,flag=0,deger,flag2=0;
	char k3[x];
	vector<int> secilenler;
	vector<int> yazilacakSecilenler;
	for(int i =0;i<x;++i){
		for(int j=i+1;j<x;++j)  { 
			if(k[i]>k[j]) { 
				flag = 1;	//Kelimenin sirali olup olmadigini kontrol ediyor.
			} 		
		} 				
     }
	   
    if(flag==0) { cout << "Kelime Mukkemmel Halde"; return; }//Siraliysa fonksiyon bitiyor.
    
    //Ikili harf degisimi yapan kisim.
	for(int i=0;i<x;++i){
	 	if(y<2) { break; }
	 	if(bulunuyormu(secilenler,i)) { continue; }
	 	deger = k[i];
	 	point1 = i;
	 	point2 = i;
	 	flag=0;		
	 	for(int j=i+1;j<x;++j){
	 		if(bulunuyormu(secilenler,j)) { continue; }
	 		if(deger>k[j]){
	 			deger = k[j];
	 			point2 = j;
	 			flag=1;
				}						
			if(deger==k[j]&&flag==1){
				deger = k[j];
				point2 = j;
				}
			 }
		if(flag==1){
		secilenler.push_back(point1);
		secilenler.push_back(point2);
		yazilacakSecilenler.push_back(point1);
		yazilacakSecilenler.push_back(point2);
		y=y-2;
		++z;
	   } 
	 }
	 	  
	for(int i = 0; i< x; ++i) { if(bulunuyormu(secilenler,i)) { k3[i] = ' '; } else{ k3[i] = k[i]; } }

	
	for(int i=0;i<x;++i){
	    if(z==0) { break; }
	 	if(k3[i]==' '){
	 		donen d = kucuk(secilenler,k);
	 		k3[i] = d.deger;
	 		secilenler.erase(secilenler.begin()+d.index);
	 		z--;
	 		point1 =  i;
		 }
	 } 

	 flag = 0;
	 flag2 = 0;
	 //2'li harf degisimi bittikten sonra hala secilmesi gereken eleman varsa-
	 //en iyi sonucu vericek sekilde eleman secen kisim.
	 while(y>0){
	 	if(flag==0){
			for(int  i =point1+1; i<x;++i){
				if(k3[i]==' '){
					donen d = kucuk(secilenler,k);
					deger = d.deger;
					for(int j=i+1;j<x;++j){
						if(k3[j]!=' '&&deger>k3[j]){
							deger = k[j];
							point2 = j;
							flag2 = 1;
						}
					}
					if(flag2==1){
						k3[point2] = ' ';
						secilenler.push_back(point2);
						yazilacakSecilenler.push_back(point2);
						y--;
						break;
					}
				}
				else{
					if(buyukmu(secilenler,k,k3[i])){
						secilenler.push_back(i);
						yazilacakSecilenler.push_back(i);
						k3[i] = ' ';
						flag2 = 1;
						y--;
						break;
					}
				}
			}
	    }
			
	  	if(flag2==0){
	 	for(int i=x-1; i>0 ;i--){
	 	if(k3[i] != ' '&&!bulunuyormu(secilenler,i)){
	 	secilenler.push_back(i);
	 	yazilacakSecilenler.push_back(i);
	 	k3[i] = ' ';
		y--;
		flag = 1;																		
	 	break;
		   }
		 }
	   }
	   flag2=0;  
	}
	//Secilen elemanlari en iyi sekilde yerine koyan kisim.
	for(int i=0;i<x;++i){
		if(secilenler.size()<1){ break; }
		if(k3[i]==' '){
		    donen d = kucuk(secilenler,k);
		 	k3[i] = d.deger;
		 	secilenler.erase(secilenler.begin()+d.index);
			}
		}
	cout<<"\nKelimenin Onceki Hali:"<<endl;
	yazdirKelime(k,x);
	cout<<"\nKelimenin Yeni Hali:"<<endl;
	yazdirKelime(k3,x);
	cout<<"\nSecilen Harflerin Index'i:"<<endl;
	yazdir(yazilacakSecilenler);
}

	
int main() {
	int uzunluk,K=0;
	cout <<"Giriceginiz Kelimenin Uzunlugunu Girin:"<<endl;
	cin >> uzunluk;
	char kelime[uzunluk];
	while(K<2){
	cout << "K Sayisini Giriniz(2 den buyuk girin.)"<<endl;
	cin >> K;
	}
	cout <<"Kelimeyi Girin"<<endl;
	cin >> kelime;
	karakterSecme(kelime,uzunluk,K);	
	return 0;
}

