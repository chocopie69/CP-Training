#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fi first
#define se second
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) x * y / __gcd(x, y)

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mxN = 1e2 + 5;
const int block = 450;
const int base = 31;
const int LOG = 19;

int n, m, q;
int a[mxN][mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int sz = s.size();
        s = " " + s;
        stack<int> st, v;
        int i = 1;
        while (i <= sz) {
            if (s[i] == 'S' && s[i + 1] == 'U' && s[i + 2] == 'M') {
                st.push(1);
                i += 3;
            }
            else if (s[i] == 'M' && s[i + 1] == 'A' && s[i + 2] == 'X') {
                st.push(2);
                i += 3;
            }
            else if ('A' <= s[i] && s[i] <= 'Z' && '1' <= s[i + 1] && s[i + 1] <= '9') {
                v.push(a[s[i + 1] - '0'][s[i] - 'A' + 1]);
                i += 2;
            }
            else if (s[i] == ')') {
                if (st.top() == 1) {
                    st.pop();
                    int x = v.top();
                    v.pop();
                    int y = v.top();
                    v.pop();
                    v.push(x + y);
                }
                else {
                    st.pop();
                    int x = v.top();
                    v.pop();
                    int y = v.top();
                    v.pop();
                    v.push(max(x, y));
                }
                i++;
            }
            else {
                i++;
            }
        }
        cout << v.top() << '\n';
    }
}
/*
*/

