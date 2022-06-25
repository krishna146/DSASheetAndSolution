//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
#include<string>
using namespace std;
void printBinarySequence(int LS, int RS, char *input, int i, int j){
    if(i > j){
        if(LS == RS){
            cout << input << endl;
            return;
        }
        return;
    }
    //put 0, 0
    input[i] = '0';
    input[j] = '0';
    printBinarySequence(0, 0, input, i + 1, j - 1);
    //put 0, 1
    input[i] = '0';
    input[j] = '1';
    printBinarySequence(0, 1, input, i + 1, j - 1);
    //put 1, 0
    input[i] = '1';
    input[j] = '0';
    printBinarySequence(1, 0, input, i + 1, j - 1);
    //put 1, 1
    input[i] = '1';
    input[j] = '1';
    printBinarySequence(1, 1, input, i + 1, j - 1);
}
int main(){
    int n;
    cin >> n;
    char *input = new char[2 * n];
    printBinarySequence(0, 0, input, 0, 2 * n - 1);


}