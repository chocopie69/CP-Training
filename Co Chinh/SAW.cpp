#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll, ll>

#define TASKNAME "SAW"
using namespace std;

const int maxN = 1e6+5;
ll n,m,a[maxN],s[maxN],x;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool check(ll mid)
{
    int pos = upper_bound(a+1,a+n+1,mid) - a;
    ll tong = s[n] - s[pos-1] - mid*(n-pos+1);
    if(tong >= x) return true;
    return false;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    s[1] = a[1];
    for(int i=2;i<=n;i++) s[i] = s[i-1] + a[i];
    while(m--)
    {
        cin >> x;
        ll l = 1, r = 2*1e6;
        while(l <= r) {
            ll mid = (l+r)/2;
            if(check(mid)) {
                l = mid+1;
            } else r = mid-1;
        }
        cout << r << ' ';
    }
}

