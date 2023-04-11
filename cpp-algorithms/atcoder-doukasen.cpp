// https://atcoder.jp/contests/abc223/tasks/abc223_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long double t = 0, ans = 0;
    cin >> n;
    vector<long double> a(n), b(n);
    for(int i = 0; i < n; i++) { cin >> a[i] >> b[i]; t += (a[i]/b[i])/2; }
    for(int i = 0; i < n; i++) { 
        if(t > a[i]/b[i]) { t -= a[i]/b[i]; ans += a[i]; }
        else { ans += t*b[i]; break; }
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}
