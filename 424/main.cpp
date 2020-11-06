#include <iostream>


using namespace std;

int main() {
    int n;
    cout << "Enter the number of numbers: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the numbers (one in each line) " << endl;
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = 0;

    for (int i=0; i < n; i++) {
        sum  ^= arr[i];
    }
    cout << "Bits set after xor: " << sum << endl;
    cout << endl;

    cout << "The numbers that are not in pairs are: ";
    sum = sum&~(sum-1);  // lowest set bit
    int tmp = 0;
    for (int i=0; i < n; i++) {
        if (sum & arr[i]) {
            tmp ^= arr[i];
        }
    }
    cout << tmp << " and ";
    tmp = 0;
    for (int i=0; i < n; i++) {
        if (!(sum & arr[i])) {
            tmp ^= arr[i];
        }
    }
    cout << tmp << endl;;

    delete[] arr;
    return 0;
}