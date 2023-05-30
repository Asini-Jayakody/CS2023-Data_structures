
#include <iostream>
using namespace std;
#include <limits.h>
  

#define V 6
int minTime(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
    return min_index;
}
  

void printSolution(int time_[])
{
    float sum =0;
    cout << "city \t Distance from Source City" << endl;
    for (int i = 0; i < V; i++){
         cout << i << " \t\t\t\t" << time_[i] << endl;
        sum = sum +  time_[i];
    }
       
        
    cout << "average time: " << sum/5 <<"\n";
}
  

void dijkstra(int graph[V][V], int src)
{
    int time_[V]; 
  
    bool sptSet[V]; 
    
    for (int i = 0; i < V; i++)
        time_[i] = INT_MAX, sptSet[i] = false;
 
    time_[src] = 0;
  
    
    for (int count = 0; count < V - 1; count++) {
        int u = minTime(time_, sptSet);
        sptSet[u] = true;
  
        
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v]
                && time_[u] != INT_MAX
                && time_[u] + graph[u][v] < time_[v])
                time_[v] = time_[u] + graph[u][v];
    }
  
    
    printSolution(time_);
}
  

int main()
{
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0,0 } };
  
    
    for(int i=0; i<=5; i++){
        cout<<"from city "<< i<<"\n";
        dijkstra(graph, i);
        cout<<"\n";
    }
    
  
    return 0;
}
  
