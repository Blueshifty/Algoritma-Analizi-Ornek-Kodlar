#include<bits/stdc++.h> 
#include <iostream>
using namespace std; 
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair; 						//Mehmet Bir 160204027
  		  														
class Graph { 
    int V;  
    list< pair<int, int> > *adj; 
public: 									//Prim Algoritmasi Icin Graf Sinifi
    Graph(int V); 
    void addEdge(int u, int v, int w); 
    void primMST(); 
}; 
  
  
Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
  
void Graph::addEdge(int u, int v, int w) { 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
  
void Graph::primMST() { 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    int src = 0;
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()){ 
        int u = pq.top().second; 
        pq.pop(); 
        inMST[u] = true;  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
            int v = (*i).first; 
            int weight = (*i).second; 									//Prim Algoritmasi
            if (inMST[v] == false && key[v] > weight) { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  	cout << "Prim Algoritmasi Ile Minumum Cost Spining Tree Edgeleri\n";
    for (int i = 1; i < V; ++i) { printf("%d - %d\n", parent[i]+1, i+1);} 
} 
 
 
 struct GraphK{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
    GraphK(int V, int E){ 
        this->V = V; 
        this->E = E; 
    } 
    void addEdge(int u, int v, int w) { 								  //Kruskal Algoritmasi Icin Graf Sinifi
        edges.push_back({w, {u, v}}); 
    } 
    int kruskalMST(); 
};


struct DisjointSets{ 
    int *parent, *rnk; 
    int n; 
    DisjointSets(int n){ 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
        for (int i = 0; i <= n; i++){ 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
    int find(int u) { 
        if (u != parent[u]) { parent[u] = find(parent[u]); } 
        return parent[u]; 
    } 
    void merge(int x, int y) { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y])  { parent[y] = x; } else { parent[x] = y; }  
        if (rnk[x] == rnk[y]){ rnk[y]++; } 
    } 
}; 


int GraphK::kruskalMST(){ 
    int mst_wt = 0; 
    sort(edges.begin(), edges.end());  
    DisjointSets ds(V); 
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++){ 									//Kruskal Algoritmasi
        int u = it->second.first; 
        int v = it->second.second; 
        int set_u = ds.find(u); 
        int set_v = ds.find(v);  
        if (set_u != set_v) {  
            cout << u+1 << " - " << v+1 << endl; 
            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 
    return mst_wt; 
}
 
int main(){ 
	int v,edge,agirlik,e1,e2;
	cout << "Grafin Vertex Sayisini Giriniz:\n";
	cin >>v;
	Graph g(v);
	cout << "Grafin Edge Sayisini Giriniz:\n";
	cin >>edge;
	GraphK g2(v,edge);
	for(int i =0; i < edge;i++){
		cout << i+1 << ". Edgeyi Girin Arada Bosluk Birakin (Vertexler 1 Den Basliyor):"<<endl;
		cin >> e1 >> e2;
		e1= e1-1;
		e2= e2-1;													//Graflarin Olusumu
		cout << i+1 <<".Edgenin Agirligini Girin:"<<endl;;
		cin >> agirlik;
		g.addEdge(e1,e2,agirlik);
	    g2.addEdge(e1,e2,agirlik);
	}
    g.primMST();
    cout << "Kruskal Algoritmasi Ile Minumum Cost Spining Tree Edgeleri"<<endl;
    int x = g2.kruskalMST();
    cout <<" \nKruskal ve Prim Spining Tree Edgeleri Yazilirken Edgeler Ayni Ama Gosterimleri Farkli Olabilir Cunku Graf Yonsuz,\n(1-2) ile (2-1) Gibi"<< endl;
    cout <<"Edgelerin Siralarinin Farkli Olma Sebebi Kruskal Edgelerden Secim Yaparken Prim Dugumleri Geziyor"<< endl;
    return 0; 
} 
