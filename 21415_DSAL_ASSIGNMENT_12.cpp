//============================================================================
// Name        : Assignment_12.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;

class File{
	int id,salary,experience;
	string name;
	int index, address[10];
public:
	File(){
		id = 0;
		salary = 0;
		experience = 0;
		name = "----";
		index = 0;
	}

	void addRecord(){
		int n;
		cout<<"Enter total records"<<endl;
		cin>>n;
		ofstream out;
		out.open("file.txt",ios::out);
		for(int i=0;i<n;i++){
			cout<<"Enter Employee's id, name , salary , experience (years) - "<<endl;
			cin>>id>>name>>salary>>experience;
			int pointer = out.tellp();
			address[index] = pointer;
			index++;
			out<<"Record - "<<index<<", id - "<<id<<", name - "<<name<<", salary - "<<" "<<salary<<", experience - "<<experience<<endl;
		}
	}


	void searchRecord(){
		int n;
		cout<<"Enter record no "<<endl;
		cin>>n;
		n--;
		int position = address[n];
		ifstream in;
		in.open("file.txt",ios::in);
		in.seekg(position,ios::beg);
		string s;
		getline(in, s);
		cout<<s<<endl;
	}

	void displayRecord(){
		for(int i=0;i<index;i++){
			int position = address[i];
			ifstream in;
			in.open("file.txt",ios::in);
			in.seekg(position,ios::beg);
			string s;
			getline(in, s);
			cout<<s<<endl;
		}
	}

	void deleteRecord(){
		int n;
		cout<<"Enter record no that to be deleted "<<endl;
		cin>>n;
		n = n - 1;
		for(int i=n;i<index;i++){
			address[i] = address[i+1];
		}
		index--;
	}

};


int main() {
	File f1;
	char ch = 'y';
	while(ch != 'n'){
		cout<<"-----------------------------"<<endl;
		cout<<"1. Add records"<<endl;
		cout<<"2. Display all records"<<endl;
		cout<<"3. Search for an record"<<endl;
		cout<<"4. Delete an record"<<endl;
		cout<<"-----------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			f1.addRecord();
		}
		else if(c==2){
			f1.displayRecord();
		}
		else if(c==3){
			f1.searchRecord();
		}
		else if(c==4){
			f1.deleteRecord();
		}
		else{
			cout<<"You have entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n) -"<<endl;
		cin>>ch;
	}
	return 0;
}
