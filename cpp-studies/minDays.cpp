#include <bits/stdc++.h>
using namespace std;

// 'minDays' returns the minimum amount of days to watch all movies
// each element of 'duration' represents the duration of a movie
// a movie started is always finished on the same day
// the maximum time of movies watched per day is 3 hours
int minDays(vector<float> duration) {
    sort(duration.begin(), duration.end());

    size_t back = duration.size() - 1;
    size_t front = 0;
    double sumHours = duration[back];
    int days = 0;

    while(front != back) {
        if(sumHours + duration[front] <= 3) {
            sumHours += duration[front];
            front++;
        } else {
            days++;
            back--;
            sumHours = duration[back];
        }
        
        if(front == back) { days++; }
        
    }

    return days;
}

int main() {
    vector<float> duration = {1.90, 1.04, 1.25, 2.5, 1.75}; // min 3 days | {1.04 1.25 1.75 1.9 2.5}
    // vector<float> duration = {1.01, 1.32, 1.4, 1.991}; // min 3 days
    cout << minDays(duration) << endl;
}
