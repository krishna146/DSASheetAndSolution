//Problem Link - https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T, list<T>> adjList;
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
    void findTopoSequence(int source, unordered_map<int, bool> &visited, stack<int> &st){
        visited[source] = true;
        for(auto adj : adjList[source]){
            if(!visited[adj]){
                findTopoSequence(adj, visited, st);
            }
        }
        st.push(source);
    }
    void dfs(int source, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &newAdjList){
        visited[source] = true;
        for(auto neighbour : newAdjList[source]){
            if(!visited[neighbour]){
                dfs(neighbour, visited, newAdjList);
            }
        }
    }
    void findTranspose(unordered_map<int, list<int> > &newAdjList){
        for(auto v: adjList){
            for(auto neighbour: v.second){
                newAdjList[neighbour].push_back(v.first);
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
    g -> addEdge(3, 4, true);
    //topo Ordering
    int n = 5;
    stack<int> st;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            g -> findTopoSequence(i, visited, st);
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
            g -> dfs(node, visited, newAdjList);
            scc++;
        }
    }
    cout << scc << endl;
}