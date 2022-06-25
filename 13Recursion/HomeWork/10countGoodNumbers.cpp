// Problem Link - https://leetcode.com/problems/count-good-numbers/
/* By Krishna Kumar */
#include <iostream>
using namespace std;
long long power(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long ans = power(a, b / 2);
    ans = (ans % 1000000007) * (ans % 1000000007) % 1000000007;
    if (b & 1)
    {
        ans = (a % 1000000007) * (ans % 1000000007) % 1000000007;
    }
    return ans;
}
int main()
{
    long long n = 4;
    long long oddPosition = n / 2;
    long long evenPosition = n - oddPosition;
    long long oddPositionAnswer = power(4, oddPosition);
    long long evenPositionAnswer = power(5, evenPosition);
    long long fans = (oddPositionAnswer % 1000000007) * (evenPositionAnswer % 1000000007) % 1000000007;
    cout << fans;
}