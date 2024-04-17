#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "EXP"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a,b,res;
map<int,int> cnt;
vector<int> v;

ll dem(ll x, ll y)
{
    ll res = 0, cur = y;
    while(cur <= x)
    {
        res += x/cur;
        cur *= y;
    }
    return res;
}

ll phantich()
{
    ll res = INFLL;
    for(ll i = 2; i * i <= b; i++)
    {
        if(b % i == 0)
        {
            if(cnt[i] == 0) v.push_back(i);
            while(b % i == 0)
            {
                b /= i;
                cnt[i]++;
            }
        }
    }
    if(b != 1)
    {
        if(cnt[b] == 0) v.push_back(b);
        cnt[b]++;
    }
    for(int i = v.size()-1; i >= 0; i--)
    {
        res = min(res,dem(a,v[i])/cnt[v[i]]);
        cnt.erase(v[i]);
        v.pop_back();
    }
    return res;
}

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        res = phantich();
        cout << res << '\n';
    }
}

