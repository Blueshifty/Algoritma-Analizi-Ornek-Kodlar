#include<iostream> 
#include <list>  
#include <conio.h>												//Algoritma Analizi Odev-2
#include <vector>												//Mehmet BÝR
#include <string>												//160204027
#include <algorithm>

using namespace std; 
void menuFonk();

class borisGraph{
	int vertex;
	vector<int> *adj;
public:
	borisGraph(int V);
	void addEdge(int v,int w);
	void printEdge();
	vector<vector<int> >borisBFS(vector<vector<int> >x,int s);
};

borisGraph::borisGraph(int V){
	this->vertex=V;
	adj = new vector<int>[vertex];
}

void borisGraph::addEdge(int v,int w){
	adj[v].push_back(w);
}

void borisGraph::printEdge(){
	for(int i = 0; i<vertex;++i){
		cout << i; 
		for(int j=0;j < adj[i].size();++j){
			cout <<"->"<<adj[i].at(j);
		}
		cout <<endl;
	}
}

vector<vector<int> >borisGraph::borisBFS(vector<vector<int> >x ,int s){
	vector<int> b;
	b.push_back(s);
	bool *visited = new bool[vertex];
	for(int i = 0; i < vertex; ++i){visited[i] = false;}
	list<int> queue;
	visited[s] =true;
	queue.push_back(s);
	vector<int>::iterator i;
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
				b.push_back(*i);
			}
		}
	}
	if(b.size()>1){x.push_back(b);}
	return x;
}


class Graph 
{ 
    int V;   
    vector<int> *adj;    
public: 
    Graph(int V);  
    void addEdge(int v, int w);  
	void uzaklik(int s);   
	int soru1Fonk(int s);
	int soru2Fonk(int s1,int s2);
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new vector<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
    adj[w].push_back(v);
} 
  
void Graph::uzaklik(int s){
	int uzaklik[V];
	for(int i = 0; i<V;++i)	{ uzaklik[i] = -1; }
	list<int> queue;
	uzaklik[s] = 0;
	queue.push_back(s);
	vector<int>::iterator i;
	while(!queue.empty()){
		s = queue.front();
		cout << s << "in uzakligi "<< uzaklik[s] << "\n";
		queue.pop_front();
		for(i = adj[s].begin(); i != adj[s].end(); ++i){
			if(uzaklik[*i] == -1){
				uzaklik[*i] = uzaklik[s] + 1;
				queue.push_back(*i);
			}
		}	
	}
}

int Graph::soru1Fonk(int s ){
	int uzaklik[V];
	for(int i = 0; i<V;++i) { uzaklik[i] = -1; }
	list<int> queue;
	uzaklik[s] = 0;
	queue.push_back(s);
	vector<int>::iterator i;
	while(!queue.empty()){
		s = queue.front();
		queue.pop_front();
		for(i = adj[s].begin(); i != adj[s].end(); ++i){
			if(uzaklik[*i] == -1){
				uzaklik[*i] = uzaklik[s] + 1;
				queue.push_back(*i);
			}
		}	
	}
	return uzaklik[V-1];
}


int Graph::soru2Fonk(int s1,int s2){
	int uzaklik[V],x=0;
	for(int i = 0; i<V;++i){ uzaklik[i] = -1;}
	list<int> queue;
	uzaklik[s1] = 0;
	queue.push_back(s1);
	vector<int>::iterator i;
	while(!queue.empty()){
		s1=queue.front();
		queue.pop_front();
		for(i = adj[s1].begin();i!=adj[s1].end();++i){
			if(uzaklik[*i] == -1){
				uzaklik[*i] = uzaklik[s1]+1;
				queue.push_back(*i);
			}
		}
	}	
for(int i = 0; i < V; ++i){if(uzaklik[i] == s2){ ++x; cout<<i<<" ";}}
return x;
}


void Soru1(){
	int x1=0,x2,g1,g2;
	cout << "Toplam Ada Sayisini Giriniz:";
	cin >> g1; 
	Graph r(g1);
    cout << "\nToplam Kopru Sayisini Giriniz:";
    cin >> x2;
    cout <<"\nKopru Girerken 0 dan Baslayin ve Arada Bosluk Birakin"<<endl;
    while(x1<x2){
    	cout <<x1+1<<". Kopruyu Giriniz:"<<endl;
    	cin >> g1;
    	cin >> g2;
    	r.addEdge(g1,g2);
    	++x1;
	}
    cout << "\n\n" << "Robinson'un Gecmesi Gereken En Az Kopru Sayisi:" << r.soru1Fonk(0);
    cout << "\nMenuye Donmek Icin Bir Tusa Basin..";
    getch();
    return menuFonk();
}


