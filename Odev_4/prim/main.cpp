#include<bits/stdc++.h> 
#include <iostream>

using namespace std; 
# define INF 0x3f3f3f3f 
  
typedef pair<int, int> iPair; 
  
class Graph 
{ 
    int V;  
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V); 
    void addEdge(int u, int v, int w); 
    void primMST(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
void Graph::primMST() 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    int src = 0;
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false); 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        printf("\n%d\n",u);
        pq.pop(); 
        inMST[u] = true;  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            if (inMST[v] == false && key[v] > weight) 
            { 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  	cout << "Prim Algoritmasi Ile Minumum Cost Spining Tree Edgeleri\n";
    for (int i = 1; i < V; ++i) { printf("%d - %d\n", parent[i]+1, i+1);} 
} 
 
int main() 
{ 
	int v,edge,agirlik,e1,e2;
	cout << "Grafin Vertex Sayisini Giriniz:\n";
	cin >>v;
	Graph g(v);
	cout << "Grafin Edge Sayisini Giriniz:\n";
	cin >>edge;
	for(int i =0; i < edge;i++){
		cout << i+1 << ". Edgeyi Girin Arada Bosluk Birakin (Vertexler 1 Den Basliyor):\n";
		cin >> e1 >> e2;
		e1= e1-1;
		e2= e2-1;
		cout << "\nEdgenin Agirligini Girin:";
		cin >> agirlik;
		g.addEdge(e1,e2,agirlik);
	}
    g.primMST(); 
  
    return 0; 
} 

