#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;
/*
Developer:     Ruslan Arifullin
Date:          APR 29 2018

DIFFICULTY:    Medium
               
PROBLEM:       You inherited a piece of code that performs username validation for your company's 
               website. The existing function works reasonably well, but it throws an exception 
               when the username is too short. Upon review, you realize that nobody ever defined 
               the exception. 
               The inherited code is provided for you in the locked section of your editor. Comp
               lete the code so that, when an exception is thrown, it prints Too short: n (where n 
               is the length of the given username). 

SAMPLE INPUT:

3
Peter
Me
Arxwwz

SAMPLE OUTPUT:

Valid
Too short: 2
Invalid

EXPLANATION:   Username Me is too short because it only contains characters, so your exception prints 
               Too short : 2.
               All other validation is handled by the locked code in your editor.

*/

class BadLengthException : public exception {
private:
	int exceptionValue;
public:
	explicit BadLengthException(const int& n) {
		exceptionValue = n;
	}

	virtual ~BadLengthException() throw() {}

	virtual const char* what() const throw() {
		cout << exceptionValue;
		return "";
	}
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
}