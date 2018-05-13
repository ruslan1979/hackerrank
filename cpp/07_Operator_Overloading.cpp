#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
Developer:     Ruslan Arifullin
Date:          MAY 13 2018

DIFFICULTY:    Medium

PROBLEM:       You are given a main() function which takes a set of inputs to create two matrices
               and prints the result of their addition. You need to write the class Matrix which 
               has a member a of type vector<vector<int> >. You also need to write a member function 
               to overload the operator +. The function's job will be to add two objects of Matrix 
               type and return the resultant Matrix.

                    Input Format

               First line will contain the number of test cases T. For each test case, there are three 
               lines of input.
                The first line of each test case will contain two integers N and M which denote the number
                of the rows and columns respectively of the two matrices that will follow on the next two lines. 
                These next two lines will each contain N*M elements describing the two matrices in row-wise format 
                i.e. first M elements belong to the first row,next M elements belong to the second row and so on.
                
                Output Format

                The code provided in the editor will use your class Matrix and overloaded operator function to add the 
                two matrices and give the output.
                
INPUT:         1
               2 2
               2 2 2 2
               1 2 3 4
               
OUTPUT:        3 4 
               5 6
              
EXPLANATION:   The sum of first matrix and the second matrix is the matrix given in the output.             
*/

using namespace std;

class Matrix {
    public:
        vector<vector<int>> a;
    
        Matrix& operator + (const Matrix &b) {
            for (size_t i = 0; i != b.a.size(); ++i)
                for (size_t j = 0; j != b.a[0].size(); ++j) {
                    this->a[i][j] = this->a[i][j] + b.a[i][j];
                }
            
            return *this;
        }    
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}