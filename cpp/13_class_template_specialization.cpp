#include <iostream>

/*
Developer:      Ruslan Arifullin
Date:           JUN 03 2018
                
DIFFICULTY:     Medium
    
PROBLEM:        You are given a main function which reads the enumeration values for two different
                types as input, then prints out the corresponding enumeration names. Write a class 
                template that can provide the names of the enumeration values for both types. If the
                enumeration value is not valid, then print unknown.

SAMPLE INPUT:   2
                1 0
                3 3

SAMPLE OUTPUT:  green apple
                unknown unknown
    
*/

using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template<> struct Traits<Fruit> {
public:
    static string name(int index) {
        switch (index){
            case 0: return "apple";
            case 1: return "orange";
            case 2: return "pear";
        }

        return "unknown";
    }
};

template<> struct Traits<Color> {
public:
    static string name(int index) {
        switch (index){
            case 0: return "red";
            case 1: return "green";
            case 2: return "orange";
        }

        return "unknown";
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}


