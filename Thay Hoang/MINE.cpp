#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MINE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n;

ll sumG[SZ], sumR[SZ], x[SZ], g[SZ], r[SZ], a[SZ], b[SZ], res, maxF[SZ];
stack<int> st;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        res = 0;
        cin >> n;
        g[0] = 0;
        r[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i] >> g[i] >> r[i];
            g[i] += g[i-1];
            r[i] += r[i-1];
            a[i] = r[i] - x[i];
            b[i] = r[i-1] - x[i];
        }
        for(int i = 1; i <= n; i++)
        {
            if(st.empty() || b[i] < b[st.top()] ) st.push(i);
        }
        int j = n;
        while(!st.empty())
        {
            int i = st.top();
            st.pop();
            while(a[j] < b[i]) --j;
            res = max(res,g[j] - g[i-1]);
        }
        cout << res << '\n';
    }
}

/*
3
4
0 5 1
1 7 2
4 4 1
7 15 1
4
0 5 1
1 7 2
4 4 1
7 15 1
4
0 5 1
1 7 2
4 4 1
7 15 1
*/
