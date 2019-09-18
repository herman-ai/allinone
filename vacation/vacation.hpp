#ifndef _vacation_hpp
#define _vacation_hpp

#include <vector>

using namespace std;

class vacation_days {
    vector<bool> calendar;

    public:
        vacation_days(vector<bool> calendar) : calendar(calendar){};
        int get_max_vacation(int vac);
};

int _main();
#endif