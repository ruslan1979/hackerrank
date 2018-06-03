#include<bits/stdc++.h>

/*
Developer:      Ruslan Arifullin
Date:           JUN 01 2018
                
DIFFICULTY:     Medium
                
PROBLEM:        A student signed up for n workshops and wants to attend the maximum number 
                of workshops where no two workshops overlap. You must do the following:
                
                Implement 2 structures:
                
                struct Workshop having the following members:
                    The workshop's start time.
                    The workshop's duration.
                    The workshop's end time.
                
                struct Available_Workshops having the following members:
                    An integer n, (the number of workshops the student signed up for).
                    An array of type Workshop array having size n.
                
                Implement 2 functions:
                
                    Available_Workshops* initialize (int start_time[], int duration[], int n)
                    Creates an Available_Workshops object and initializes its elements using 
                    the elements in the start_time[] and duration[] parameters (both are of size n). 
                    Here,start_time[i] and duration[i] are the respective start time and duration for 
                    the i__th workshop. This function must return a pointer to an Available_Workshops object.
                
                    int CalculateMaxWorkshops(Available_Workshops* ptr)
                    Returns the maximum number of workshops the student can attend—without overlap. The next 
                    workshop cannot be attended until the previous workshop ends.
                    
                An array of unknown size () should be declared as follows:
                DataType* arrayName = new DataType[n];


SAMPLE INPUT:   6
                1 3 0 5 5 8
                1 1 6 2 4 1
SAMPLE OUTPUT:  4
    
*/

using namespace std;

    struct Workshop {
        int start_time;
        int duration;
        int end_time;
    };
    struct Available_Workshops {
        int n;
        vector<Workshop> workshop;
    };

bool compare(Workshop w1, Workshop w2) {
    return w1.end_time < w2.end_time;
}

Available_Workshops* initialize(int* start_time, int* duration, int n) {
    Available_Workshops* aw = new Available_Workshops();

    aw->n = n;
    for (int i = 0; i != n; ++i) {
        Workshop w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        aw->workshop.push_back(w);
    }

    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int lastTime = 0;
    int maxWorkshops = 0;

    sort(ptr->workshop.begin(), ptr->workshop.end(), compare);
    for (auto& it : ptr->workshop) {
        if (it.start_time >= lastTime){
            maxWorkshops++;
            lastTime = it.end_time;
        }
    }

    return maxWorkshops;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

