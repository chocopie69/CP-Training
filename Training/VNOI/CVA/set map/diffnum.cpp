#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 2e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,x;
set<int> s;

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}
