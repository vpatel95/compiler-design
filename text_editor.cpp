#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void write_file(char *str){
	ofstream out;
	char data[100];
	
	out.open(str, ios::out | ios::app);	
	cout<<"File created"<<endl;
	
	cout<<"Enter the data to be entered in file"<<endl;
	cin.ignore();
	cin.getline(data, 100);
	
	out<<data<<endl;
}

void seperate_file(char *str) {
	int i=-1;
	ifstream in;
	ofstream outV, outC;
	char data, a[100];
	in.open(str, ios::in);
	outV.open("vowels.txt", ios::out);
	outC.open("consonants.txt", ios::out);
	while(!in.eof()){
		in.get(data);
		if(data == 'a' || data == 'e' || data == 'i' || data == 'o' || data == 'u' || data == 'A' || data == 'E' || data == 'I' || data == 'O' || data == 'U'){
			outV<<data<<" ";
		} else {
			outC<<data<<" ";
		}
	}
	/*for(j=0;j<i;j++) {
		if(a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' || a[j] == 'u') {
			outV<<a[j]<<" ";
		} else {
			outC<<a[j]<<" ";
		}
	}*/
}

void delete_file(char *str) {
	if(remove(str)!=0)
		cout<<"Error deleteing file!";
	else
		cout<<"file successfully deleted!";
}

int main() {
	char file[100];
	int choice;
	cout<<"Enter the file name : ";
	gets(file);
	cout<<endl<<"1. Write"<<endl<<"2. Read"<<endl<<"3. Delete"<<endl;
	cin>>choice;
	switch(choice) {
		case 1: {
			write_file(file);
			break;
		}
			
		case 2: {
			seperate_file(file);
			break;
		}
		case 3: {
			remove(file);
			break;
		}
		default : {
			cout<<"wrong input";break;	
		}
	}
	
}
