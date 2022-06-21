//Problem Link - https://leetcode.com/problems/n-queens/
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
void printPlaces(int currCol, vector<vector<int>> &visited,int n, vector<int> &ans, vector<vector<int>> &fans){
    if(currCol == visited.size()){
        fans.push_back(ans);
        return;
    }
    for(int row = 0 ; row < n ; row++){
        bool flag = true;
        //checkpoint 1
        for(int col = 0 ; col < currCol ; col++){
            if(visited[row][col]){
                flag = false;
                break;
            }
        }
        //checkpoint 2
        for(int prevRow = row - 1, prevCol = currCol - 1; prevRow >= 0 && prevCol >= 0; prevRow--, prevCol--){
                if(visited[prevRow][prevCol]){
                    flag = false;
                }
        }
        //checkpoint 3
        for(int nextRow = row + 1, prevCol = currCol - 1; nextRow <= n - 1 && prevCol >= 0 ; nextRow++, prevCol--){
                if(visited[nextRow][prevCol]){
                    flag = false;
                }
        }


        if(flag){
            visited[row][currCol] = 1;
            ans.push_back(row + 1);
            printPlaces(currCol + 1, visited,n, ans, fans);
            ans.pop_back();
            visited[row][currCol] = 0;
        }
    }
}
int main(){
    int n = 4;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<int>> fans;
    vector<int> ans;
    printPlaces(0, visited, 4, ans, fans);
    for(auto row : fans){
        for(auto el : row){
            cout << el << " ";
        }
        cout << endl;
    }
}