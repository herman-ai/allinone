#include "vacation.hpp"
#include <iostream>

int vacation_days::get_max_vacation(int vac) {
    int f = -1;
    int i = 0;
    int max_vac = 0;
    while(i<calendar.size()) {
        i = f + 1;
        int v = 0;
        int vl = vac;
        bool first_vacation = true;
        while (vl >= 0 && i < calendar.size()) {
            if (calendar[i] == false) {
                vl--;
                if (first_vacation) {
                    f = i;
                    first_vacation = false;
                }
            }
            if (vl>=0) {
                v++;
                i++;
            }
        }
        max_vac = max(v, max_vac);
    }
    return max_vac;
}

int _main() {
    vacation_days vd({true, true, false, false, true, true, true, false, false, false, true});
    cout << "The maximum number of vacation days possible = " << vd.get_max_vacation(1) << endl;
    return 0;
}