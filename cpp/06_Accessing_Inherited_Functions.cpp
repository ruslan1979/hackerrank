#include<iostream>

/*
Developer:     Ruslan Arifullin
Algor Impl:    noorvir_aulakh (https://www.hackerrank.com/noorvir_aulakh?hr_r=1)
Date:          MAY 12 2018

DIFFICULTY:    Medium

PROBLEM:       You are given three classes A, B and C. All three classes implement their own version of func.
               You need to modify the class D and implement the function update_val which sets D's val to new_val
               by manipulating the value by only calling the func defined in classes A, B and C.
               It is guaranteed that new_val has only and as its prime factors.

TESTCASE 1:
  input:       30
  output:      Value = 30
               A's func called 1 times
               B's func called 1 times
               C's func called 1 times

TESTCASE 2:
   input:      180
   output:     Value = 180
               A's func called 2 times
               B's func called 2 times
               C's func called 1 times
*/


using namespace std;

class A
{
public:
    A(){
        callA = 0;
    }
private:
    int callA;
    void inc(){
        callA++;
    }

protected:
    void func(int & a)
    {
        a = a * 2;
        inc();
    }
public:
    int getA(){
        return callA;
    }
};

class B
{
public:
    B(){
        callB = 0;
    }
private:
    int callB;
    void inc(){
        callB++;
    }
protected:
    void func(int & a)
    {
        a = a * 3;
        inc();
    }
public:
    int getB(){
        return callB;
    }
};

class C
{
public:
    C(){
        callC = 0;
    }
private:
    int callC;
    void inc(){
        callC++;
    }
protected:
    void func(int & a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC(){
        return callC;
    }
};

class D : public A, public B, public C
{

    int val;
public:
    //Initially val is 1
    D()
    {
        val = 1;
    }


    //Implement this function
    void update_val(int new_val)
    {
        val = new_val;
        int a = new_val;
        while (a % 2 == 0) {
            a /= 2;
            A::func(new_val);
        }

        while (a % 3 == 0) {
            a /= 3;
            B::func(new_val);
        }

        while (a % 5 == 0) {
            a /= 5;
            C::func(new_val);
        }
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
}