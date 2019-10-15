#include <iostream>			//Mehmet BÝR 160204027
#include <string>			 //1 For Herseyi Yapiyor :))
        								
using namespace std;

void fonk(string kelime){
	int deger = 0;
	for(int i = 0,j =1,k=1;k<kelime.length();++j,++i){
		if(j==kelime.length() || i==kelime.length()){
			cout<<kelime.substr(k,kelime.length()-k)<<"\t"<<deger<<endl;
			deger = 0;
			j = ++k -1;
			i = -1;
			continue;
		}
		if(kelime.at(i) != kelime.at(j)){
			cout<<kelime.substr(k,kelime.length()-k)<<"\t"<<deger<<endl;
			deger = 0;
			j= ++k-1;
			i= -1;
		}
		else{deger++;}
	}
}

int main(){
	string girdi;
	cout<<"String'i Girin"<<endl;
	cin>>girdi;
	fonk(girdi);
	return 0;
}
