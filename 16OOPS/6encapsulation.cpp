//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class Human{
    private:
    int age;
    int weight;
    string name;
    public:
    int getAge(){
        return this -> age;
    }
};
//single level
class Female : public Human{

};
//multilevel
class StubbornGirl : public Female{

};

int main(){
    Human krishna;
    Female sushma;
    sushma.getAge();
}