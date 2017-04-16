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

void read_file(char *str) {
	ifstream in;
	char data[100];
	
	in.open(str, ios::in);
	in.get(data, 100);
	cout<<data<<endl;
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
			read_file(file);
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
