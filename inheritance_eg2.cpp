#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    string name;
    int age;
};

class Student : public Person {
public: 
    int rollno;
};

class GradStudent : public Student {
public: 
    string researchArea;
};

// Main function
int main(){
    GradStudent s1;
    s1.name = "Tony Stark";
    s1.researchArea = "Quantam Physics";
    cout << s1.name << endl;
    cout << s1.researchArea << endl;

    return 0;
}
