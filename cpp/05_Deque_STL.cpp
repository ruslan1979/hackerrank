#include <iostream>
#include <deque>

/*
Developer:     noorvir_aulakh
Algor Impl:    noorvir_aulakh (https://www.hackerrank.com/noorvir_aulakh?hr_r=1)
Date:          MAY 11 2018

DIFFICULTY:    Medium
               
PROBLEM:       Given a set of arrays of size N and an integer K, you have to find the maximum integer for each and every contiguous 
               subarray of size K for each of the given arrays.               
               
TESTCASE:      2
               5 2
               3 4 6 3 4
               7 4
               3 4 5 8 1 4 10            
                 
OUTPUT:        4 6 6 4
               8 8 8 10 
                         
*/

using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> dq(n);

    for (int i = 0; i != n; ++i) {
        //base case for first element
        if (dq.empty()) {
            dq.push_back(i);
        }

        //removing elements outside of the current window
        if (dq.front() <= (i - k)) {
            dq.pop_front();
        }

        //move max element to the front
        while (!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);

        //print out when the first element is completed
        if (i>= (k - 1))
            cout << arr[dq.front()] << " ";
    }

    cout << endl;
}

int main(){

    int t;
    scanf("%d", &t);
    //cin >> t;
    while(t>0) {
        int n,k;
        scanf("%d%d", &n, &k);
        //cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            scanf("%d", &arr[i]);
            //cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}