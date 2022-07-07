#include <bits/stdc++.h>
using namespace std;
int main()
{
	deque<int> dq(5);
	while(!dq.empty()){
		cout << dq.front() << " ";
		dq.pop_front();
	}
}
