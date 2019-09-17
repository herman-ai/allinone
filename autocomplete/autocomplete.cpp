#include "autocomplete.hpp"
#include <iostream>

int _main() {
    vector<string> strings = {"abc", "abbc", "def", "a", "acg"};
    auto a = autocomplete(strings);
    auto results = a.get_autocomplete("defg");
    cout << "doing autocomplete" << endl;
    for (auto w : results) {
        cout << w << endl;
    }
    return 0;
}