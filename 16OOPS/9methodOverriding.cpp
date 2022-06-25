//Problem Link - 
/* By Krishna Kumar */
#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){
        cout << "i speack";
    }
};
class Dog : public Animal{
    //method overriding
    public:
    void speak(){
        cout << "dog barks" << endl;
    }
};
int main(){
    Dog dog;
    dog.speak();
}