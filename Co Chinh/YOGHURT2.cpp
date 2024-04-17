#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "YOGHURT2"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;
ll a[SZ], b[SZ], s = 0, cnt = 0;

bool choose[SZ];

struct cmp
{
    bool operator () (int x, int y)
    {
        return b[x] < b[y];
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        s += a[i];
        if(s >= b[i])
        {
            s -= b[i];
            cnt++;
            choose[i] = true;
        } else if(!pq.empty() && pq.top() - b[i] >= 0)
        {
            choose[pq.top()] = false;
            choose[i] = true;
            s += (pq.top() - b[i]);
        }
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(choose[i]) cout << i << " ";
    }
}
