//============================================================================
// Name        : Assignment_3.cpp
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
	bool rightThread;
	bool leftThread;
	public:
	node(){
		left = right = NULL;
		data = 0;
		rightThread = false;
		leftThread = false;
	}
	node(int x){
		left = right = NULL;
		data = x;
		rightThread = false;
		leftThread = false;
	}
	friend class BST;
};


class BST{
	node *root,*header;
	public:
	BST(){
		root = NULL;
		header = NULL;
	}
	
	// for Inserting a node
	void insert(int key){
	    if(root == NULL){
	        header = new node(-99);
	        header->right = header;
	        root = new node(key);
	        root->left = header;
	        root->right = header;
	        header->left = root;
	    }
	    else{
	        node *ptr = root;
	        node *temp = new node(key);
	        while(true){
	            if(ptr->data > key){
    	            if(ptr->leftThread){
    	                ptr = ptr->left;
    	            }
    	            else{
    	                temp->left = ptr->left;
    	                temp->right = ptr;
    	                ptr->leftThread = 1;
    	                ptr->left = temp;
    	                return;
    	            }
	             }
    	        else{
    	            if(ptr->rightThread){
    	                ptr = ptr->right;
    	            }
    	            else{
    	                temp->left = ptr;
    	                temp->right = ptr->right;
    	                ptr->right = temp;
    	                ptr->rightThread = 1;
    	                return;
    	            }
    	        }
	        }
	    }
	}
	
	
	void inorder(){
	    node* t = root;
	    while(t->leftThread != 0){
	        t = t->left;
	    }
	    
	    while(t != header){
	        cout<<t->data<<" ";
	        if(t->rightThread != 0){
	            t = t->right;
	            while(t->leftThread != 0){
	                t = t->left;
	            }
	        }
	        else{
	            t = t->right;
	        }
	    }
	}
	
    void preorder(){
        bool flag =0;
        node* t = root;
        while(t != header){
            if(flag == 0){
                cout<<t->data<<" ";
            }
            if(flag == 0 && t->leftThread == 1){
                t = t->left;
            }
            else{
                if(t->rightThread == 1){
                    flag = 0;
                }
                else{
                    flag = 1;
                }
                t = t->right;
            }
        }
    }

    void search(int key,node* &curr,node* &par)
	{
		if(root != NULL)
		{
			int flag = 0;
			if(curr->data == key){
			    return;
			}
			while(curr != header)
			{
				if(curr->data == key)
					return;
				if(flag == 0 && curr->leftThread == 1)
				{
					par = curr;
					curr = curr->left;
				}
				else
				{
					if(curr->rightThread == 1)
						flag = 0;
					else
						flag = 1;
					par = curr;
					curr = curr->right;
				}
			}
		}
	}
    
    void deleteNode(int key)
	{
		node* curr = root;
		node* par = NULL;
		search(key,curr,par);
		if(curr->leftThread == 1 && curr->rightThread == 1)
		{
			node* cs = curr->right;
			par = curr;
			while(cs->leftThread == 1)
			{
				par = cs;
				cs = cs->left;
			}
			curr->data = cs->data;
			curr = cs;
		}
		if(curr->leftThread == 0 && curr->rightThread == 0)
		{
			if(par->left == curr)
			{
				par->left = curr->left;
				par->leftThread = 0;
			}
			else
			{
				par->right = curr->right;
				par->rightThread = 0;
			}
			free(curr);
		}
		if(curr->leftThread == 1 && curr->rightThread == 0)
		{
			node* temp = curr->left;
			if(par->left == curr)
				par->left = temp;
			else
				par->right = temp;
			while(temp->rightThread == 1)
				temp = temp->right;
			temp->right = curr->right;
			free(curr);
		}
		if(curr->leftThread == 0 && curr->rightThread == 1)
		{
			node* temp = curr->right;
			if(par->left == curr)
				par->left = temp;
			else
				par->right = temp;
			while(temp->leftThread == 1)
				temp = temp->left;
			temp->left = curr->left;
			free(curr);
		}
	}
};


int main()
{
    BST b1;
    char ch = 'y';
	while(ch != 'n'){
		cout<<"-----------------------------------------"<<endl;
		cout<<"1. Add new node"<<endl;
		cout<<"2. Inorder Traversal"<<endl;
		cout<<"3. Preorder Traversal"<<endl;
		cout<<"4. Delete a node"<<endl;
		cout<<"-----------------------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			int x;
			cout<<"Enter value of node"<<endl;
			cin>>x;
			b1.insert(x);
		}
		else if(c==2){
			b1.inorder();
		}
		else if(c==3){
			b1.preorder();
		}
		else if(c==4){
		     	int x;
			cout<<"Enter value of node that to be deleted"<<endl;
			cin>>x;
			b1.deleteNode(x);
		}
		else{
			cout<<"You have entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n)"<<endl;
		cin>>ch;
	}
	return 0;
}



/* example 
b1.insert(10);
b1.insert(5);
b1.insert(20);
b1.insert(2);
b1.insert(8);
b1.insert(25);
b1.inorder();
cout<<endl;
b1.preorder();
b1.deleteNode(8);
cout<<endl;
b1.preorder();
*/
