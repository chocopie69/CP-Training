#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pli pair<long long, int>
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

ll n,l,r,a[SZ];
bool valid[SZ], valid2[SZ];

namespace sub2
{
    vector<pli> v1, v2;
    void solve()
    {
        for(int mask = 0; mask < (1 << (n/2) ); mask++ )
        {
            ll sum = 0;
            for(int i = 1; i <= n/2; i++)
            {
                if(mask >> (i-1) & 1)
                {
                    sum += a[i];
                }
            }
            v1.push_back({sum,mask});
        }
        for(int mask = 0; mask < (1 << ( n - (n/2) ) ); mask++ )
        {
            ll sum = 0;
            for(int i = n/2 + 1; i <= n; i++)
            {
                if(mask >> (i - n/2 - 1) & 1)
                {
                    sum += a[i];
                }
            }
            v2.push_back({sum,mask});
        }
        sort(all(v1));
        sort(all(v2));
//        for(pii p : v1) cout << p.fi << " ";
//        cout << '\n';
//        for(pii p : v2) cout << p.fi << " ";
//        int j = 0;
        for(pli p : v1)
        {
            ll x = p.fi;
            if(x + v2[0].fi > r || x + v2[v2.size()-1].fi < l) continue;
            int mask = p.se, mask2;
            //while(j < v2.size() - 1 && x + v2[j].fi < l) j++;
            int lo = 0, hi = v2.size()-1, mid;
            while(lo <= hi)
            {
                mid = (lo + hi) / 2;
                if(v2[mid].fi >= l - x)
                {
                    hi = mid-1;
                } else
                {
                    lo = mid+1;
                }
            }
            int j = lo;
            //cout << x << " " << v2[j].fi << " " << l << " " << r << '\n';
            if(x + v2[j].fi >= l && x + v2[j].fi <= r)
            {
                mask2 = v2[j].se;
                cout << __builtin_popcount(mask) + __builtin_popcount(mask2) << '\n';
                for(int i = 1; i <= n/2; i++)
                {
                    if(mask >> (i-1) & 1)
                    {
                        cout << i << " ";
                    }
                }
                for(int i = n/2 + 1; i <= n; i++)
                {
                    if(mask2 >> (i - n/2 - 1) & 1)
                    {
                        cout << i << " ";
                    }
                }
                exit(0);
            }
        }
        cout << -1;
    }
}

namespace sub3
{
    stack<int> res;
    int f[SZ];
    void solve()
    {
        f[0] = 0;
        for(int x = 1; x <= r; x++)
        {
            f[x] = INF;
            for(int i = 1; i <= n; i++)
            {
                if(a[i] <= x && f[x-a[i]] < i)
                {
                    f[x] = i;
                    break;
                }
            }
        }
        bool flag = false;
        for(int x = l; x = r; x++)
        {
            if(f[x] == INF) continue;
            flag = true;
            int cur = x;
            while(cur > 0)
            {
                res.push(f[cur]);
                cur -= a[f[cur]];
                //cout << f[cur] << '\n';
            }
            break;
        }
        if(!flag)
        {
            cout << -1;
            exit(0);
        }
        cout << res.size() << '\n';
        while(!res.empty())
        {
            cout << res.top() << " ";
            res.pop();
        }
    }
}

namespace sub5
{
    stack<int> res;
    void solve()
    {
        ll sum = 0;
        for(int i = n; i >= 1; i--)
        {
            if(sum + a[i] <= r)
            {
                res.push(i);
                sum += a[i];
            }
        }
        if(sum < l)
        {
            cout << -1;
            exit(0);
        }
        cout << res.size() << '\n';
        while(!res.empty())
        {
            cout << res.top() << " ";
            res.pop();
        }
    }
}

namespace sub6
{
    pll b[SZ];
    set<int> res;
    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            b[i] = {a[i],i};
        }
        sort(b+1,b+n+1);
        memset(valid,true,sizeof(valid));
        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += b[i].fi;
            if(sum > r)
            {
                for(int j = i; j <= n; j++)
                {
                    valid[j] = false;
                }
                break;
            }
        }
        memset(valid2,false,sizeof(valid2));
        sum = 0;
        for(int i = n; i >= 1; i--)
        {
            sum += b[i].fi;
            if(sum >= l)
            {
                for(int j = i; j >= 1; j--)
                {
                    valid2[j] = true;
                }
                break;
            }
        }
        for(int k = 1; k <= n; k++)
        {
            if(!valid[k] || !valid2[n-k+1]) continue;
            sum = 0;
            for(int i = 1; i <= n; i++)
            {
                sum += b[i].fi;
                if(i > k) sum -= b[i-k].fi;
                if(i >= k && sum >= l && sum <= r)
                {
                    cout << k << '\n';
                    for(int j = i-k+1; j <= i; j++)
                    {
                        res.insert(b[j].se);
                    }
                    while(!res.empty())
                    {
                        cout << *res.begin() << " ";
                        res.erase(res.begin());
                    }
                    exit(0);
                }
            }
        }
        cout << -1;
    }
}

int main()
{
    init();
    cin >> n >> l >> r;
    bool isSub5 = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != i) isSub5 = false;
    }
    if(n <= 40)
    {
        sub2::solve();
    } else if(n <= 80)
    {
        sub3::solve();
    } else if(isSub5)
    {
        sub5::solve();
    } else
    {
        sub6::solve();
    }
}
