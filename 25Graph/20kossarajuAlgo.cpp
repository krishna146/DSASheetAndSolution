//Problem Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
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
    void dfs(int source, unordered_map<int, bool> &visited, stack<int> &st){
        visited[source] = true;
        for(auto adj : adjList[source]){
            if(!visited[adj]){
                dfs(adj, visited);
            }
        }
        st.push(source);
    }
    void revDfs(int source, unordered_map<int, bool> &visited){
        visited[source] = true;
        for(auto adj : adjList[source]){
            if(!visited[adj]){
                dfs(adj, visited);
            }
        }

    }
    void findTranspose(unordered_map<int, list<int>> &newAdjList){
        for(auto v: adjList){
            for(auto neighbour: adjList[v.first]){
                newAdjList[neighbour].push()
            }
        }
    }

};
int main(){
    Graph<int> *g = new Graph<int>();
    unordered_map<int , bool> visited;
    //component c1
    g -> addEdge(0, 1, true);
    g -> addEdge(1, 2, true);
    g -> addEdge(2, 0, true);
    g -> addEdge(2, 3, true);
    g -> addEdge(3, 4, false);
    //topo Ordering
    int n = 5;
    stack<int> st;
    unordered_map<int, bool> visited;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            g -> dfs(i, visited, st);
        }
    }
    //transpose
    unordered_map<int, list<int>> newAdjList;
    g -> findTranspose(newAdjList);
    // dfs basis on T.S.
    int scc = 0;
    visited.clear();
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            g -> revDfs(i, visited);
        }
    }
    cout << scc << endl;
    
    

}