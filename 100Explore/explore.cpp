#include <bits/stdc++.h>
using namespace std;
void printVectorString(vector<string> &ump)
{
	for (int i = 0; i < ump.size(); i++)
	{
		for (int j = 0; j < ump[i].size(); j++)
		{
			cout << ump[i][j];
		}
		cout << endl;
	}
}
int main()
{
	// string s(2, '.');
	// s[0] = 'c';
	// cout << s ;
	// vector<string> ump(2, string(2, '.'));
	// for(int i = 0 ; i < 2 ; i++){
	// 	for(int j = 0 ; j < 2 ; j++){
	// 		ump[i][j] = 'h';
	// 	}
	// 	cout << endl;
	// }
	// printVectorString(ump);
	// for (int i = 0; i < 2 ; i++)
	// {
	// 	for(int j = 0 ; j < ump[i].size() ; j++){
	// 		cout << ump[i][j];
	// 	}
	// 	cout << endl;
	// }
	string s = "krishna";
	s.erase(s.begin() + 1);
	cout << s << endl;
	s.insert(s.begin() + 1, 'r');
	cout << s << endl;
}
