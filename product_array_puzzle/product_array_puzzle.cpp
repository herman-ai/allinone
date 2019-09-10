#include <iostream>
using namespace std;

int * product_array(int *a, int n);

int _main() {
    int n;
    int *a;
    cout << "How many numbers :";
    cin >> n;
    a = new int [n];
    cout << "Enter " << n << " numbers :";
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    product_array(a, n);
    cout << "Result " << endl;
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete [] a;
    return 0;
}
int * product_array(int *a, int n) {
    int * left, * right;
    left = new int [n];
    right = new int [n];

    left[0] = 1;
    right[n-1] = 1;

    for (int i=0; i<n; i++) {
        if (i-1 >= 0)
            left[i] = left[i-1]*a[i-1];
        if (n-i < n)
            right[n-1-i] = right[n-i]*a[n-i];
    }

    // cout << "Left " << endl;
    // for (int i=0; i<n; i++) {
    //     cout << left[i] << " ";
    // }
    // cout << endl << "Right " << endl;
    // for (int i=0; i<n; i++) {
    //     cout << right[i] << " ";
    // }
    // cout << endl;

    for (int i=0; i<n; i++) {
        a[i] = left[i] * right[i];
    }

    delete [] left;
    delete [] right;
    return a;
}