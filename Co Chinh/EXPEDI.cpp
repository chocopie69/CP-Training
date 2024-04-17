#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "EXPEDI"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, cnt = 0, l, p;
pii a[SZ];

priority_queue<int> pq;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    cin >> l >> p;
    a[0] = {0,0};
    for(int i = n; i >= 0; i--)
    {
        p -= (l - a[i].fi);
        while(!pq.empty() && p < 0)
        {
            cnt++;
            p += pq.top();
            pq.pop();
        }
        if(p < 0)
        {
            cnt = -1;
            break;
        }
        pq.push(a[i].se);
        l = a[i].fi;
    }
    cout << cnt;
}
