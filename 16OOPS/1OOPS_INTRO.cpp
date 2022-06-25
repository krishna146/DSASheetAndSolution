// Problem Link -
/* By Krishna Kumar */
#include <iostream>
using namespace std;
class Human
{
public:
    int age;
    char gender;

    Human()
    {
        age = 0;
        gender = 'F';
        cout << "I am in Constructor" << endl;
    }
    ~Human(){
        cout << "I am in destructor" << endl;
    }
    Human(int age, char gender)
    {
        this->age = age;
        this->gender = gender;
        cout << "I am in P Constructor" << endl;
    }
    // Human(Human &obj){
    //     cout << "I am in copy constructor" << endl;
    //     this -> age = obj.age;
    //     this -> gender = obj.gender;
    // }
    char getGender()
    {
        return gender;
    }
    void setGender(char ch)
    {
        gender = ch;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int a)
    {
        age = a;
    }
};

int main()
{
    Human obj1, objx;
    obj1.age = 100;
    Human *obj2 = new Human();
    Human *obj3 = new Human(12, 'f');
    Human *obj4 = new Human(obj1);
    cout << obj1.age << endl;
    cout << obj2->age << endl;
    cout << obj3->gender << endl;
    cout << obj3->age << endl;
    cout << obj4 -> age << endl;
    cout << obj4 -> age << endl;
    delete obj2;
    delete obj3;
    delete obj4;
    return 0;
}