#include <bits/stdc++.h>
#define N int(1e6)+5
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int,int>
#define mll map<ll,ll>
#define dei deque<int>
#define dell deque<ll>
#define dch deque<char>
#define el '\n'
#define fi first
#define se second
#define hieeus_coding signed main
const int MOD = 1e9+7;
using namespace std;
int t,n;
int a[N];
void solve()
{
    int res = 0;
    int sum = 0;
    for (int i=1;i<=n-2;i++)
    {
        int j = i;
        for (int v = 2;v<=n/2+1;v++)
        {
            sum = 0;
            int dem = 0;
            int j = i;
            while (j<=n)
            {
                sum+=a[j];
                j+=v;
                dem++;
                if (dem == n/2) res = max(res,sum);
            }
        }
    }
    cout << res << el;
}
hieeus_coding()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("bai2.inp","r",stdin);
    //freopen("bai2.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        solve();
    }
    return 0;
}

/*
1
5
-1 2 5 1 -2
*/
