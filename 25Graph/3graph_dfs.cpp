//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T, list<T>> adjList;
    void addEdge(T u, T v, bool direction){
        adjList[u].push_back(v);
        if(!direction){
            adjList[v].push_back(u);
        }
    }
    void printADj(){
        for(auto vertices: adjList){
            cout << vertices.first ;
            for(auto adjacent : vertices.second){
                cout << " -> " << adjacent ;
            }
            cout << endl;
        }
    }
    void dfs(int source, unordered_map<int, bool> &visited){
        visited[source] = true;
        cout << source << " ";
        for(auto adj : adjList[source]){
            if(!visited[adj]){
                dfs(adj, visited);
            }
        }
    }

};
int main(){
    Graph<int> *g = new Graph<int>();
    unordered_map<int , bool> visited;
    //component c1
    g -> addEdge(0, 2, false);
    g -> addEdge(2, 3, false);
    g -> addEdge(2, 4, false);
    g -> addEdge(3, 3, false);
    g -> addEdge(1, 3, false);
    g -> addEdge(3, 4, false);

    cout << "printing adjaceny list : " << endl;
    g -> printADj();
    for(int i = 0 ; i < 5 ; i++){
        if(!visited[i]){
            g -> dfs(i, visited);
        }
    }
    
    

}