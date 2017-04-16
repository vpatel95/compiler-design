#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int is_keywords(string str){
	ifstream in;
	int i=0;
	string* keywords = new string[500];
	in.open("keywords.txt", ios::in);
	while(!in.eof()) {
		getline(in,keywords[i++],'\n');
	}
	
	int n = i;
	for(i=0;i<n;i++){
		if(str==keywords[i])
			return 1;
	}
	return 0;
}




int main(){
	cout<<is_keywords("main");
	return 0;
}
