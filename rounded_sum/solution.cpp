/*
You are given an array X of floating-point numbers x1, x2, ... xn. 
These can be rounded up or down to create a corresponding array Y of integers y1, y2, ... yn.
Write an algorithm that finds an appropriate Y array with the following properties:
	•	The rounded sums of both arrays should be equal.
	•	The absolute pairwise difference between elements is minimized. 
        In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. 
In this case you cannot do better than [1, 2, 5], which has an absolute difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.

[1.3, 2.3, 4.4] = 8.0
[0.3, 0.3, 0.4] = SUM needs to be 1
[0,   0 ,  1]  
[1,   2,   5] 
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <functional>
using namespace std;

int sum_int(const vector<float> & v) {
   int sum = 0;
   for (int i=0; i< v.size(); i++) {
       sum += static_cast<int>(v[i]);
   } 
   return sum;
}

struct my_less_than {
    bool operator()(const float & v1, const float & v2) {
        if ((v1 - floor(v1)) <= (v2 - floor(v2))) {
            return true;
        }
        return false;
    }
};

int _main() {
    vector<float> in = {1.9, 2.8, 3.1, 6.1, 9.8};
    sort(in.begin(), in.end(), my_less_than());
    for (int i=0; i<in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << endl;
    float sum = accumulate(in.begin(), in.end(), 0.0);
    int rounded_sum = static_cast<int>(round(sum));
    int base_sum = sum_int(in);
    int remainder = rounded_sum - base_sum;
    for (int i=in.size()-1; i>=0; i--) {
        if (in.size()-i <= remainder)
            in[i] = ceil(in[i]);
        else
            in[i] = floor(in[i]);
    }
    for (int i=0; i<in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << endl;
    return 0;
}