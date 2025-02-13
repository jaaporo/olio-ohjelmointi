#include "student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(string name, int age) :name(name), Age(age) {}

void Student::setAge(int age)
{
   
    Age = age;
}

void Student::setName(string name)
{
  
    this->name = name;
}

string Student::getName() const
{
    return name;
}

int Student::getAge()const
{
    return Age;
}

void Student::printStudentInfo()const
{
    cout<<"Opiskelijan nimi: "<<name<<", ika: "<<Age<<endl;
}
