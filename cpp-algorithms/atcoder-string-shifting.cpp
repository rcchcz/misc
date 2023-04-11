// https://atcoder.jp/contests/abc223/tasks/abc223_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; 
    cin >> s;
    int n = size(s);
    vector<string> v(n);
    for(int i = 0; i < n; i++) { v[i] = s.substr(i, n - i) + s.substr(0, i); }
    cout << *min_element(begin(v), end(v)) << endl;
    cout << *max_element(begin(v), end(v)) << endl;
}
