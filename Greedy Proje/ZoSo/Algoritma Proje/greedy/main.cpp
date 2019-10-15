#include <bits/stdc++.h> 
using namespace std; 
#define MAX_CHAR 26 

void findOrder(vector<string> v) 
{ 
	int n = v.size(); 
	if (n == 1) { 
		cout << "abcdefghijklmnopqrstuvwxyz"; 
		return; 
	} 

	/* Adjacency list of 26 characters*/
	vector<int> adj[MAX_CHAR]; 
	/* Array tracking the number of edges that are 
	inward to each node*/
	vector<int> in(MAX_CHAR, 0); 

	// Traverse through all words in given array 
	string prev = v[0]; 

	/* (n-1) loops because we already acquired the 
	first word in the list*/
	for (int i = 1; i < n; ++i) { 
		string s = v[i]; 

		/* Find first such letter in the present string that is different 
		from the letter in the previous string at the same index*/
		int j; 
		for (j = 0; j < min(prev.length(), s.length()); ++j) 
			if (s[j] != prev[j]) 
				break; 

		if (j < min(prev.length(), s.length())) { 

			/* The letter in the previous string precedes the the one 
			in the present string, hence add the letter in the present 
			string as the child of the letter in the previous string*/
			adj[prev[j] - 'a'].push_back(s[j] - 'a'); 

			/* The number of inward pointing edges to the node representing 
			the letter in the present string increases by one*/
			in[s[j] - 'a']++; 

			/* Assign present string to previous string for the next 
			iteration. */
			prev = s; 
			continue; 
		} 

		/* If there exists no such letter then the string length of 
		the previous string must be less than or equal to the 
		present string, otherwise no such order exists*/
		if (prev.length() > s.length()) { 
			cout << "Impossible"; 
			return; 
		} 

		/* Assign present string to previous string for the next 
		iteration */
		prev = s; 
	} 

	/* Topological ordering requires the source nodes 
	that have no parent nodes*/
	stack<int> stk; 
	for (int i = 0; i < MAX_CHAR; ++i) 
		if (in[i] == 0) 
			stk.push(i); 

	/* Vector storing required order (anyone that satisfies) */
	vector<char> out; 

	/* Array to keep track of visited nodes */
	bool vis[26]; 
	memset(vis, false, sizeof(vis)); 

	/* Standard DFS */
	while (!stk.empty()) { 

		/* Acquire present character */
		char x = stk.top(); 
		stk.pop(); 

		/* Mark as visited */
		vis[x] = true; 

		/* Insert character to output vector */
		out.push_back(x + 'a'); 

		for (int i = 0; i < adj[x].size(); ++i) { 
			if (vis[adj[x][i]]) 
				continue; 

			/* Since we have already included the the present 
			character in the order, the number edges inward 
			to this child node can be reduced*/
			in[adj[x][i]]--; 

			/* If the number of inward edges have been removed, 
			we can include this node as a source node*/
			if (in[adj[x][i]] == 0) 
				stk.push(adj[x][i]); 
		} 
	} 

	/* Check if all nodes(alphabets) have been visited. 
	Order impossible if any one is unvisited*/
	for (int i = 0; i < MAX_CHAR; ++i) 
		if (!vis[i]) { 
			cout << "Impossible"; 
			return; 
		} 

	for (int i = 0; i < out.size(); ++i) 
		cout << out[i]; 
} 

// Driver code 
int main() 
{ 
	vector<string> v;
	v.push_back("efgh");
	v.push_back("abcd");
	findOrder(v); 
	return 0; 
} 

