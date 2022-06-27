// Problem Link -https://leetcode.com/problems/maximum-score-words-formed-by-letters/submissions/
/* By Krishna Kumar */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
void maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
{
    vector<int> arrScore;
    for (int index = 0; index < words.size(); index++)
    {
        string currWord = words[index];
        bool isValidWord = true;
        unordered_map<int, bool> ump;
        for (int j = 0; j < currWord.length(); j++)
        {
            char ch = currWord[j];
            bool flag = false;
            for (int k = 0; k < letters.size(); k++)
            {
                int currCh = letters[k];
                if (ch == currCh && !ump[k])
                {
                    flag = true;
                    ump[k] = true;
                    break;
                }
            }
            if (flag == false)
            {
                isValidWord = false;
                break;
            }
            j++;
        }
        if (isValidWord)
        {
            int currScore = 0;
            for (int j = 0; j < currWord.size(); j++)
            {
                currScore += score[currWord[j] - 'a'];
            }
            arrScore.push_back(currScore);
        }
    }
    for (auto el : arrScore)
    {
        cout << el << " ";
    }
}
int main()
{
    vector<string> words = {"dog", "cat", "dad", "good"};
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