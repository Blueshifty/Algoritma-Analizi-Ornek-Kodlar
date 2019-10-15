#include <stdio.h> 
#include <limits.h> 
#include <stdbool.h>  
#include <vector>

using namespace std;


int minKey(int key[], bool mstSet[],int V) 
{ 
int min = INT_MAX, min_index; 
for (int v = 0; v < V; v++) 
    if (mstSet[v] == false && key[v] < min) 
        min = key[v], min_index = v; 
return min_index; 
} 
  
int printMST(int parent[], int V, vector<vector<int> >graph)
{ 
printf("Edge \tWeight\n"); 
for (int i = 1; i < V; i++) 
    printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
  

void primMST(vector<vector<int> > graph,int V) 
{ 
    int parent[V];  
    int key[V];  
    bool mstSet[V];  
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0;      
    parent[0] = -1; 
    for (int count = 0; count < V-1; count++) 
    { 
        int u = minKey(key, mstSet,V); 
        mstSet[u] = true; 
        for (int v = 0; v < V; v++) 
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
            parent[v] = u, key[v] = graph[u][v]; 
    } 
    printMST(parent, V, graph); 
} 
int main() 
{ 
int V,Edge,agirlik,e1,e2;
vector<vector<int> > graph;
vector<int> gecici; 
printf("Vertex Sayisini Giriniz\n");
scanf("%d",&V);
for(int i=0;i<V;++i){
	for(int j=0;j<V;++j){
		gecici.push_back(0);
	}
	graph.push_back(gecici);
	gecici.clear();
}

printf("Edge Sayisini Giriniz\n");
scanf("%d",&Edge);
for(int i =0;i<Edge;++i){
	printf("%d. Edge'i Giriniz(Arada Bosluk Birakin Vertex 1den Basliyor):\n",i+1);
	scanf("%d %d",&e1,&e2);
	printf("%d. \nEdgenin Agirligini Giriniz:",i+1);
	scanf("%d",&agirlik);
	graph[e1-1][e2-1] = agirlik; 	
}

    primMST(graph,V); 
  
    return 0; 
} 
