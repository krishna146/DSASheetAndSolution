//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class Calculator{
    public:
    int add(int a, int b){
        return a + b;
    }
    int add(int a, int b, int c){
        return a + b + c;
    }


};
int main(){
    Calculator calc;
    calc.add(2, 3);
    calc.add(4, 5, 5);
}