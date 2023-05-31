//============================================================================
// Name        : Assignment_7.cpp
// Author      : Vedant Kokane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;

class Graph{
	int **graph;
	char vertex[26];
	int vertices,edges;
public:
	Graph(int v1,int e1){
		vertices = v1;
		edges = e1;
		graph = new int*[vertices];
		for(int i=0;i<vertices;i++){
			graph[i] = new int[vertices];
		}

		for(int i=0;i<vertices;i++){
			for(int j=0;j<vertices;j++){
				graph[i][j] = 0;
			}
		}
		int x =0;
		for (char i = 'a'; i <= 'z'; i++) {
	      	vertex[x] = i;
	      	x++;
	  	}
	}

	void create(){
		cout<<"Vertices are - ";
		for(int i=0;i<vertices;i++){
			cout<<vertex[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<edges;i++){
			cout<<"Enter 2 vertices of edge and weight of the edge"<<endl;
			char a,b;
			int c;
			cin>>a>>b>>c;
			int u = returnInt(a);
			int v = returnInt(b);
			graph[u][v] = c;
			graph[v][u] = c;
		}
	}

	int returnInt(char x){
		for(int i=0;i<vertices;i++){
			if(x == vertex[i]){
				return i;
			}
		}
		return -1;
	}

	void display(){
		for(int i=0;i<vertices;i++){
			cout<<"\t"<<vertex[i]<<"\t";
		}
		cout<<endl;
		for(int i=0;i<vertices;i++){
			cout<<vertex[i]<<"\t";
			for(int j=0;j<vertices;j++){
				cout<<graph[i][j]<<"\t\t";
			}
			cout<<endl;
		}
	}

	int minKey(bool visited[],int key[]){
		int min = 999,minIndex;
		for(int i=0;i<vertices;i++){
			if(visited[i] == 0 && key[i] < min){
				min = key[i];
				minIndex = i;
			}
		}
		return minIndex;
	}

	void Prim(){
		int key[vertices],parent[vertices];
		bool visited[vertices];
		for(int i=0;i<vertices;i++){
			key[i] = 999;
			visited[i] = 0;
			parent[i] = -1;
		}
		key[0] = 0;
		for(int i=0;i<vertices-1;i++){
			int u = minKey(visited,key);
			visited[u] = 1;
			for(int v=0;v<vertices;v++){
				if((graph[u][v] != 0 && visited[v] == 0) && (graph[u][v] < key[v])){
					parent[v] = u;
					key[v] = graph[u][v];
				}
			}
		}
		printMST(parent);
	}

	void printMST(int parent[]){
		int cost = 0;
		cout<<endl;
		cout<<"Edges "<<"\t"<<"Cost"<<endl;
		for(int i=1;i<vertices;i++){
			cout<<vertex[parent[i]]<<" - "<<vertex[i]<<"\t "<<graph[i][parent[i]]<<endl;
			cost+=graph[i][parent[i]];	
		}
		cout<<"Total cost - "<<cost<<endl;
	}

};

int main(){
	int v,e;
	cout<<"Enter total no of vertices and total no of edges"<<endl;
	cin>>v>>e;
	Graph g1(v,e);
	char c = 'y';
	while(c != 'n'){
	    cout<<"-------------------------------------------------"<<endl;
	    cout<<"1. Create Graph"<<endl;
	    cout<<"2. Display Graph"<<endl;
	    cout<<"3. Find MST of Graph using prim's algorithm"<<endl;
	    cout<<"-------------------------------------------------"<<endl;
	    int ch;
	    cout<<"Enter your choice"<<endl;
	    cin>>ch;
	    if(ch == 1){
	        g1.create();
	    }
	    else if(ch == 2){
	        g1.display();
	    }
	    else if(ch == 3){
	        g1.Prim();
	        cout<<endl;
	    }else{
	        cout<<"You have eneterd a wrong choice"<<endl;
	    }
	    cout<<"Do you want to continue (y/n)"<<endl;
	    cin>>c;
	}
	return 0;

}

/* example
Input - 
Vertices - 4 , Edges - 5
a b 10
a c 11
c b 17
c d 11
d b 6

Output - 
Edges 	Cost
a - b	 10
a - c	 11
b - d	 6
Total cost - 27
*/
