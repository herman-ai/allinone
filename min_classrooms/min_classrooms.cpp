#include <iostream>
#include <queue>

using namespace std;

class EndPoint {
    int t;
    bool start;
    public:
        EndPoint(int t, bool start):t(t), start(start){}
    struct CustomCompare {
        bool operator()(const EndPoint& lhs, const EndPoint &rhs) {
            if (lhs.t > rhs.t) return true;
            else if (lhs.t == rhs.t && lhs.start && !rhs.start) return true;
            return false;
        }
    };
    const int gett() const {
        return t;
        }
    const int getstart() const {
        return start;
    }
};

int _main() {
    int n, num_rooms = 0, min_rooms=0;
    cout << "Enter the number of intervals: ";
    cin >> n;
    pair<int, int> * intervals = new pair<int, int>[n];
    cout << "Enter " << n << "intervals in the form start, end " << endl;
    priority_queue<EndPoint, vector<EndPoint>, EndPoint::CustomCompare> pq;
    for (int i=0; i<n;i++) {
        cin >> intervals[i].first >> intervals[i].second;
        pq.push(EndPoint(intervals[i].first, true));
        pq.push(EndPoint(intervals[i].second, false));
    }
    cout <<"Given intervals :" << endl;
    for (int i=0; i<n;i++) {
        cout << intervals[i].first << ", " << intervals[i].second << endl;     
    }
    while (!pq.empty()) {
        EndPoint e = pq.top();
        if (e.getstart()) num_rooms++;
        else num_rooms--;
        min_rooms = min_rooms>num_rooms?min_rooms:num_rooms;
        pq.pop();
    }
    cout << "You need a minimum of " << min_rooms << endl;
    return 0;
}