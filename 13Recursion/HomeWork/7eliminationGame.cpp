// Problem Link - https://leetcode.com/problems/elimination-game/
/* By Krishna Kumar */
#include <iostream>
int rightToLeft(int);
using namespace std;
int leftToRight(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return 2 * rightToLeft(n / 2);
}
int rightToLeft(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n & 1)
    {
        return 2 * leftToRight(n / 2);
    }
    return 2 * leftToRight(n / 2) - 1;
}
int main()
{
    cout << leftToRight(5);
    return 0;
}