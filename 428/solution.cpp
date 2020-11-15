#include <vector>
#include <iostream>

using namespace std;

int cost_to_build(vector<int>& stones) {
    int cost = 0;
    int N = stones.size();
    vector<int> left = vector<int>(N, 0), right = vector<int>(N, 0), total = vector<int>(N, 0);
    // step 1: Calculate the max-height possible for the pyramid
    // minimum height possible for a position is the minimum of 
    // 1+ the height of previous location, 
    // it's current height
    // and it's position i+1
    left[0] = min(0+1, stones[0]);
    for (int i=0; i<N; i++) {
        left[i] = min({left[i-1]+1, stones[i], i+1});
    }
    right[N-1] = min(N-(N-1), stones[N-1]);
    for (int i=N-2; i>=0; i--) {
        right[i] = min({right[i+1]+1, stones[i], N-i});
    }

    for (int i=0; i<N; i++) {
        total[i] = min(left[i], right[i]);
    }

    // Step 2: Chip away so heights really do increment/decrement by 1
    // Step 2a: Find max point
    int max_ind = 0;
    for (int i=0; i<N; i++) {
        if (total[i] > total[max_ind]) {
            max_ind = i;
        }
    }

    // Step 2b: Chip away assuming that the pyramid's middle is at max_ind
    for (int i=max_ind-1; i>=0; i--){
        total[i] = max(total[i+1]-1, 0);
    }
    for (int i=max_ind+1; i<N; i++){
        total[i] = max(total[i-1]-1, 0);
    }

    // now compute the cost to demolish such a pyramid
    for (int i=0; i<N; i++) {
        cost += stones[i] - total[i];
    }

    cout << "Pyramid = " << endl;
    for (int i=0; i<N; i++) {
        cout << total[i] << " ";
    }
    cout << endl;
    return cost;
}


int main() {
    // vector<int> stones = {1, 1, 3, 3, 2, 1};
    vector<int> stones = {1, 2, 3, 4, 2, 1};
    int cost = cost_to_build(stones);
    cout << "cost to build = " << cost << endl;   
}