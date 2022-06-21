//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){
        cout << "i am from animal";
    }
};
class Dog : public Animal{
    public:
    void speak(){
        cout << " i am from child";
    }
};

int main(){
    Dog dog;
    Animal *ptr = &dog;
    ptr -> speak();
}