// Problem Link -https://leetcode.com/problems/maximum-score-words-formed-by-letters/submissions/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
void solve(vector<string> &words, vector<int> &score, int index, int *charMap, int &ans, int &currScore)
{
    if (index == words.size())
    {
        ans = max(ans, currScore);
        return;
    }

    // excluding current word
    solve(words, score, index + 1, charMap, ans, currScore);

    // including current word
    bool isValidWord = true;
    int visitedUpTo = -1;
    for (auto ch : words[index])
    {
        if (charMap[ch - 'a'] > 0)
        {
            charMap[ch - 'a']--;
            visitedUpTo++;
        }
        else
        {
            isValidWord = false;
            break;
        }
    }
    if (isValidWord)
    {
        int sum = 0;
        for (int j = 0; j < words[index].size(); j++)
        {
            sum += score[words[index][j] - 'a'];
        }
        currScore += sum;
        solve(words, score, index + 1, charMap, ans, currScore);
        currScore -= sum;
        // undoing the changes
        for (int i = 0; i <= visitedUpTo; i++)
        {
            charMap[words[index][i] - 'a']++;
        }
    }
    else
    {
        // undoing the changes
        for (int i = 0; i <= visitedUpTo; i++)
        {
            charMap[words[index][i] - 'a']++;
        }
        solve(words, score, index + 1, charMap, ans, currScore);
    }
}
int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    int ans = 0;
    int currScore = 0;
    int index = 0;
    int charMap[26] = {};
    for (int i = 0; i < letters.size(); i++)
    {
        charMap[letters[i] - 'a']++;
    }
    solve(words, score, index, charMap, ans, currScore);
    return ans;
}
int main()
{
    vector<string> words = {"dog",
                            "cat",
                            "dad",
                            "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o'};

    vector<int> score = {1,
                         0,
                         9,
                         5,
                         0,
                         0,
                         3,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         2,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0};
    maxScoreWords(words, letters, score);
}