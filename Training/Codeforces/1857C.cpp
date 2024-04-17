#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n,a[SZ],res[SZ];

int sum(int x)
{
    return x*(x-1)/2;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= sum(n); i++)
        {
            cin >> a[i];
        }
        sort(a+1,a+sum(n)+1);
        int pos = 0;
        for(int i = 1; i < n; i++)
        {
            pos += (n-i);
            cout << a[pos] << " ";
        }
        cout << int(1e9) << '\n';
    }
}
