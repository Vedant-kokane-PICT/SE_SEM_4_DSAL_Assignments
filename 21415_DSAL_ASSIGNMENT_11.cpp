//============================================================================
// Name        : Assignment_11.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string.h>
#define m 10
using namespace std;


class Student{
public:
	int roll;
	string name;
	int division;
	string address;
public:
	Student(){
		roll = 0;
		name = "----";
		division = 0;
		address = "----";
	}

	Student(int r,string n,int d,string a){
		roll = r;
		name = n;
		division = d;
		address = a;
	}
	void add(){
		cout<<"Enter roll no - "<<endl;
		cin>>roll;
		cout<<"Enter name - "<<endl;
		cin>>name;
		cout<<"Enter division - "<<endl;
		cin>>division;
		cout<<"Enter address - "<<endl;
		cin>>address;
	}
	friend class File;
};

class File{
	Student s1[m];
	int i;
public:
	File(){
		i = 0;
	}
	void createRecord(){
		int n;
		cout<<"Enter total records  - "<<endl;
		cin>>n;
		for(int j=0;j<n;j++){
			s1[i].add();
			i++;
		}
		fstream obj;
		obj.open("file.txt",ios::out);
		if(!obj){
			cout<<"Error in opening file"<<endl;
		}
		else{
			for(int j=0;j<i;j++){
				obj<<"Record - "<<j+1<<endl;
				obj<<"Name - "<<s1[j].name<<endl;
				obj<<"Roll no - "<<s1[j].roll<<endl;
				obj<<"Division - "<<s1[j].division<<endl;
				obj<<"Address - "<<s1[j].address<<endl;
				cout<<endl;
			}
		}
		obj.close();
	}

	void display(){
		fstream obj;
		obj.open("file.txt",ios::in);
		if(!obj){
			cout<<"Error in opening file"<<endl;
		}
		else{
			string buffer;
			while(getline(obj,buffer)){
				cout<<buffer<<endl;
			}
		}
		obj.close();
	}

	void search(){
		string name;
		cout<<"Enter name - "<<endl;
		cin>>name;
		string s1 = "Name - " + name;
		fstream obj;
		obj.open("file.txt",ios::in);
		if(!obj){
			cout<<"Error in opening file"<<endl;
		}
		else{
			string buffer;
			while(getline(obj,buffer)){
				if(s1 == buffer){
					cout<<"Record is present"<<endl;
					return;
				}
			}
		}
		cout<<"Record is not present"<<endl;
		obj.close();
	}

	void deleteRecord(){
		string name1;
		cout<<"Enter name - "<<endl;
		cin>>name1;
		string st1 = "Name - " + name1;
		fstream obj;
		obj.open("file.txt",ios::in);
		bool present = 0;
		if(!obj){
			cout<<"Error in opening file"<<endl;
		}
		else{
			string buffer;
			while(getline(obj,buffer)){
				if(st1 == buffer){
					cout<<"Record is present"<<endl;
					present = 1;
					break;
				}
			}
			obj.close();
			if(present){
				int k;
				for(int j=0;j<i;j++){
					if(s1[j].name == name1){
						k = j;
					}
				}
				for(int j=k;j<i;j++){
					s1[j] = s1[j+1];
				}
				i--;
				fstream obj;
				obj.open("file.txt",ios::out);
				for(int j=0;j<i;j++){
					obj<<"Record - "<<j+1<<endl;
					obj<<"Name - "<<s1[j].name<<endl;
					obj<<"Roll no - "<<s1[j].roll<<endl;
					obj<<"Division - "<<s1[j].division<<endl;
					obj<<"Address - "<<s1[j].address<<endl;
					cout<<endl;
				}
				cout<<"Record has been deleted"<<endl;
				obj.close();
			}
		}
		if(present == 0){
			cout<<"Record does not exist"<<endl;
		}
	}

	void addRecord(){
		s1[i].add();
		i++;
		fstream obj;
		obj.open("file.txt",ios::out);
		if(!obj){
			cout<<"Error in opening file"<<endl;
		}
		else{
			for(int j=0;j<i;j++){
				obj<<"Record - "<<j+1<<endl;
				obj<<"Name - "<<s1[j].name<<endl;
				obj<<"Roll no - "<<s1[j].roll<<endl;
				obj<<"Division - "<<s1[j].division<<endl;
				obj<<"Address - "<<s1[j].address<<endl;
				cout<<endl;
			}
		}
		obj.close();
	}
};


int main() {
	File f1;
	char ch = 'y';
	while(ch != 'n'){
		cout<<"-----------------------------"<<endl;
		cout<<"1. Add all records"<<endl;
		cout<<"2. Display all records"<<endl;
		cout<<"3. Search for an record"<<endl;
		cout<<"4. Delete an record"<<endl;
		cout<<"5. Add a new record"<<endl;
		cout<<"-----------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			f1.createRecord();
		}
		else if(c==2){
			f1.display();
		}
		else if(c==3){
			f1.search();
		}
		else if(c==4){
			f1.deleteRecord();
		}
		else if(c==5){
			f1.addRecord();
		}
		else{
			cout<<"You have entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n) -"<<endl;
		cin>>ch;
	}
	return 0;
}
