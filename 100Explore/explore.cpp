#include <bits/stdc++.h>
using namespace std;
int main()
{
	unordered_map<int, int> ump;
	ump[1] = 0;
	ump[2] = 3;
	for(auto el : ump){
		cout << el.second;
	}
}
