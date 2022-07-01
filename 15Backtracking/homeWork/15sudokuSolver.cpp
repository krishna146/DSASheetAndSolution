//Problem Link - https://leetcode.com/problems/sudoku-solver/submissions/
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    
}
class Solution {
private:
    bool isSafe(vector<vector<char>> &board, int &row, int &col, char ch){
        
        for(int count = 0 ; count < board.size() ; count++){
            //checking in column
            if(board[count][col] == ch)
                return false;
            //checking in row
            if(board[row][count] == ch)
                return false;
            //checking in triangle
            if(board[(row / 3 * 3) + (count / 3)][(col / 3 * 3) + (count % 3)] == ch)
                return false;
            
        }
      
        return true;
    }
private:
    bool solve(vector<vector<char>> &board){
        for(int row = 0 ; row < board.size(); row++){
            for(int col = 0 ; col < board[row].size() ; col++){
                if(board[row][col] == '.'){
                    bool isValid = false;
                    for(char ch = '1'; ch <= '9' ; ch++){
                        if(isSafe(board , row, col, ch)){
                            board[row][col] = ch;
                            isValid = solve(board);
                            if(isValid == true)
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};