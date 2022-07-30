//Problem Link - 
/* By Krishna Kumar */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    unordered_map<char, int> ump;
    pair<char,int> p = make_pair('a', 3);
    ump.insert(p);
    ump['b'] = 3;
    ump.insert({'c', 5});
    cout << ump['b'] << endl;
    cout << ump['z'] << endl;
    cout << ump.size() << endl;
    cout << ump.empty() << endl;
    // a present or not
    cout << ump.count('a') << endl;
    //d present or not
    cout << ump.count('j') << endl;

    cout << ump['j'] << endl;
    cout << ump.count('j') << endl;
    unordered_map<char, int> :: iterator i = ump.find('a');
    if(i == ump.end()){
        cout << "not present" << endl;
    }else{
        cout << "present" << endl;
    }
    unordered_map<char, int> :: iterator it = ump.find('m');
    if(it == ump.end()){
        cout << "not present" << endl;
    }else{
        cout << "present" << endl;
    }
    return 0;
}