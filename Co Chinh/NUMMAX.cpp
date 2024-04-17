#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NUMMAX"

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

int n, lo[SZ], hi[SZ];
ll b,a[SZ], res = 0;
stack<int> st;

int main()
{
    init();
    cin >> n >> b;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        while(!st.empty() && a[st.top()] < a[i])
        {
            st.pop();
        }
        lo[i] = (st.empty() ? 0 : st.top());
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(int i = n; i >= 1; i--)
    {
        while(!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }
        hi[i] = (st.empty() ? n+1 : st.top());
        st.push(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == b)
        {
            res += (i-lo[i])*(hi[i]-i);
        }
    }
    cout << res;
}
