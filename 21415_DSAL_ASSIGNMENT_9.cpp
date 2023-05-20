//============================================================================
// Name        : Assignment_9.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<string.h>
using namespace std;
#define m 10

class node{
	node *left,*right;
	int keyword;
	string meaning;
	int height; // balance factor
	public:
	node(){
		left = right = NULL;
		keyword = 0;
		meaning = "----";
		height = 1;
	}
	node(int x,string y){
		left = right = NULL;
		keyword = x;
		meaning = y;
		height = 1;
	}
	friend class AVL;
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


class AVL{
	node* root;
public:
	AVL(){
		root = NULL;
	}

	int height(node* p){
		if(p == NULL){
			return 0;
		}
		return p->height;
	}

	int balanceFactor(node* p){
		if(p == NULL){
			return 0;
		}
		return height(p->left) - height(p->right);
	}

	void updateHeight(node* p){
		p->height = 1 + max(height(p->left),height(p->right));
	}

	int max(int a,int b){
		if(a > b){
			return a;
		}
		else{
			return b;
		}
	}

	node* rotateLeft(node* p){
		// ll_rotate
		node* newNode = p->right;
		p->right = newNode->left;
		newNode->left = p;
		updateHeight(p);
		updateHeight(newNode);
		return newNode;
	}

	node* rotateRight(node* p){
		// rr_rotate
		node* newNode = p->left;
		p->left = newNode->right;
		newNode->right = p;
		updateHeight(p);
		updateHeight(newNode);
		return newNode;
	}

	node* rotateLeftRight(node* p){
		// rl_rotate
		p->left = rotateLeft(p->left);
		return rotateRight(p);
	}

	node* rotateRightLeft(node* p){
		// rl_rotate
		p->right = rotateRight(p->right);
		return rotateLeft(p);
	}

	node* balance(node* p){
		if(balanceFactor(p) == 2){
			if(balanceFactor(p->left) < 0){
				p = rotateLeftRight(p);
			}
			else{
				p = rotateRight(p);
			}
		}
		else if(balanceFactor(p) == -2){
			if(balanceFactor(p->right) > 0){
				p = rotateRightLeft(p);
			}
			else{
				p = rotateLeft(p);
			}
		}
		updateHeight(p);
		return p;
	}

	node* insert(int x,string y, node* root){
		if(root == NULL){
			node* temp = new node();
			temp->keyword = x;
			temp->meaning = y;
			root = temp;
			return root;
		}
		if(x < root->keyword){
			root->left = insert(x,y,root->left);
		}
		else if (x > root->keyword){
			root->right = insert(x,y,root->right);
		}
		else{
			root->meaning = y; // meaning of an existing keyword is updated
			return root;
		}

		return balance(root);
	}

	void inorder(node* root){
		if(root != NULL){
			inorder(root->left);
			cout<<root->keyword<<" ";
			inorder(root->right);
		}
	}

	void display(){
		cout<<"Ascending order"<<endl;
		inorder(root);
	}

	void add_node(){
		int x;
		string y;
	    cout<<"Enter Keyword - "<<endl;
		cin>>x;
		cout<<"Enter its meaning - "<<endl;
		cin>>y;
		root = insert(x,y,root);
		
	}

	void levelWiseTraversal(){
		Queue q1;
		q1.enqueue(root);
		while(!q1.empty()){
			node* temp = q1.dequeue();
			cout<<temp->keyword<<" ";
			if(temp->left != NULL){
				q1.enqueue(temp->left);
			}
			if(temp->right != NULL){
				q1.enqueue(temp->right);
			}

		}
	}
	
	bool search(node* root,int key)
    {
        if (root == NULL)
        {
            return false;
        }
        if (key < root->keyword)
        {
            return search(root->left, key);
        }
        else if (key > root->keyword)
        {
            return search(root->right, key);
        }
        else
        {
            cout<<"Keyword is present"<<endl;
            cout<<root->keyword<<" : "<<root->meaning<<endl;
            return true;
        }
    }
    
    void searchKey(){
        int n;
        cout<<"Enter keyword"<<endl;
        cin>>n;
        if(search(root,n)){
            //cout<<"Keyword is present"<<endl;
        }
        else{
            cout<<"Keyword is not present"<<endl;
        }
    }
};


int main() {
	AVL a1;
	char ch = 'y';
	while(ch != 'n'){
        cout<<"-----------------------------"<<endl;
        cout<<"1. Insert key-value pair"<<endl;
        cout<<"2. Search key"<<endl;
        cout<<"3. Level order traversal"<<endl;
        cout<<"4. Inorder traversal"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<< "Enter your choice: ";
        int c;
        cin>>c;
        if(c==1){
            a1.add_node();
        }
        else if(c==2){
            a1.searchKey();
        }
        else if(c==3){
            a1.levelWiseTraversal();
        }
        else if(c==4){
            a1.display();
        }
        else{
			cout<<"You have entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n) -"<<endl;
		cin>>ch;
	}
	return 0;
}
