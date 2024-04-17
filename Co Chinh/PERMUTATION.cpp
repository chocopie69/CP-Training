#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PERMUTATION"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, t[SZ], a[SZ];
vector<int> v;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0, j = 1;
        while(cnt < t[i])
        {
            if(a[j] == 0) cnt++;
            j++;
        }
        while(a[j] != 0) j++;
        a[j] = i;
        //cout << i << " " << j << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
