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

const int SZ = 3e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q;

struct FenwickTree
{
    ll sum[SZ];

    void update(int pos)
    {
        while(pos < SZ)
        {
            sum[pos]++;
            pos += pos & (-pos);
        }
    }

    ll query(int pos)
    {
        ll res = 0;
        while(pos > 0)
        {
            res += sum[pos];
            pos -= pos & (-pos);
        }
        return res;
    }
} ft;

vector<pll> vec[4];

ll a[SZ], b[SZ], c[SZ], w[4] = {0, 1LL, 2LL, 5LL}, sum[4][SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != 0)
        {
            vec[1].push_back({1, 1});
            vec[1].push_back({a[i] + 1, -1});
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if(b[i] != 0)
        {
            vec[2].push_back({a[i] + 1, 1});
            vec[2].push_back({a[i] + 1 + b[i], -1});
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if(c[i] != 0)
        {
            vec[3].push_back({a[i] + b[i] + 1, 1});
            vec[3].push_back({a[i] + b[i] + c[i] + 1, -1});
        }
    }
    for(int i = 1; i <= 3; i++)
    {
        sort(all(vec[i]));
        sum[i][0] = vec[i][0].se;
        for(int j = 1; j < vec[i].size(); j++)
        {
            sum[i][j] = sum[i][j-1] + vec[i][j].se;
        }
        //cout << i << '\n' << vec[i][0].fi << " " << vec[i][0].se << '\n';
        //for(int j = 1; j < vec[i].size(); j++) cout << vec[i][j].fi << " " << vec[i][j].se << '\n';
    }
    cin >> q;
    while(q--)
    {
        int pos;
        cin >> pos;
        int rpos = pos + ft.query(pos);
        ft.update(pos);
        ll res = 0;
        //cout << rpos << ' ';
        for(int i = 1; i <= 3; i++)
        {
            if(rpos >= vec[i][vec[i].size()-1].fi ) continue;
            int lo = 0, hi = vec[i].size()-1, mid;
            while(lo <= hi)
            {
                mid = (lo + hi) / 2;
                if(vec[i][mid].fi > rpos)
                {
                    hi = mid-1;
                } else
                {
                    lo = mid+1;
                }
            }
            if(lo <= 0) continue;
            res += w[i]*sum[i][lo-1];
            //cout << i << " " << lo << ' ' << w[i] << " " << sum[i][lo-1] << " " << vec[i][lo-1].fi << '\n'; ;
        }
        cout << res << '\n';
    }
}

/*
6
2 1 2 0 3 1
1 2 2 2 2 0
1 0 1 2 0 3
4
1 3 1 2
*/


