#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
/*
Developer:     Ruslan Arifullin
Date:          MAY 01 2018

DIFFICULTY:    Medium
               
PROBLEM:       Your friend set up a small computational server that performs 
               complex calculations.
               It has a function that takes large numbers as its input and 
               returns a numeric result. Unfortunately, there are various 
               exceptions that may occur during execution.
               
               Complete the code in your editor so that it prints appropriate 
               error messages, should anything go wrong. The expected behavior
               is defined as follows:
               
                   If the compute function runs fine with the given arguments, 
               then print the result of the function call.
                   If it fails to allocate the memory that it needs, print 
               Not enough memory.
                   If any other standard C++ exception occurs, print Exception: S 
               where is the exception's error message.
                   If any non-standard exception occurs, print Other Exception.
              
               
                ---- testcase 1  ------
                2
                -8 5
                1435434255433 5
                
                ---- output ----
                Exception: A is negative
                Not enough memory
                2
                
                ---- testcase 2 ----
                100
                -9252 888
                25581 3661
                3850 921492
                6003 0
                51975592548100 2718
                47661 3500
                47359 1567
                35522339043844 9712
                8144 969179
                18206520948100 6545
                40906 3565
                -6316 4606
                1035 790526
                38409 1080
                -4050 137
                -6900 3340
                -2277 6815
                81701 8110
                -8976 8927
                37237 1968
                1329 181341
                27688 6179
                78674 2832
                2198 156405
                4603 880384
                -7734 9449
                -943 2118
                2156 0
                63962 6110
                71773 2016
                55971 1374
                24945 6999
                28097 8185
                97017 9190
                51524301309849 7375
                9638 605678
                8472 474502
                95055 2311
                93328 2258
                1043 354662
                8738 762278
                3396 0
                88664 2585
                -4774 2115
                37301 5243
                -6930 6810
                -8508 2179
                63371 4545
                44539 9030
                1836 0
                77145129232900 9719
                7281 998198
                41631555871504 3349
                -1469 85
                -1996 3640
                7672 364991
                37936 9799
                9139 345963
                43523 5381
                -8993 6866
                96392279653849 8466
                66332 5657
                46239 1381
                64632563355844 242
                6035 0
                -5141 4338
                2097 0
                6184467685881 4571
                47114 2625
                9781 0
                44422 4681
                85037 2451
                4536 299270
                8551 869254
                76457 4900
                57093 8026
                43440 6391
                69531 5943
                -2723 1918
                5348 581077
                72807 1188
                93944 9862
                12260 3457
                2631 0
                56836 9843
                8973 0
                3480 0
                52288937369881 2642
                84658 5338
                1707135617476 2249
                4233 0
                5175 428523
                4989 508317
                46515400848400 7053
                -8995 4278
                83283 8616
                41063 4118
                78317 1048
                5817 713028
                -2755 5249
                
                ---- output -----
                Exception: A is negative
                25575
                Exception: vector::_M_range_check: __n (which is 921492) >= this->size() (which is 3850)
                Other Exception
                Not enough memory
                47648
                47329
                Not enough memory
                Exception: vector::_M_range_check: __n (which is 969179) >= this->size() (which is 8144)
                Not enough memory
                40895
                Exception: A is negative
                Exception: vector::_M_range_check: __n (which is 790526) >= this->size() (which is 1035)
                38374
                Exception: A is negative
                Exception: A is negative
                Exception: A is negative
                81691
                Exception: A is negative
                37219
                Exception: vector::_M_range_check: __n (which is 181341) >= this->size() (which is 1329)
                27684
                78647
                Exception: vector::_M_range_check: __n (which is 156405) >= this->size() (which is 2198)
                Exception: vector::_M_range_check: __n (which is 880384) >= this->size() (which is 4603)
                Exception: A is negative
                Exception: A is negative
                Other Exception
                63952
                71738
                55931
                24942
                28094
                97007
                Not enough memory
                Exception: vector::_M_range_check: __n (which is 605678) >= this->size() (which is 9638)
                Exception: vector::_M_range_check: __n (which is 474502) >= this->size() (which is 8472)
                95014
                93287
                Exception: vector::_M_range_check: __n (which is 354662) >= this->size() (which is 1043)
                Exception: vector::_M_range_check: __n (which is 762278) >= this->size() (which is 8738)
                Other Exception
                88630
                Exception: A is negative
                37294
                Exception: A is negative
                Exception: A is negative
                63358
                44535
                Other Exception
                Not enough memory
                Exception: vector::_M_range_check: __n (which is 998198) >= this->size() (which is 7281)
                Not enough memory
                Exception: A is negative
                Exception: A is negative
                Exception: vector::_M_range_check: __n (which is 364991) >= this->size() (which is 7672)
                37933
                Exception: vector::_M_range_check: __n (which is 345963) >= this->size() (which is 9139)
                43515
                Exception: A is negative
                Not enough memory
                66321
                46206
                Not enough memory
                Other Exception
                Exception: A is negative
                Other Exception
                Not enough memory
                47097
                Other Exception
                44413
                85003
                Exception: vector::_M_range_check: __n (which is 299270) >= this->size() (which is 4536)
                Exception: vector::_M_range_check: __n (which is 869254) >= this->size() (which is 8551)
                76442
                57086
                43434
                69520
                Exception: A is negative
                Exception: vector::_M_range_check: __n (which is 581077) >= this->size() (which is 5348)
                72746
                93935
                12257
                Other Exception
                56831
                Other Exception
                Other Exception
                Not enough memory
                84643
                Not enough memory
                Other Exception
                Exception: vector::_M_range_check: __n (which is 428523) >= this->size() (which is 5175)
                Exception: vector::_M_range_check: __n (which is 508317) >= this->size() (which is 4989)
                Not enough memory
                Exception: A is negative
                83274
                41054
                78243
                Exception: vector::_M_range_check: __n (which is 713028) >= this->size() (which is 5817)
                Exception: A is negative
                100 
*/

using namespace std;

class Server {
private:
    static int load;
public:
    static int compute(long long A, long long B) {
        load += 1;
        if(A < 0) {
            throw std::invalid_argument("A is negative");
        }
        vector<int> v(A, 0);
        int real = -1, cmplx = sqrt(-1);
        if(B == 0) throw 0;
        real = (A/B)*real;
        int ans = v.at(B);
        return real + A - B*ans;
    }
    static int getLoad() {
        return load;
    }
};
int Server::load = 0;

int main() {
    int T; cin >> T;
    while(T--) {
        long long A, B;
        cin >> A >> B;
        /* Enter your code here. */
        try {
            cout << Server::compute(A, B) << endl;
        }
        catch (bad_alloc& e) {
            cout << "Not enough memory" << endl;
        }
        catch (exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        catch (...){
            cout << "Other Exception" << endl;
        }
       }
	cout << Server::getLoad() << endl;
	return 0;
}