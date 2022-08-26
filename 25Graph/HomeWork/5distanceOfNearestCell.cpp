// Problem Link - https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        queue<pair<int, int>> q;
	    vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
	    for(int r = 0 ; r < grid.size() ; r++){
	        for(int c = 0 ; c < grid[0].size() ; c++){
	            if(grid[r][c] == 1){
	                dist[r][c] = 0;
	                q.push({r, c});
	            }
	        }
 	    }
 	    while(!q.empty()){
 	        int row = q.front().first;
 	        int col = q.front().second;
 	        q.pop();
 	        if(row + 1 < grid.size() && dist[row + 1][col] > 1 + dist[row][col]){
 	            q.push({row + 1, col});
 	            dist[row + 1][col] = 1 + dist[row][col];
 	        }
 	        if(row - 1 >= 0 && dist[row - 1][col] > 1 + dist[row][col]){
 	            q.push({row - 1, col});
 	            dist[row - 1][col] = 1 + dist[row][col];
 	        }
 	        if(col + 1 < grid[0].size() && dist[row][col + 1] > 1 + dist[row][col]){
 	            q.push({row, col + 1});
 	            dist[row][col + 1] = 1 + dist[row][col];
 	        }
 	        if(col - 1 >= 0 && dist[row][col - 1] > 1 + dist[row][col]){
 	            q.push({row, col - 1});
 	            dist[row][col - 1] = 1 + dist[row][col];
 	        }
 	    }
 	    return dist;
	    
	}
};