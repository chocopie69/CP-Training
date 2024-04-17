#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "QUERYSUM"

using namespace std;

const int SZ = 4e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,sum[SZ], i,j, val;
int idx, u, v;
char c;

void update(int lo, int hi, int id)
{
    if(lo == hi)
    {
        sum[id] = val;
        return;
    }
    int mid = (lo + hi) / 2;
    if(idx <= mid)
    {
        update(lo,mid,2*id);
    } else
    {
        update(mid+1,hi,2*id+1);
    }
    sum[id] = sum[2*id] + sum[2*id+1];
}

ll getSum(int lo, int hi, int id)
{
    if(lo > v || hi < u)
    {
        return 0;
    }
    if(lo >= u && hi <= v)
    {
        return sum[id];
    }
    int mid = (lo + hi) / 2;
    return getSum(lo,mid,2*id) + getSum(mid+1,hi,2*id+1);
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> c >> i >> j;
        if(c == 'S')
        {
            idx = i;
            val = j;
            update(1,n,1);
        } else
        {
            u = i;
            v = j;
            cout << getSum(1,n,1) << '\n';
        }
    }
}
