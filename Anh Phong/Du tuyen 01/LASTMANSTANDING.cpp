#include <bits/stdc++.h>
#define int long long
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int t, n, a[SZ], h[SZ], mx;

struct Node
{
    int mx1, pos, mx2;
    Node(int _mx1 = 0, int _pos = 0, int _mx2 = 0) : mx1(_mx1), pos(_pos), mx2(_mx2) {}
};

Node mer(Node x, Node y)
{
    if(x.pos == y.pos)
    {
        return {x.mx1, x.pos, max(x.mx2, y.mx2) };
    } else
    {
        if(x.mx1 < y.mx1) swap(x, y);
        return {x.mx1, x.pos, max(x.mx2,y.mx1)};
    }
}

Node rmq[21][SZ];

void buildRMQ(int lim)
{
    for(int j = 0; j <= 20; j++)
    {
        for(int i = 1; i <= lim; i++)
        {
            rmq[j][i] = {0,0,0};
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if(h[i] > rmq[0][a[i]].mx1)
        {
            rmq[0][a[i]].mx2 = rmq[0][a[i]].mx1;
            rmq[0][a[i]].mx1 = h[i];
            rmq[0][a[i]].pos = i;
        } else if(h[i] > rmq[0][a[i]].mx2)
        {
            rmq[0][a[i]].mx2 = h[i];
        }
    }
    for (int j = 1; j <= 20; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= lim; ++i)
        {
            rmq[j][i] = mer(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }
}

Node get(int lo, int hi)
{
    int k = __lg(hi - lo + 1);
    return mer(rmq[k][lo], rmq[k][hi - (1 << k) + 1]);
}

int res[SZ];

signed main()
{
    init();
    cin >> t;
    while(t--)
    {
        mx = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        buildRMQ(mx);
        memset(res, 0, sizeof(res));
        for(int x = 1; x <= mx; x++)
        {
            int pos = 0, curmx1 = 0, curmx2 = 0;
            for(int lo = 1; lo <= mx; lo += x)
            {
                int hi = min(mx, lo + x - 1);
                int c = (lo - 1) / x + 1;
                Node tmp = get(lo, hi);
                if(tmp.pos == 0) continue;
                if(tmp.mx1*c > curmx1)
                {
                    curmx2 = curmx1;
                    curmx1 = tmp.mx1*c;
                    pos = tmp.pos;
                } else if(tmp.mx1*c > curmx2)
                {
                    curmx2 = tmp.mx1*c;
                }
                curmx2 = max(curmx2, tmp.mx2*c);
            }
            if(pos == 0) continue;
            res[pos] = max(res[pos], curmx1 - curmx2);
            //cout << x << " " << pos << " " << curmx1 << " " << curmx2 << '\n';
        }
        for(int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
        cout << '\n';
    }
}

/*
1
3
3 1 2
3 11 5
*/
