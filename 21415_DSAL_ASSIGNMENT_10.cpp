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
  int arr[100] = {0};
  int index;
  public:
    Heap(){
        index = 1;
    }
    
    void createRecord(){
        int n;
        cout<<"Enter total records"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Enter marks - "<<endl;
            cin>>arr[index];
            index++;
        }
    }
    
    void printRecords(){
        for(int i=1;i<index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void insert(int n){
        int i = n;
        int temp = arr[n];
        while(i>1 && arr[i/2] < temp){
            arr[i] = arr[i/2];
            i = i/2;
        }
        arr[i] = temp;
    }
    
    void delete1(int n){
        int i = 1;
        int j = 2*i;
        swap(arr[1],arr[n]);
        while(j <= n-1){
            if(j < n-1 && (arr[j+1] > arr[j])){
                j = j+1; 
            }
            
            if(arr[j] > arr[i]){
                swap(arr[j],arr[i]);
                i = j;
                j = 2*j;
            }
            else{
                break;
            }
            
        }
    }
    
    void heapify(){
        for(int i = 2;i<=index;i++){
            insert(i);
        }
    }
    
    void heapSort(){
        heapify();
        for(int i=index-1;i>1;i--){
            delete1(i);
        }
    }
    
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b =temp;
    }
    
    void lowest(){
		heapSort();
		cout<<"Lowest Marks - "<<arr[1]<<endl;
	}
};

// use examples of 7 nodes because a tree with 7 nodes is a complete binary tree
int main()
{
    Heap h1;
    char ch = 'y';
	bool heapApplied = 0;
	while(ch != 'n'){
		cout<<"-----------------------------"<<endl;
		cout<<"1. Add Marks of students"<<endl;
		cout<<"2. Display all Marks"<<endl;
		cout<<"3. Heapify the record"<<endl;
		cout<<"4. Apply Heap Sort"<<endl;
		cout<<"5. Display the lowest marks"<<endl;
		cout<<"-----------------------------"<<endl;
		int c;
		cout<<"Enter choice - "<<endl;
		cin>>c;
		if(c==1){
			h1.createRecord();
		}
		else if(c==2){
			if(heapApplied){
				cout<<"Heap sort has been applied."<<endl;
				h1.printRecords();
			}
			else{
				h1.printRecords();
			}
		}
		else if(c==3){
			h1.heapify();
			cout<<"The record is heapified"<<endl;
		}
		else if(c==4){
		    h1.heapSort();
			cout<<"Heap sort is applied."<<endl;
		}
		else if(c==5){
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
