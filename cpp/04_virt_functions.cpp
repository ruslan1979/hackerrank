//
// Created by Ruslan on 02.05.2018.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
Developer:     Ruslan Arifullin
Date:          MAY 03 2018

DIFFICULTY:    Medium
               
PROBLEM:       
               
               This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. 
               The class Person should have data members name and age. The classes Professor and Student should inherit from 
               the class Person.
               The class Professor should have two integer members: publications and cur_id. There will be two member functions: 
               getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the 
               professor. The function putdata should print the name, age, publications and the cur_id of the professor.               
               The class Student should have two data members: marks, which is an array of size and cur_id. It has two member 
               functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks 
               of the student in 6 subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the 
               student.               
               For each object being created of the Professor or the Student class, sequential id's should be assigned to them 
               starting from 1.
               Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.               

TESTCASE:      4
               1
               Walter 56 99
               2
               Jesse 18 50 48 97 76 34 98
               2
               Pinkman 22 10 12 0 18 45 50
               1
               White 58 87
               
OUTPUT:        Walter 56 99 1
               Jesse 18 403 1
               Pinkman 22 135 2
               White 58 87 2
*/

using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {}
    virtual void getdata() {}

    virtual void putdata() {}
    virtual ~Person() {}
};

class Professor : public Person {
    static int id ;
private:
    int publications;
    int cur_id;
public:
    Professor() {
        cur_id = ++id;
    }
    void getdata() {
        cin >> name >> age >> publications;
    }

    void putdata() {
        cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << endl;
    }
};

class Student : public Person {
    static int id;
private:
    int marks[6];
    int cur_id;
public:
     Student() {
         cur_id = ++id;
     }

     void getdata() {
        cin >> name >> age;
        for (size_t i = 0; i < 6; ++i) {
            cin >> marks[i];
        }
    }

    void putdata() {
        int sum = 0;
        for (size_t i = 0; i < 6; ++i) {
            sum += marks[i];
        }

        cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << endl;
    }

};

int Student::id;
int Professor::id;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}