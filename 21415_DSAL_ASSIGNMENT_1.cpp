//============================================================================
// Name        : Assignment_1.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class node{
	node *left,*right;
	int data;
	public:
	node(){
		left = right = NULL;
		data = 0;
	}
	friend class BST;
};

class BST{
	node *root;
	public:
	BST(){
		root = NULL;
	}

	void add_node(int x){
		node *temp = new node();
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		node *current = root;
		if(root == NULL){
			root = temp;
		}
		else{
			while(true){
				if(current->data <= x){
					if(current->right != NULL ){
						current = current->right;
					}
					else{
						current->right = temp;
						break;
					}
				}
				else{
					if(current->left != NULL){
						current = current->left;
					}
					else{
						current->left = temp;
						break;
					}

				}
			}
		}
	}

	void preorder(node* root){
		if(root != NULL){
			cout<<root->data<<" ";
			preorder(root->left);
			preorder(root->right);
		}
	}

	void postorder(node* root){
		if(root != NULL){
			postorder(root->left);
			postorder(root->right);
			cout<<root->data<<" ";
		}
	}

	void inorder(node* root){
		if(root != NULL){
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
		}
	}

	void display(){
		cout<<"Pre order = ";
		preorder(root);
		cout<<endl;
		cout<<"Post order = ";
		postorder(root);
		cout<<endl;
		cout<<"In order = ";
		inorder(root);
		cout<<endl;

	}

	int search(int x){
		node *temp = root;
		while(temp != NULL){
			if(temp->data == x){
				cout<<"Node with value "<<x<<" is Present"<<endl;
				return 1;
			}
			else if(temp->data > x ){
				temp = temp->left;
			}
			else if(temp->data < x){
				temp = temp->right;
			}
		}
		if(temp == NULL){
			cout<<"Node is not present"<<endl;
			return 0;
		}
	}

	void swap(node *root){
		node *p;
		p = root;
		if(p){
			if(p->left || p->right){
				node *temp;
				temp = p->left;
				p->left = p->right;
				p->right = temp;
			}
			swap(p->left);
			swap(p->right);
		}
	}

	void max_min_value(){
		node *p1,*p2;
		p1 = root;
		p2 = root;
		// minimum
		while(p1->left != NULL){
			p1 = p1->left;
		}
		// maximum
		while(p2->right != NULL){
			p2 = p2->right;
		}
		cout<<"Minimum is "<<p1->data<<endl;
		cout<<"Maximum is "<<p2->data<<endl;
	}

	int height(node* node)
	{
	    if (node == NULL)
	        return 0;
	    else {
	        /* compute the height of each subtree */
	        int lheight = height(node->left);
	        int rheight = height(node->right);
	        /* use the larger one */
	        if (lheight > rheight){
	            return (lheight + 1);
	        }
	        else{
	            return (rheight + 1);
	        }
	    	}
	}
	void longest(){
		int x = height(root);
		cout<<"Longest path is "<<x<<endl;
	}

	void swapped_sub_tree(){
		swap(root);
		display();
	}
};


int main(){
	BST b1;
	char ch = 'y';
	while(ch != 'n'){
		cout<<"-----------------------------------------"<<endl;
		cout<<"1. Add new node"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Search node"<<endl;
		cout<<"4. Maximum and Minimum values of node"<<endl;
		cout<<"5. No of nodes in longest path"<<endl;
		cout<<"6. Swap sub-trees and display "<<endl;
		cout<<"-----------------------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			int x;
			cout<<"Enter value of node"<<endl;
			cin>>x;
			b1.add_node(x);
		}
		else if(c==2){
			b1.display();
		}
		else if(c==3){
			int x;
			cout<<"Enter node to be searched"<<endl;
			cin>>x;
			b1.search(x);
		}
		else if(c==4){
			b1.max_min_value();
		}
		else if(c==5){
			b1.longest();
		}
		else if(c==6){
			b1.swapped_sub_tree();
		}
		else{
			cout<<"You have entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}

/*
b1.add_node(10);
b1.add_node(5);
b1.add_node(20);
b1.add_node(2);
b1.add_node(8);
b1.add_node(25);

10,5,20,2,8,25
Pre order = 10 5 2 8 20 25
Post order = 2 8 5 25 20 10
In order = 2 5 8 10 20 25
*/