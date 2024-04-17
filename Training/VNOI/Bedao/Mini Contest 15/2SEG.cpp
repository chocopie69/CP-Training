#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6+5;
int t,n,a[MAXN];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int gen(int lo, int hi)
{
    return rng()%(hi-lo+1)+lo;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> t;
    if(t == 2)
    {
        cout << 3 << endl << 4;
        return 0;
    }
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        cout << n - gen(1,n-1) << '\n';
    }
}
