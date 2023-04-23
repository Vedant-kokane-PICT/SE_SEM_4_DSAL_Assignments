//============================================================================
// Name        : Assignment_5.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#define m 10


class node{
	string value,key;
	node* next;

public:
	node(){
		value = "";
		key = "";
		next = NULL;
	}
	node(string key,string value){
		this->value = value;
		this->key = key;
		next  = NULL;
	}
	friend class Table;
};

class Table{
	node* hash_table[m] = {NULL};
public :
	Table(){

	}
	void create(){
		for(int i=0;i<m;i++){
			node* temp = new node("----","----");
			hash_table[i] = temp;
			hash_table[i]->next = NULL;
		}
	}
	long long  returnASCII(string s1){
		long long  num = 0;
		for(int i=0;i<s1.length();i++){   // s1.length() can replaced by i!= '\0'
			num = num + s1[i];
		}
		return num;
	}

	void insert(string key,string value){
		long long index  = returnASCII(key);
		index = index % m;
		node* temp = new node(key,value);
		if(hash_table[index]->next == NULL){
			hash_table[index]->next = temp;
		}
		else{
			node* current = hash_table[index]->next;
			while(current->next !=NULL){
				current = current->next;
			}
			current->next = temp;
		}
	}


	node* search(string key){
		long long index  = returnASCII(key);
		index = index % m;
		node* temp = hash_table[index];
		temp = temp->next;
		while(temp != NULL){
			if(key == temp->key){
				cout<<"Meaning is - "<<temp->value<<endl;
				return temp;
			}
			temp = temp->next;
		}
		if(temp == NULL){
			cout<<"Key does not exist"<<endl;
		}
		return NULL;
	}
	
	void search2(string key, node* &prev,node* &curr){
		long long index  = returnASCII(key);
		index = index % m;
		prev = hash_table[index];
		curr = prev->next;
		while(curr != NULL){
			if(key == curr->key){
				return;
			}
			curr = curr->next;
			prev = prev->next;
			
		}
		if(curr == NULL){
			cout<<"Key does not exist"<<endl;
		}
	}
	
	void display(){
		cout<<" Index   key   value";
		for(int i=0;i<m;i++){
			cout<<"\n  "<<i<<"\t"<<hash_table[i]->key<<"\t"<<hash_table[i]->value;
		}
		cout<<endl;
	}
	void display2(){
		cout<<" Index   key   value";
		for(int i=0;i<m;i++){
			cout<<"\n  "<<i<<"\t"<<hash_table[i]->key<<"\t"<<hash_table[i]->value<<"\t-> ";
			node* temp = hash_table[i]->next;
			while(temp != NULL){
			    cout<<temp->key<<":"<<temp->value<<" -> ";
			    temp = temp->next;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	
	void deleteKey(string key){
	    node* prev = NULL;
	    node* curr = NULL;
	    search2(key,prev,curr);
	    if(curr != NULL){
	        if(curr->next == NULL){
	            prev->next = NULL;
	            free(curr);
	        }
	        else{
	            prev->next = curr->next;
	            free(curr);
	        }
	    }
	}
	
};


int main() {
	Table t1;
	t1.create();
	bool set = 0;
	char ch='y';
	while(ch != 'n'){
		cout<<"-----------------------------------------"<<endl;
		cout<<"1. Insert a new record"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Delete a record"<<endl;
		cout<<"4. Search a record"<<endl;
		cout<<"-----------------------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
		    set = 1;
			string key; //  word
			string value; // its meaning
			cout<<"Enter name of word"<<endl;
			cin>>key;
			cout<<"Enter the  meaning of word"<<endl;
			cin>>value;
			t1.insert(key,value);
		}
		else if(c==2){
		    if(set == 0){
		        t1.display();
		    }
		    else{
		        t1.display2();
		    }
		}
		else if(c==3){
			string key; // word
			cout<<"Enter  word"<<endl;
			cin>>key;
			t1.deleteKey(key);
		}
		else if(c==4){
		    string name;
    		cout<<"Enter word whose to be searched"<<endl;
    		cin>>name;
			t1.search(name);
		}
		else{
			cout<<"You entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}



/* example
Table t1;
	t1.create();
	t1.display();
	t1.insert("ram","meaning1");
	t1.insert("kate1","meaning2");
	t1.insert("joy","happy");
	t1.display2();
	t1.search("ram");
	t1.search("joy");
	t1.deleteKey("ram");
	t1.search("ram");
	t1.display2();
*/
