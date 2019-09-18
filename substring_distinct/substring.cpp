#include "substring.hpp"
#include <iostream>
#include <string>
#include <set>

using namespace std;


int longest(string s, int k) {
    int i=0, j=0;
    int rval = 0;

    while (i<s.size()) {
        int cl=0;
        bool next_start_found = true;
        set<char> seen;
        for (i=j; i<s.size(); i++) {
            if (seen.find(s[i]) == seen.end()) {
                seen.insert(s[i]);
            }
            if (seen.size()>k) {
                break;
            }
            cl++;
            if (seen.size()==2 && next_start_found) {
                j=i;
                next_start_found = false;
            }
        }
        rval = max(rval, cl);
    }
    return rval;
}

int _main() {
    int k = 2;
    string s = "abbcabcccb";
    cout << "Length of longest substring with " << k << " distinct characters" << endl;
    cout << "in " << s << " is " << longest(s, k) << endl;
    return 0;
}