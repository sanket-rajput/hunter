




#include<iostream>
using namespace std;

const int V=8;

int MinimumKey(int key[], bool visited[]){ 
    int min = 999, min_index;  
    for (int v = 0; v < V; v++){ 
        if (visited[v] == false && key[v] < min){ 
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

int printMST(int parent[], int cost[V][V]){  
    string dept [8] = {"CS","IT","ENTC","Elec.","Mech.","AIDS","AIML","Civil"};
    int minCost=0;
	cout<<"Department\t----->   Distance\n"; 
    cout<<endl;
    for (int i = 1; i< V; i++) 
    {
		cout<<"A--B : "<<dept[parent[i]]<<" --> "<<dept[i]<<" \t Dist ="<<cost[i][parent[i]]<<" m"<<" \n";  
		minCost+=cost[i][parent[i]];
    }
    cout<<endl;
	cout<<"Distance of Mininimum Spanning Tree is : "<<minCost<<" m";
	return minCost;
}  

void findMST(int cost[V][V]){  
    int parent[V], key[V];
    bool visited[V];
    for (int i = 0; i< V; i++) 
    { 
        key[i] = 999;   
        visited[i] = false;
        parent[i]=-1;
    }    
    key[0] = 0;  
    parent[0] = -1; 
    for (int x = 0; x < V - 1; x++) 
    {  
        int u = MinimumKey(key, visited);  
        visited[u] = true;  
        for (int v = 0; v < V; v++)  
        {
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {  
                parent[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    }
	printMST(parent, cost);  
}  

int main()  
{  
    cout<<"\tPrim's Algorithm";
	cout<<endl;
    int graph[V][V] = { {0,80,50,0,0,0,0,40},
                        {80,0,50,300,80,0,30,0},
	                    {50,50,0,90,70,0,30,30},
	                    {0,290,90,0,190,290,0,0},
	                    {0,80,70,190,0,60,28,71},
	                    {0,0,0,290,60,0,0,80}, 
                        {0,35,76,91,0,0,0,0},
                        {30,50,20,0,0,41,0,0} };
	findMST(graph);  
    return 0;  
}  








