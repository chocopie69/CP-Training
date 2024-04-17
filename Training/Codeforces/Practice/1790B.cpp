#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define endl '\n'
using namespace std;

const int INF = INT_MAX, LIMIT = 55;
const ll INFLL = 2e18;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,s,r,t,a[LIMIT];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> s >> r;
        int maxValue = s-r;
        for(int i = 1; i <= n; i++)
        {
            a[i] = maxValue;
        }
        int sumLeft = maxValue*n-s;
        for(int i = 1; i <= n; i++)
        {
            a[i] -= min(maxValue-1,sumLeft);
            sumLeft -= (maxValue - a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
