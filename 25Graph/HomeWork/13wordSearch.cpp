// Problem Link -
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(int row, int col, int idx, string &word, vector<vector<char>> &board, unordered_map<int, unordered_map<int, bool>> &visited)
    {
        if (idx == word.length())
            return true;
        visited[row][col] = true;
        for (int i = 0; i < 4; i++)
        {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            if (r < board.size() && r >= 0 && c < board[0].size() && c >= 0 && word[idx] == board[r][c] && !visited[r][c])
            {
                visited[r][c] = true;
                bool ans = dfs(r, c, idx + 1, word, board, visited);
                if (ans)
                    return ans;
            }
        }
        return false;
    }

public:
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        // Code here

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                unordered_map<int, unordered_map<int, bool>> visited;
                if (board[i][j] == word[0])
                {
                    bool ans = dfs(i, j, 1, word, board, visited);
                    if (ans)
                        return ans;
                }
            }
        }
        return false;
    }
};