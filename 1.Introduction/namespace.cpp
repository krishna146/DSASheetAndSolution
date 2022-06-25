//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
namespace krishna
{
    int calculate(int a, int b){
        return a + b;
    }
} 
namespace sushma
{
    int calculate(int a, int b){
        return a * b;
    }
} 

int main(){
    cout << krishna::calculate(4, 8) << endl;
    cout << sushma::calculate(4, 8);
}