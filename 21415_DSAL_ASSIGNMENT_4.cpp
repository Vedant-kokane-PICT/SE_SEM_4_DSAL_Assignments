//============================================================================
// Name        : Assignment_4.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
#define m 10

class Hash{
	string name;   // key
	long long telephone;  // value
	public:
	Hash(){
		name = "----";
		telephone =0;
	}
	friend class Table;
};

class Table{
	Hash hash_table1[m];
	Hash hash_table2[m];
	int table_size;
	bool empty;
public:
	Table(){
		table_size = m;
		empty = 1;
	}

	long long  returnASCII(string s1){
		long long  num = 0;
		for(int i=0;i<s1.length();i++){   // s1.length() can replaced by i!= '\0'
			num = num + s1[i];
		}
		return num;
	}

	// without replacement
	void insert1(string nm,long long tel){
		empty = 0;
		int key;
		key = returnASCII(nm);
		key = key % table_size;
		if(hash_table1[key].telephone == 0){
			hash_table1[key].name = nm;
			hash_table1[key].telephone = tel;
		}
		else{
			// linear Probing
			while(hash_table1[key].telephone != 0){
				key = (key+1) % table_size;
			}
			hash_table1[key].name = nm;
			hash_table1[key].telephone = tel;
		}
	}


	// with replacement
	void insert2(string nm,long long tel){
		empty = 0;
		int key;
		key = returnASCII(nm);
		key = key % table_size;
		int original_key = key;
		if(hash_table2[key].telephone == 0){
			hash_table2[key].name = nm;
			hash_table2[key].telephone = tel;
		}
		else{
			// linear Probing
			string s1 = hash_table2[original_key].name;
			int actual_key = returnASCII(s1) % 10;
			while(hash_table2[key].telephone != 0){
				key = (key+1) % table_size;
			}
			int new_key = key;
			if(actual_key == original_key){
				hash_table2[new_key].name = nm;
				hash_table2[new_key].telephone = tel;
			}
			else{
			    hash_table2[new_key].name = hash_table2[original_key].name;
			    hash_table2[new_key].telephone = hash_table2[original_key].telephone;
			    hash_table2[original_key].name = nm;
				hash_table2[original_key].telephone = tel;
			}
		}
	}
	
	
	void display(){
		cout<<endl;
		cout<<" ----Hash Table - 1---          ---Hash Table - 2--- "<<endl;
		cout<<" Index  name    Telephone       Index  name    Telephone";
		for(int i=0;i<table_size;i++){
			cout<<"\n  "<<i<<"\t"<<hash_table1[i].name<<"\t"<<hash_table1[i].telephone;
			cout<<"\t\t  "<<i<<"\t"<<hash_table2[i].name<<"\t"<<hash_table2[i].telephone;
		}
		cout<<endl;
	}



	// without replacement
	void search1(string name){
		if(empty == 1){
			cout<<"No record is present"<<endl;
			return;
		}
		int key = returnASCII(name);
		int count = 1;
		key = key % table_size;
		if(hash_table1[key].name == name){
			cout<<"Name - "<<hash_table1[key].name<<endl;
			cout<<"Telephone no - "<<hash_table1[key].telephone<<endl;
			cout<<"Total Comparisons Required - "<<count<<endl;
		}
		else{
			while((hash_table1[key].name != name) && (count < table_size+1)){
				key = (key+1) % table_size;
				count++;
			}
			if(hash_table1[key].name == name){
				cout<<"Name - "<<hash_table1[key].name<<endl;
				cout<<"Telephone no - "<<hash_table1[key].telephone<<endl;
				cout<<"Total Comparisons Required (without replacement) - "<<count<<endl;
			}
			else{
				cout<<"No Entry found "<<endl;
			}
		}
	}

	void search2(string name){
		if(empty == 1){
			cout<<"No record is present"<<endl;
			return;
		}
		int key = returnASCII(name);
		int count = 1;
		key = key % table_size;
		if(hash_table2[key].name == name){
			cout<<"Name - "<<hash_table2[key].name<<endl;
			cout<<"Telephone no - "<<hash_table2[key].telephone<<endl;
			cout<<"Total Comparisons Required - "<<count<<endl;
		}
		else{
			while((hash_table2[key].name != name) && (count < table_size+1)){
				key = (key+1) % table_size;
				count++;
			}
			if(hash_table2[key].name == name){
				cout<<"Name - "<<hash_table2[key].name<<endl;
				cout<<"Telephone no - "<<hash_table2[key].telephone<<endl;
				cout<<"Total Comparisons Required (with replacement) - "<<count<<endl;
			}
			else{
				cout<<"No Entry found "<<endl;
			}
		}
	}
};

int main() {
	Table t1;
	char ch='y';
	while(ch != 'n'){
		cout<<"-----------------------------------------"<<endl;
		cout<<"1. Create Record"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Insert a new record"<<endl;
		cout<<"4. Search for an record"<<endl;
		cout<<"-----------------------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			int n;
			cout<<"Enter total no of records to be inserted"<<endl;
			cin>>n;
			for(int i=0;i<n;i++){
				string nm; // name
				long long tel; // telephone no
				cout<<"Enter name"<<endl;
				cin>>nm;
				cout<<"Enter Telephone"<<endl;
				cin>>tel;
				t1.insert1(nm,tel);
				t1.insert2(nm,tel);
			}
		}
		else if(c==2){
			t1.display();
		}
		else if(c==3){
			string nm; // name
			long long tel; // telephone no
			cout<<"Enter name"<<endl;
			cin>>nm;
			cout<<"Enter Telephone"<<endl;
			cin>>tel;
			t1.insert1(nm,tel);
			t1.insert2(nm,tel);
		}
		else if(c==4){
		    string name;
    		cout<<"Enter name for the record to be searched"<<endl;
    		cin>>name;
			t1.search1(name);
			t1.search2(name);
		}
		else{
			cout<<"You entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}


/* indexes for names
returnASCII("ved")%10 = 9
returnASCII("kit")%10 =  8
returnASCII("ram")%10 =  0
returnASCII("kate")%10 =  1
returnASCII("kate1")%10 = 0
*/
