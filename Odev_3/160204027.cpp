#include<iostream> 													//Mehmet BÝR 160204027
#include<list> 
#include<vector>
#include<conio.h>
using namespace std;  

void menuFonk();
class dersProgrami{
public:
	bool flag;																						
	int dersSayisi;																				
	vector<int> dersler;	
	vector<int> *adj;
	void DFSUtil(int v,bool visited[]);
	dersProgrami(int x);																	//2. Soru Icin Class Tanýmlamam
	void addEdge(int v,int w);																//Kendi DFS'inide Burda Barýndýrýyor.
	void DFS(int x);
	void printEdge();
};


dersProgrami::dersProgrami(int x){
	this->dersSayisi=x;
	this->flag=true;
	adj = new vector<int>[x];
}

void dersProgrami::addEdge(int v,int w){ 
	adj[v].push_back(w); 
}

void dersProgrami::DFSUtil(int v, bool visited[]){;
	visited[v] = true;
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i){
		if(visited[*i])  {this->flag=false;}
		if(!visited[*i]&&flag) { DFSUtil(*i,visited); }
	}		
}

void dersProgrami::DFS(int x){
	bool *visited = new bool[dersSayisi];
	for(int i=0;i<dersSayisi;++i){ visited[i]=false; }
	DFSUtil(x,visited);
	if(!flag) { cout <<"Can Butun Dersleri Alamayacak (Grafda Cycle Var)"<<endl; }
	else{ cout << "Can Butun Dersleri Alabilir (Grafda Cycle Yok)"<<endl; }
}
	
class Sehir{
public:
	bool flag;
	int graphNum,dusme,kor1,kor2;
	vector<int> yukseklik;
	vector<int> *adj;
	void DFSUtil(int v, bool visited[]);													//1. Soru Icin Class Tanýmlamam
	Sehir(int x1,int x2,int x3);															
	void addEdge(int v, int w);
	void DFS(int x);
	void printEdge();
};
																							
Sehir::Sehir(int x1,int x2,int x3){
	this->flag=true;
	this->kor1=x1;
	this->kor2=x2;
	this->graphNum=x1*x2;
	this->dusme=x3;
	adj = new vector<int>[x1*x2];
}

void Sehir::addEdge(int v,int w){ 
	adj[v].push_back(w); 
}

void Sehir::DFSUtil(int v,bool visited[]){
	int k1,k2;
	visited[v] = true;
	k1=v/this->kor2;
	k2=v%this->kor2;
	cout << k1+1 <<","<<k2+1<<" ";
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i){
		if(!visited[*i]&&yukseklik.at(v)-yukseklik.at(*i)<=dusme&&yukseklik.at(v)>=yukseklik.at(*i)&&flag) { DFSUtil(*i,visited); }
		if(i+1==adj[v].end()){ this->flag=false; }
	}	
}

void Sehir::DFS(int x){
	bool *visited = new bool[graphNum];
	for(int i=0;i<x;++i){ visited[i]=false; }
	cout<<"Canin Gezdigi Koordinatlar"<<endl;
	DFSUtil(x,visited);
}

void Sehir::printEdge(){
	for(int i =0;i<graphNum;i++){
		cout<<i;
		for(int j=0; j<adj[i].size();++j){
			cout<<"->"<<adj[i].at(j);
		}
		cout << endl;
	}	
}


void soru1Fonk(){
	int x1,x2,yukseklik,graphNum=0,dus,k1,k2,k3;
	cout << "Matrisin Satir ve Sutun Degerlerini Girin (Arada Bosluk Birakin):"<<endl;
	cin >>x1>>x2;
	cout << "Canin Dusebilecegi Yuksekligi Giriniz:"<<endl;
	cin >>dus;
	Sehir sehir(x1,x2,dus);
	int matris[x1][x2];
	for(int i = 0;i<x1;++i){
		for(int j=0;j<x2;++j){
			cout << i+1 <<". Satirin " << j+1 << ". Sutunundaki Sehrin Yuksekligini Girin:"<<endl;
			cin >> yukseklik;
			sehir.yukseklik.push_back(yukseklik);
			matris[i][j] = yukseklik; 
			}
	}
	cout<< "Sehir:"<<endl;
	for(int i=0;i<x1;++i){
		for(int j=0;j<x2;++j){
			cout << matris[i][j]<<" ";
		}
		cout <<endl;
	}
	for(int i=0;i<x1;++i){
		for(int j=0;j<x2;++j){
			if(j+1<x2) { sehir.addEdge((x2*i)+j,(x2*i)+j+1); }
			if(i+1<x1) { sehir.addEdge((x2*i)+j,((x2)*(i+1))+j); }
			if(j-1>=0) { sehir.addEdge((x2*i)+j,(x2*i)+j-1); }
			if(i-1>=0) { sehir.addEdge((x2*i)+j,((x2)*(i-1))+j); }
		}
	}
	cout << "Canin Bulundugu Koordinati Giriniz: (1,1 ile N,M)(Arada Bosluk Birakin):"<<endl;
	cin >> k1>>k2;
	sehir.DFS(((k1-1)*x1)+(k2-1));
	cout <<"\n Menuye Donmek Icin Bir Tusa Basin";
	getch();
	return menuFonk();	
}

int returnIndex(vector<int>x,int y){
	for(int i=0;i<x.size();++i){ if(x.at(i)==y) { return i; }}
	return -1;
}


void soru2Fonk(){
	int dersSayisi,x1,x2,onKosul,ders;
	cout << "Canin Programindaki Ders Sayisini Giriniz:"<<endl;
	cin >> dersSayisi;
	dersProgrami caninProgrami(dersSayisi);
	cout <<"Ders Kodlarini Giriniz:"<<endl;
	for(int i = 0; i <dersSayisi;++i ){
		cout<< i+1<<". Dersi Giriniz:"<<endl;
		cin >> ders;
		caninProgrami.dersler.push_back(ders);
	}
	
	cout << "On Kosullu Ders Sayisini Giriniz(M Sayisi):"<<endl;
	cin >> onKosul;
    for(int i = 0; i<onKosul; ++i){
    	cout << i+1<<". Ders Ciftini Giriniz:(Ders Onkusulu-Ders Arada Bosluk Birakin)"<<endl;
    	cin >>x1>>x2;
    	caninProgrami.addEdge(returnIndex(caninProgrami.dersler,x1),returnIndex(caninProgrami.dersler,x2));
	}
	caninProgrami.DFS(0);
	cout <<"\nMenuye Donmek Icin Bir Tusa Basin... ";
	getch();
	return menuFonk();

}

void menuFonk(){
	int m;
	system("cls");
	cout << "Menu: ***"<<endl;
	cout <<"1. Soru:"<<endl;
	cout <<"2. Soru:"<<endl;
	cout <<"3--Exit"<<endl;
	cout <<" Yapmak Istediginiz Islemin Numarasini Giriniz:"<<endl;
	cin>>m;
	switch(m){
		case 1:soru1Fonk();
		case 2:soru2Fonk();
		case 3:exit(1);
		default:cout<<"Islem Numarasi Girmeliydiniz... Menuye Donmek Icin Bir Tusa Basin";getch();return menuFonk();
	}
}

int main() { menuFonk(); return 0; } 

