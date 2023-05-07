//============================================================================
// Name        : Assignment_6.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#define m 10
using namespace std;

class node{
	string data;
	bool visited1;
	bool visited2;
	node* next;
	node* down;
	int inDegree, outDegree;
public :
	node(){
		data = "";
		visited1 = 0;
		visited2 = 0;
		inDegree = 0;
		outDegree = 0;
		next = down = NULL;
	}
	node(string x){
		data = x;
		visited1 = 0;
		visited2 = 0;
		next = down = NULL;
	}
	friend class Graph;
};

class Stack{
	node* a[m];
	int top;
public:
	Stack(){
		top = -1;
	}

	void push(node *temp){
		if(top == m-1){
			//cout<<"Overflow"<<endl;
			return;
		}
		else{
			top++;
			a[top] = temp;
		}
	}

	node* pop(){
		if(top == -1){
			//cout<<"Underflow"<<endl;
			return NULL;
		}
		node *temp = a[top];
		top--;
		return temp;
	}
	node* top1(){
		return a[top];
	}
	bool is_empty(){
		if(top == -1){
			return 1;
		}
		return 0;
	}
};

class Queue{
	node* a[m];
	int front,rear;
public:
	Queue(){
		front = rear = -1;
	}
	void enqueue(node *temp){
		if(front == -1){
			front = 0;
		}
		else if (rear == m-1){
			// cout<<"Overflow"<<endl;
			return;
		}
		rear++;
		a[rear] = temp;
	}


	node* dequeue(){
		if(front == -1){
			// cout<<"Underflow"<<endl;
			return NULL;
		}
		else if(front == rear){
			node *temp = a[front];
			front = -1;
			rear = -1;
			return temp;
		}
		else{
			node *temp = a[front];
			front++;
			return temp;
		}
	}


	bool empty(){
		if(front == -1 || front == rear+1){
			return 1;
		}
		return 0;
	}
};


class Graph{
	node* head;
	int nodes;
	string *bfs;
	string *dfs;

public :
	Graph(int v){
		head = NULL;
		nodes = 0;
		nodes = v;
		bfs = new string[nodes];
		dfs = new string[nodes];
	}

	void createGraph(){
		int adjacentNodes;
		for(int i=0;i<nodes;i++){
			node* newNode = new node();
			node *move,*temp;
			cout<<"Enter the data of vertex"<<endl;
			cin>>newNode->data;
			if(head == NULL){
				head = newNode;
				move = temp = head;
			}
			else{
				move->down = newNode;
				move = move->down;
				temp = move;
			}
			cout<<"Enter total adjacent nodes for the vertex"<<endl;
			cin>>adjacentNodes;
			temp->outDegree = adjacentNodes;
			for(int j=0;j<adjacentNodes;j++){
				node* newNode = new node();
				cout<<"Enter data of adjacent vertex"<<endl;
				cin>>newNode->data;
				temp->next = newNode;
				temp = temp->next;
			}
		}
	}

	void display(){
		if(head != NULL){
			cout<<"Graph Contents"<<endl;
			node *move,*temp;
			move = head;
			while(move != NULL){
				cout<<move->data<<" : ";
				temp = move->next;
				while(temp != NULL){
					cout<<" --> "<<temp->data;
					temp = temp->next;
				}
				cout<<endl;
				move = move->down;
			}
		}
		else{
			cout<<"Graph is empty"<<endl;
		}
	}

	void operationDFS(){
		node* move = head;
		Stack s1;
		move->visited1 = 1;
		s1.push(move);
		int i = 0;
		while(!s1.is_empty()){
			node* n1 = s1.pop();
			dfs[i] = n1->data;
			i++;
			//cout<<n1->data<<" ";
			n1 = n1->next;
			while(n1 != NULL){
				string name = n1->data;
				node* n2 = move;
				while(n2 != NULL){
					if(n2->data == name){
						if(n2->visited1 == 0){
							n2->visited1 = 1;
							s1.push(n2);
						}
					}
					n2 = n2->down;
				}
				n1 = n1->next;
			}
		}
	}

	void operationBFS(){
		node* move = head;
		Queue q1;
		move->visited2 = 1;
		q1.enqueue(move);
		int i = 0;
		while(!q1.empty()){
			node* n1 = q1.dequeue();
			bfs[i] = n1->data;
			i++;
			// cout<<n1->data<<" ";
			n1 = n1->next;
			while(n1 != NULL){
				string s1 = n1->data;
				node* n2 = move;
				while(n2 != NULL){
					if(n2->data == s1){
						if(n2->visited2 == 0){
							n2->visited2 = 1;
							q1.enqueue(n2);
						}
					}
					n2 = n2->down;
				}
				n1 = n1->next;
			}
		}
	}

	void displayDFS(){
		operationDFS();
		for(int i=0;i<nodes;i++){
			cout<<dfs[i]<<" ";
		}
		cout<<endl;
	}

	void displayBFS(){
		operationBFS();
		for(int i=0;i<nodes;i++){
			cout<<bfs[i]<<" ";
		}
		cout<<endl;
	}
};

int main() {
	int v;
	cout<<"Enter total nodes"<<endl;
	cin>>v;
	Graph g1(v);
	bool graphCreated = 0;
	char ch = 'y';
	while(ch != 'n'){
		cout<<"--------------------------------------------------"<<endl;
		cout<<"1. Create a graph"<<endl;
		cout<<"2. Display DFS traversal of the graph"<<endl;
		cout<<"3. Display BFS traversal of the graph"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		int c;
		cout<<"Enter choice"<<endl;
		cin>>c;
		if(c==1){
			if(!graphCreated){
				g1.createGraph();
			}else{
				cout<<"Graph is already created"<<endl;
			}
		}
		else if(c==2){
			g1.displayDFS();
		}
		else if(c==3){
			g1.displayBFS();
		}
		else{
			cout<<"You entered a wrong choice"<<endl;
		}

		cout<<"Do you want to continuec (y/n) - "<<endl;
		cin>>ch;

	}
	return 0;
}
