#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DNUM"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a,b,cnt[LIMIT], res;
vector<int> v;

void phantich()
{
    for(ll i = 2; i * i <= a; i++)
    {
        if(a % i == 0)
        {
            v.push_back(i);
            while(a % i == 0)
            {
                a /= i;
                cnt[i]++;
            }
        }
    }
    if(a != 1) {
        v.push_back(a);
        cnt[a]++;
    }
    for(ll i = 2; i * i <= b; i++)
    {
        if(b % i == 0)
        {
            if(cnt[i] == 0) v.push_back(i);
            while(b % i == 0)
            {
                b /= i;
                cnt[i]--;
            }
        }
    }
    if(b != 1)
    {
        if(cnt[b] == 0) v.push_back(b);
        cnt[b]--;
    }
}

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        phantich();
        int res = 0;
        for(int i = v.size()-1; i >= 0; i--)
        {
            res += abs(cnt[v[i]]);
            cnt[v[i]] = 0;
            v.pop_back();
        }
        cout << res << '\n';
    }
}

