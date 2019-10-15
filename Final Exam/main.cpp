#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void convertToLowercase(string &x){
	for(int i = 0; i<x.length();++i){
		if(isupper(x[i])){ x[i] = tolower(x[i]);}
	}
}

vector<string> dosyaOkuma(string y){
	vector<string> x;
	ifstream okuyucu;
	string line;
	okuyucu.open(y.c_str());
	while(getline(okuyucu,line)){ 
		x.push_back(line);
      }
      okuyucu.close();
	for(int i = 0;i<x.size();++i){
		convertToLowercase(x.at(i));
	  }
	return x;
}


string vectorToString(vector<char> x){
	char donen[x.size()];
	for(int i = 0; i<x.size();++i){ donen[i] = x.at(i);}
	return donen;
}

map<int,string> kelimeAyirma(vector<string> x){
	string kelime;
	map<int,string> dicti;
	int mapDeger = 0;
	vector<char> really;
	for(int i = 0; i<x.size();++i){
		for(int j = 0; j<x.at(i).length();++j){
			if(x.at(i)[j]>=32&&x.at(i)[j]<=47){
			    kelime = vectorToString(really);
				really.clear();
				dicti[mapDeger++] = kelime;	
			}
			else if(j+1 == x.at(i).length()){
				really.push_back(x.at(i)[j]);
				kelime = vectorToString(really);
				really.clear();
				dicti[mapDeger++] = kelime;
			}
			else{
				if(x.at(i)[j]<97||x.at(i)[j]>123){continue;}
				really.push_back(x.at(i)[j]);}
		}
	}
	return dicti;
}


int main(){
	
	map<int,string> dicti;
	map<int,string>::iterator it;
	vector<string> lines,lines2;
	string line,line2;
	cout<<"Dosya Adini Giriniz:"<<endl;
	cin>>line;
	cout<<"Yazim Denetlemesi Yapilacak Dosyanin Adini Girinzi:"<<endl;
	cin>>line2;
	lines = dosyaOkuma(line);
	lines2 = dosyaOkuma(line2);	

	dicti = kelimeAyirma(lines);
	for(it = dicti.begin();it!=dicti.end();++it){
		cout<<it->first<<"\t";
	cout<<it->second<<endl;
	}
	cout<<dicti[2].length();	
	
}





