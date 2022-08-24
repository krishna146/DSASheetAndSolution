#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> arr = {1,1, 2, 4, 6, 7, 8 , 20};
  int idx = lower_bound(arr.begin(), arr.end(), 21) - arr.begin();
  cout << idx << endl;
}
