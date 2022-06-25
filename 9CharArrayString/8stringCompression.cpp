//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<vector>
using namespace std;
int compress(vector<char>& chars) {
        int size = chars.size();
        int i = 0, count, j;
        while(i < size - 1){
            count = 1;
            j = i + 1;
            while(j < size && chars[i] == chars[j]){
                chars.erase(chars.begin() + j);
                count++;
                size--;
            }
            i = j;
            if(count > 1) 
            {
                int digit;
                while(count > 0){
                    digit = count % 10;
                    chars.insert(chars.begin() + j, '0' + digit);
                    count = count / 10;
                    i++;
                    size++;
                }
            }            
        }
        return size;

    }
void printVector(vector<char> &ans){
    for(auto ch: ans){
        cout << ch << " ";
    }
    cout << endl;
}
int main(){
    vector<char> input = {'a', 'b', 'b', 'b','b', 'b', 'b','b', 'b', 'b','b', 'b', 'b'};
    cout << compress(input) << endl;
    printVector(input);


}