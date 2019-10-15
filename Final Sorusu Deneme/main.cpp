#include <iostream>
#include <vector>
#include <conio.h>				//Blueshifty GitHub

using namespace std;

vector<vector<int> > kombinasyonlar;	//All Combinations Are Saved In This Vector	

void print(){
	for(int i = 0;i<kombinasyonlar.size();++i){
		cout<<i+1<<"-";	
		for(int j = 0;j<kombinasyonlar.at(i).size();++j){
			cout<<" "<<kombinasyonlar.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
}
					
void exhaustiveFonk(vector<int> x,int iterator,vector<int> eleman){
	if(iterator==x.size()){kombinasyonlar.push_back(eleman);return;}
	vector<int>eleman2 = eleman;				//Combination Recursive Fonk
	eleman2.push_back(x.at(iterator));			
	exhaustiveFonk(x,iterator+1,eleman2);
	exhaustiveFonk(x,iterator+1,eleman);
}

int toplam(vector<int> x){
	int toplam = 0;
	for(int i = 0; i<x.size();++i){
		toplam += x.at(i);
	}
	return toplam;
}


void yazdir(vector<int> x){
	cout<<endl;
	for(int i = 0; i<x.size();++i){
		cout<<x.at(i)<<" ";
	}
}


int main(){
	int n,girdi,x,y;
	vector<int> A;	//Vector that you want to combinate	
	vector<int> nothing;
    	cout <<"--Enter the lenght of the Vector:";
		cin >> n;
		for(int i =0;i<n;++i){
			cout <<"--Enter the  " << i+1<< ". Element:";
			cin >>girdi;
			A.push_back(girdi);
	  	}
	  	exhaustiveFonk(A,0,nothing);
	  	print();
	  	vector<int> toplams;
	  	for(int i = 0; i<kombinasyonlar.size();++i){
			for(int j = 0; j<kombinasyonlar.size();++j){
	  			x = toplam(kombinasyonlar.at(i));
	  			y = toplam(kombinasyonlar.at(j));
	  			if(x==y && i != j){
				toplams.push_back(i);
	  			toplams.push_back(j);
			  }
		  }
	  	}
	  	for(int i = 0,j=1; i<toplams.size();i+=2,j++){
	  		cout<<"\n"<<j<<". toplam"<<endl;
	  		yazdir(kombinasyonlar.at(toplams.at(i)));
	  		yazdir(kombinasyonlar.at(toplams.at(i+1)));
		  }
	  	
	return 0;	
}

