//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class Human{
  public:
  static int total;
};
//definition of static variable
int Human::total = 0;
int main(){
    cout << Human::total;

}