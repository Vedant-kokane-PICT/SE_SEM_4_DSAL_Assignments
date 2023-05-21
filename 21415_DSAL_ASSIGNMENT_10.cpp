//============================================================================
// Name        : Assignment_10.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

class Heap{
	int *array;
	int total;
public:
	Heap(int n){
		total = n;
		array = new int[total];
		for(int i=0;i<total;i++){
			array[i] = 0;
		}
	}

	void create(){
		for(int i=0;i<total;i++){
			cout<<"Enter the marks - "<<endl;
			cin>>array[i];
		}
	}

	void swap(int &a,int &b){
		int temp = a;
		a = b;
		b = temp;
	}

	void heapify(int i,int n){
		// Finding largest among root, left child, and right child
	    int largest = i;
	    int left = 2 * i + 1;
	    int right = 2 * i + 2;
	  
	    if (left < n && array[left] > array[largest])
	      largest = left;
	  
	    if (right < n && array[right] > array[largest])
	      largest = right;
	  
	    // Swap and continue heapifying if root is not largest
	    if (largest != i) {
	      swap(array[i], array[largest]);
	      heapify(largest,n);
	    }
	}

	void heapSort(){
		// Build max heap
	    for (int i = total / 2 - 1; i >= 0; i--){
	      heapify(i,total);
	    }
	  
	    // Heap sort
	    for (int i = total - 1; i >= 0; i--) {
	      swap(array[0], array[i]);
	  
	     // Heapify root element to get highest element at root again
	     heapify(0,i);
	    }
	}

	void display(){
		for(int i=0;i<total;i++){
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}

	void highest(){
		heapSort();
		cout<<"Hightest Marks - "<<array[total-1]<<endl;
	}

	void lowest(){
		heapSort();
		cout<<"Lowest Marks - "<<array[0]<<endl;
	}
};
// use 7 nodes in tree because it is a completed tree

int main() {
	cout<<"Enter total no of entries - "<<endl;
	int n;
	cin>>n;
	Heap h1(n);
	char ch = 'y';
	bool heapApplied = 0;
	while(ch != 'n'){
		cout<<"-----------------------------"<<endl;
		cout<<"1. Add Marks of students"<<endl;
		cout<<"2. Display all Marks"<<endl;
		cout<<"3. Apply Heap Sort"<<endl;
		cout<<"4. Display the lowest marks"<<endl;
		cout<<"-----------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			h1.create();
		}
		else if(c==2){
			if(heapApplied){
				cout<<"Heap sort has been applied."<<endl;
				h1.display();
			}
			else{
				h1.display();
			}
		}
		else if(c==3){
			h1.heapSort();
			cout<<"Heap sort is  applied."<<endl;
		}
		else if(c==4){
			h1.lowest();
		}
		else{
			cout<<"You have entered a wrong choice"<<endl;
		}
		cout<<"Do you want to continue (y/n) -"<<endl;
		cin>>ch;
	}
	return 0;
}
