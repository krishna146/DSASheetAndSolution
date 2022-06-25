//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
int score = 0;
void funcOne(){
    cout << score << endl;
    score++;

}
void funcTwo(){
    cout << score << endl;
    score += 2;

}
void funcThree(){
    cout << score << endl;
    score += 3;

}

int main(){
    funcOne();
    funcTwo();
    funcThree();
    const int a = 5;
    a++;
}