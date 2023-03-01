#include <iostream>
using namespace std;
#define m 100

class node{
	node *left,*right;
	int data;
	public:
	node(){
		left = right = NULL;
		data = 0;
	}
	friend class BT;
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

class BT{
	node *root;
	public:
	BT(){
		root = NULL;
	}

	void create(){
		Queue q1;
		node *p,*t;
		int x;
		cout<<"Enter value of root"<<endl;
		cin>>x;
		node *temp = new node();
		temp->data = x;
		root = temp;
		q1.enqueue(root);
		while(!q1.empty()){
			p = q1.dequeue();
			cout<<"Enter left child of parent node "<<p->data<<endl;
			cin>>x;
			if(x != -1){
				t = new node();
				t->data = x;
				t->left = NULL;
				t->right = NULL;
				p->left = t;
				q1.enqueue(t);
			}
			cout<<"Enter right child of parent node "<<p->data<<endl;
			cin>>x;
			if(x != -1){
				t = new node();
				t->data = x;
				t->left = NULL;
				t->right = NULL;
				p->right = t;
				q1.enqueue(t);
			}
			cout<<"Add another node (y/n)"<<endl;
			char c;
			cin>>c;
			if(c == 'n'){
				break;
			}
		}
	}

	void preorder(node* root){
		if(root==NULL){
			cout<<"Tree is Empty"<<endl;
			return;
		}
		Stack s1;
		node* current = root;
		while(current != NULL || !s1.is_empty()){
			if(current != NULL){
				// cout<<root->data<<" "; pre
				s1.push(current);
				cout<<current->data<<" ";
				current = current->left;
			}
			else{
				current = s1.pop();
				current = current->right;
			}
		}
	}

	void postorder(node* root){
		Stack s1,s2;
		s1.push(root);
		node* temp;
		while(!s1.is_empty()){
			temp = s1.top1();
			s1.pop();
			s2.push(temp);
			if(temp->left != NULL){
				s1.push(temp->left);
			}
			if(temp->right != NULL){
				s1.push(temp->right);
			}
		}
		while(!s2.is_empty()){
			temp = s2.top1();
			s2.pop();
			cout<<temp->data<<" ";
		}
		
	}
	void inorder(node* root){
		Stack s1;
		node* current = root;
		while(current != NULL || !s1.is_empty()){
			if(current != NULL){
				s1.push(current);
				current = current->left;
			}
			else{
				current = s1.pop();
				cout<<current->data<<" ";
				current = current->right;
			}
		}
		
	}

	void display(){
		if(root==NULL){
			cout<<"Tree is Empty"<<endl;
			return;
		}
		cout<<"Pre order = ";
		preorder(root);
		cout<<endl;x
		cout<<"Post order = ";
		postorder(root);
		cout<<endl;
		cout<<"In order = ";
		inorder(root);
		cout<<endl;

	}
	void display1(node *root1){
			if(root1==NULL){
				cout<<"Tree is Empty"<<endl;
				return;
			}
			cout<<"Pre order = ";
			preorder(root1);
			cout<<endl;
			cout<<"Post order = ";
			postorder(root);
			cout<<endl;
			cout<<"In order = ";
			inorder(root1);
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

	int longest(node* node)
	{
	    if (node == NULL)
	        return 0;
	    else {
	        /* compute the height of each subtree */
	        int lheight = longest(node->left);
	        int rheight = longest(node->right);
	        /* use the larger one */
	        if (lheight > rheight)
	            return (lheight + 1);
	        else
	            return (rheight + 1);
	    }
	}

	void height(){
		int x = longest(root);
		cout<<"Longest path is "<<x<<endl;
	}

	void swapped_sub_tree(){
		swap(root);
		display();
	}

	void count_internal_lead(node *p,int &internal,int &leaf){
		if(p){
			if(p->left || p->right){
				internal++;
			}
			else{
				leaf++;
			}
			count_internal_lead(p->left,internal,leaf);
			count_internal_lead(p->right,internal,leaf);
		}
	}

	void count(){
		int internal=0,leaf=0;
		count_internal_lead(root,internal,leaf);
		cout<<"Internal nodes - "<<internal<<endl;
		cout<<"Leaf nodes - "<<leaf<<endl;
	}

	void erase_node(node *parent,node *current){
		if(current){
			erase_node(parent,current->left);
			erase_node(parent,current->right);
			if(parent->left == current){
				node *temp;
				temp = parent->left;
				parent->left = NULL;
				free(temp);
			}
			else{
				node *temp;
				temp = parent->right;
				parent->right = NULL;
				free(temp);
			}
		}
	}
	void erase(){
		erase_node(root,root);
		free(root);
	}
	node* copy_tree(node* root){
		if(root==NULL){
			return NULL;
		}
		node* new_root = new node();
		new_root->data = root->data;
		new_root->left = copy_tree(root->left);
		new_root->right = copy_tree(root->right);

		return new_root;
	}

	void copy(){
		node *temp = copy_tree(root);
		display1(temp);
	}
};


int main() {
	BT b1;
		char ch = 'y';
		while(ch != 'n'){
			cout<<"-----------------------------------------"<<endl;
			cout<<"1. Create Binary Tree"<<endl;
			cout<<"2. Display"<<endl;
			cout<<"3. Height of the tree"<<endl;
			cout<<"4. Swap sub-trees and display "<<endl;
			cout<<"5. Count number of internal nodes and leaf nodes "<<endl;
			cout<<"6. Copy existing tree to another tree"<<endl;
			cout<<"7. Erase all the nodes "<<endl;
			cout<<"-----------------------------------------"<<endl;
			int c;
			cout<<"Enter choice - "<<endl;
			cin>>c;
			if(c==1){
				int x;
				b1.create();
			}
			else if(c==2){
				b1.display();
			}
			else if(c==3){
				b1.height();
			}
			else if(c==4){
				b1.swapped_sub_tree();
			}
			else if(c==5){
				b1.count();
			}
			else if(c==6){
				b1.copy();
			}
			else if(c==7){
				b1.erase();
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
10,5,20,2,8,25
Pre order = 10 5 2 8 20 25
Post order = 2 8 5 25 20 10
In order = 2 5 8 10 20 25
*/
