#include<iostream>
#include <vector>

using namespace std;

void Combination(vector<int> a, int reqLen, int start, int currLen, bool check[], int len,&vector<vector<int> >kombinasyonlar) 
{
	// Return if the currLen is more than the required length.
	if(currLen > reqLen)
	return;
	// If currLen is equal to required length then print the sequence.
	else if (currLen == reqLen) 
	{
		cout<<"\t";
		for (int i = 0; i < len; i++) 
		{
			if (check[i] == true) 
			{
				cout<<a[i]<<" ";
			}
		}
		cout<<"\n";
		return;
	}
	// If start equals to len then return since no further element left.
	if (start == len) 
	{
		return;
	}
	// For every index we have two options.
	// First is, we select it, means put true in check[] and increment currLen and start.
	check[start] = true;
	Combination(a, reqLen, start + 1, currLen + 1, check, len);
	// Second is, we don't select it, means put false in check[] and only start incremented.
	check[start] = false;
	Combination(a, reqLen, start + 1, currLen, check, len);
}
 
int main()
{
	vector<int> dizi;
	int i,n,k,girdi;
	cout<<"Dizinin Uzunlugunu, 'n' Sayisini Giriniz";
	cin>>n;
	vector<vector<int> > kombinasyonlar;
	cout<<endl;
	for(i = 0; i<n;++i)
	{
		cout<<"Dizinin "<<i+1<<". Elemanini Giriniz:";
		cin>>girdi;
		dizi.push_back(girdi);
		check[i] = false;
	}
	// For each length of sub-array, call the Combination().
	for(i = 1; i <= n; i++)
	{
		Combination(dizi, i, 0, 0, check, n,kombinasyonlar);
	}
	return 0;
}
