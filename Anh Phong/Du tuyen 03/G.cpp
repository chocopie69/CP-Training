#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,k, b[SZ], st[19][SZ];
pii a[SZ], c[SZ];

void rmqC()
{
    for(int i = 1; i <= k; i++)
    {
        st[0][i] = c[i].se;
    }
    for(int j = 1; j <= 18; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= k; i++)
        {
            st[j][i] = max(st[j-1][i], st[j-1][i + (1 << (j-1)) ]);
        }
    }
}

int getMax(int lo, int hi)
{
    if(lo > hi) return 0;
    int k = __lg(hi - lo + 1);
    return max(st[k][lo], st[k][hi - (1 << k) + 1 ]);
}

struct Card
{
    int x,y, pos;
    Card(int _x = 0, int _y = 0, int _pos = 0) : x(_x), y(_y), pos(_pos) {}

    bool operator < (const Card& other) const
    {
        return pos > other.pos;
    }
} cards[SZ];

int lwb(int x)
{
    int lo = 1, hi = k, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(c[mid].fi >= x)
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    return lo;
}

vector<int> cprs;
ll res = 0;

struct FenwickTree
{
    int nodes[SZ];
    void update(int pos)
    {
        while(pos > 0)
        {
            nodes[pos]++;
            pos -= pos & (-pos);
        }
    }

    int query(int pos)
    {
        int sum = 0;
        while(pos <= k)
        {
            sum += nodes[pos];
            pos += pos & (-pos);
        }
        return sum;
    }
} ft;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> b[i];
        cprs.push_back(b[i]);
        c[i] = {b[i],i};
    }
    sort(c + 1, c + k + 1);
    rmqC();
    for(int i = 1; i <= n; i++)
    {
        int pos1 = lwb(min(a[i].fi,a[i].se)) , pos2 = lwb(max(a[i].fi,a[i].se)) - 1;
        cards[i] = {a[i].fi, a[i].se, getMax(pos1, pos2) };
        //cout << pos1 << " " << pos2 << " " <<getMax(pos1, pos2) << '\n';
    }
    sort(cards + 1, cards + n + 1);
    sort(all(cprs));
    for(int i = 1; i <= k; i++)
    {
        b[i] = lower_bound(all(cprs), b[i]) - cprs.begin() + 1;
    }
    b[0] = 0;
    int j = k;
    for(int i = 1; i <= n; i++)
    {
        int x = cards[i].x, y = cards[i].y, pos = cards[i].pos;
        if(pos != 0 && x < y) swap(x,y);
        //cout << x << " " << y << " " << pos << '\n';
        while(j > pos)
        {
            ft.update(b[j]);
            //cout << "updated " << j << '\n';
            j--;
        }
        //cout << '\n';
        if(pos != 0)
        {
            int cur = ft.query(b[pos]+1);
            if(cur % 2 == 1) res += 1LL*y;
            else res += 1LL*x;
        }
        else
        {
            int mx = max(x,y);
            int p = lower_bound(all(cprs), mx) - cprs.begin() + 1;
            int cur = ft.query(p);
            if(cur % 2 == 1) res += 1LL*y;
            else res += 1LL*x;
        }
    }
    cout << res;
}

/*
5 3
4 6
9 1
8 8
4 2
3 7
8
2
9
*/

