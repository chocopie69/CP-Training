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

struct Data
{
    ll val, id;
    Data(ll _val = 0, ll _id = 0)
    {
        val = _val;
        id = _id;
    }
};

ll n,s,p[SZ], res = 0, p1, p2;

struct cmp
{
    bool operator () (Data x, Data y)
    {
        return x.val > y.val;
    }
};

priority_queue<Data,vector<Data>,cmp> a,b;

int main()
{
    init();
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        ll j,tj,p1 = 0, p2 = 0;
        if(!b.empty())
        {
            j = b.top().id;
            p1 = p[i] - p[j] - (i - j) * s; /// = ( p[i] - i * s) - (p[j] - j * s)
        }
        if(!a.empty())
        {
            tj = a.top().id;
            p2 = p[i] - p[tj] - (i - tj) * s; /// = ( p[i] - i * s) - (p[tj] - tj * s)
        }
        if(max(p1,p2) > 0)
        {
            if(p1 > p2)
            {
                res += p1;
                a.push({p[i] - i * s,i });
                b.pop();
            } else
            {
                res += p2;
                a.pop();
                a.push({ p[i] - i * s, i });
                b.push({ p[tj] - tj * s, tj });
            }
        } else
        {
            b.push({ p[i] - i * s, i });
        }
    }
    cout << res;
}
