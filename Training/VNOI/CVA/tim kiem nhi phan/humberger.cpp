#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;

ll ing[3], n[3], p[3], r;

bool Check (ll cnt, ll r) {
    for (int i = 0; i < 3; i++)
        if (n[i] < ing[i] * cnt)
            r -= (ing[i] * cnt - n[i]) * p[i];
    if (r >= 0) return true;
    else return false;
}

signed main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s; cin >> s;
    for (int i = 0; i < (int) s.length (); i++)
        if (s[i] == 'B') ing[0]++;
        else if (s[i] == 'S') ing[1]++;
        else ing[2]++;
    for (int i = 0; i < 3; i++)
        cin >> n[i];
    for (int i = 0; i < 3; i++)
        cin >> p[i];
    cin >> r;
    ll left = 1, right = (ll) 1e12 + 100, res = 0;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        if (Check (mid, r)) {
            res = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << res;
    return 0;
}

