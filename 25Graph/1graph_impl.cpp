//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename T>
class Graph{
    public:
    map<T, list<pair<T, T>>> adjList;

    void addEdge(T u, T v,int weight, bool direction){
        adjList[u].push_back({v, weight});
        if(!direction){
            adjList[v].push_back({u, weight});
        }
    }
    void printADj(){
        for(auto vertices: adjList){
            cout << vertices.first ;
            for(auto adjacent : vertices.second){
                cout << " -> " <<  "{" << adjacent.first << ", " << adjacent.second << "}";
            }
            cout << endl;
        }
    }
    void bfs(){
        
    }
};
int main(){
    Graph<int> *g = new Graph<int>();
    g -> addEdge(0, 1, 3, false);
    g -> addEdge(1, 2, 4, false);
    g -> addEdge(1, 3, 9, false);
    g -> addEdge(2, 3, 1, false);
    g -> addEdge(2, 4, 11, false);
    g -> addEdge(3, 4, 10, false);
    cout << "printing adjaceny list : " << endl;
    g -> printADj();
    

}