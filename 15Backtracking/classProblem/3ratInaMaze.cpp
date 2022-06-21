//problem Link -> https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void storePath(vector<vector<int>> &maze, int row, int col, string path, int n, vector<vector<int>> &visited, vector<string> &ans){
        if(row == n - 1  && col == n - 1 ){
            ans.push_back(path);
            return;
        }
        if(col + 1 <= n-1){
            if(maze[row][col + 1] == 1 && !visited[row][col + 1]){
                visited[row][col+1] = 1;
                storePath(maze, row , col + 1, path + 'R', n, visited, ans);
                visited[row][col + 1] = 0;
            }
        }
        if(col - 1 >= 0){
            if(maze[row][col - 1] == 1 && !visited[row][col - 1]){
                visited[row][col - 1] = 1;
                storePath(maze, row , col - 1, path + 'L', n, visited, ans);
                visited[row][col - 1] = 0;
            }
        }
        if(row + 1 <= n-1){
            if(maze[row + 1][col] == 1 && !visited[row + 1][col]){
                visited[row + 1][col] = 1;
                storePath(maze, row + 1, col, path + 'D', n, visited, ans);
                visited[row + 1][col] = 0;
            }
        }
        if(row - 1 >= 0){
            if(maze[row - 1][col] == 1 && !visited[row - 1][col]){
                visited[row - 1][col] = 1;
                storePath(maze, row - 1, col, path + 'U', n, visited, ans);
                visited[row - 1][col] = 0;
            }
    }
}
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<string> ans;
        visited[0][0] = 1;
        storePath(m, 0, 0, "", n, visited, ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
      
    vector<vector<int>> m = {
                            {1, 0, 0, 0},
                            {1, 1, 0, 1}, 
                            {1, 1, 0, 0},
                            {0, 1, 1, 1}
                            };        
       
        
    Solution obj;
    vector<string> result = obj.findPath(m, 4);
    sort(result.begin(), result.end());
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
            cout << endl;
    
    return 0;
}  // } Driver Code Ends