void Soru2(){
	int x1=0,x2,g1,g2;
	cout << "Toplam Node Sayisini Giriniz:";
	cin >> g1;
	Graph f(g1);
	cout << "\nToplam Edge Sayisini Giriniz:";
	cin >> x2;
	cout << "\n Edgeleri Girerken 0 dan Baslayin ve Arada Bosluk Birakin"<<endl;
	while(x1<x2){
		cout << x1+1<< ". Edgeyi Giriniz:"<< endl;
		cin >> g1;
		cin >> g2;
		f.addEdge(g1,g2);
		++x1;
	}
	cout << "\nSorgu Sayisini Giriniz:";
	cin >> g2;
	g1 = 0;
	while(g1<g2){
		cout <<"\n"<<g1+1 <<". Sorgu Icin Kaynak Node'u ve T Mesafesini Giriniz:";
		cin >> x1;
		cin >> x2;
		cout <<"\n"<<x1<<".Node a "<<x2<<" Mesafesinde "<<f.soru2Fonk(x1,x2)<<" Node Bulunuyor. "<<endl;
		if(g1+1<g2){cout << g1+2 << ". Sorguya Gecmek Icin Bir Tusa Basin...";}
		getch();
		++g1;  
	}
	cout <<"\nMenuye Donmek Icin Bir Tusa Basin";
	getch();
	return menuFonk();
}

void Soru3(){
	int N,M,test1=0,test2,z=1,vertex=0,son=0;
	cout << "Test Sayisini Giriniz:";
	cin >> test2;
	while(test1<test2){
		cout <<"\nSavas Alaninin Satir Sayisini Giriniz(N):";
		cin >> N;
		cout << "\nSavas Alaninin Sutun Sayisini Giriniz(M):";
		cin >> M;
		char girdi[M];
		int savasAlani[N][M];
		for(int i = 0;i<N;++i){
			cout << "\nSavas Alaninin " << i+1 << " . Satirini Giriniz:"<<endl;
			cin >> girdi;
		for(int j= 0;j<M;++j){
			savasAlani[i][j] = (int)girdi[j] - 48;
		    }
	   }
	for(int i= 0;i<N;++i){
		for(int j= 0;j<M;++j){
			if(savasAlani[i][j]==1){
				savasAlani[i][j] = z;
				++vertex;
				++z;
			}
   		}
  	}
  	borisGraph boris(vertex);
  	for(int i= 0;i<N;++i){
  		for(int j= 0;j<M;++j){
  			if(savasAlani[i][j]!=0){
  				 if(j+1<M&&savasAlani[i][j+1]!=0){
  				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i][j+1]-1);
				   }
				 if(i+1<N&&j+1<M&&savasAlani[i+1][j+1]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i+1][j+1]-1);
				 }
				 if(i+1<N&&savasAlani[i+1][j]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i+1][j]-1);
				 }
				 if(i+1<N&&j-1>=0&&savasAlani[i+1][j-1]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i+1][j-1]-1);
				 }
				 if(j-1>=0&&savasAlani[i][j-1]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i][j-1]-1);
				 }
				 if(i-1>=0&&j-1>=0&&savasAlani[i-1][j-1]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i-1][j-1]-1);
				 }
				 if(i-1>=0&&savasAlani[i-1][j]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i-1][j]-1);
				 }
				 if(i-1>=0&&j+1<M&&savasAlani[i-1][j+1]!=0){
				 	boris.addEdge(savasAlani[i][j]-1,savasAlani[i-1][j+1]-1);
				 }  		
			  }
		  }
	  }					
      int flag=0;
      vector<vector<int> >harita;
      for(int b=0;b<vertex;++b){
      	if(harita.empty()){
      		harita = boris.borisBFS(harita,b);
		 }
		  else{
      	for(int r=0;r<harita.size();++r){
      		if(find(harita.at(r).begin(), harita.at(r).end(),b) != harita.at(r).end()){
      			flag=1;
	 		}
		  }
		if(flag==0){
	 	harita = boris.borisBFS(harita,b);
		  }
        }
        flag=0;
      }
     for(int r = 0; r<harita.size();++r){
     	if(son<harita.at(r).size()){
     		son = harita.at(r).size();
		 }
	 }
     cout << "Zeti Ordularinin Sayisi:" << harita.size()<<endl;
	 cout << "Tek Atista Oldurulebilecek Maksimum Zeti Sayisi:"<< son<<endl;
	 ++test1;
	 cout << test1+1<<". Teste Gecmek Icin Bir Tusa Basin...";
	 getch();
	 harita.clear();
}
cout << "Ana Menuye Donmek Icin Bir Tusa Basin...";
return menuFonk();
}

void menuFonk(){
	int x;
	system("cls");
	cout << "*** MENU ***"<<endl;
	cout << "1. Soru"<<endl;
	cout << "2. Soru"<<endl;
	cout << "3. Soru"<<endl;
	cout << "4 -Exit" << endl;
	cout << "Yapmak Istediginiz Islemin Numarasini Girin:";
	cin >> x;
	switch(x){
		case 1: system("cls"); Soru1();
		case 2: system("cls"); Soru2();
		case 3: system("cls"); Soru3();
		case 4: return;
		default: cout << "Islem Numarasi Girmeliydiniz Menuye Donmek Icin Bir Tusa Basin";  cin.ignore(); getch(); return menuFonk();		
	}
}

int main(){menuFonk(); return 0;} 

