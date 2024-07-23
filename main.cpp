#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll maxNum = *max_element(a.begin(), a.end());
    ll minNum = *min_element(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (n == 2 && a[i] == minNum) {
            cout << -1 << endl;
            continue;
        }
        ll res = sum;
        if (a[i] == maxNum) {
            cout << sum << endl;
        } else if (a[i] == minNum) {
            if (maxNum - a[i] <= n - 1) {
                res += (maxNum - a[i]) * 2 - 1;
                cout << res << endl;
            } else {
                res += 2 * (maxNum - a[i] - n + 1) + (maxNum - a[i]) * 2 - 1;
                cout << res << endl;
            }
        } else {
            res += (maxNum - a[i]) * 2 - 1;
            cout << res << endl;
        }
    }
}