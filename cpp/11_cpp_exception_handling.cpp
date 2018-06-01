#include <iostream>
#include <stdexcept>

/*
Developer:   Ruslan Arifullin
Date:        JUN 01 2018
             
DIFFICULTY:  Medium

PROBLEM:     You are required to extend the existing code so that it handles std::invalid_argument exception properly. More specifically, you have
             to extend the implementation of process_input function. It takes integer as an argument and has to work as follows:
             
             It calls function largest_proper_divisor(n).
             If this call returns a value without raising an exception, it should print in a single line result=d where is the returned value.
             Otherwise, if the call raises a std::invalid_argument exception, it has to print in a single line the string representation of the raised 
             exception, i.e. its message. Finally, no matter if the exception is raised or not, it should print in a single line returning control flow
             to caller after any other previously printed output.
             
             To keep the code quality high, you are advised to have exactly one line printing returning control flow to caller in the body of process_input function.
             
             Your function will be tested against several cases by the locked template code.

INPUT:       0
              
OUTPUT:      largest proper divisor is not defined for n=0
             returning control flow to caller
              

INPUT:       1
              
OUTPUT:      result=3
             returning control flow to caller           

*/

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }    
    
    cout << "returning control flow to caller" << endl;    
}

int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}

