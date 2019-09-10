#include <algorithm>
#include <iostream>

using namespace std;

bool twosum(int *a, int n, int k);

int _main() {
    int n, k;
    int *a;
    cout << " Enter the number of elements in the array :";
    cin >> n;

    a = new int[n];

    cout << "Enter " << n << " numbers :";

    for (int i=0; i< n; i++) {
        cin >> a[i];
    }
    cout << "Enter k: " << endl;
    cin >> k;

    cout << "Two sum exists ? =" << boolalpha << twosum(a, n, k) << endl;

    delete [] a;
    return 0;
}

bool twosum(int *a, int n, int k) {
    std::sort(a, a+n);
    int i=0, j=n-1;
    while (i<j) {
        if (a[i]+a[j] == k) {
            return true;
        } else if (a[i]+a[j] < k) {
            i+=1;
        } else {
            j-=1;
        }
    }
    return false;
}