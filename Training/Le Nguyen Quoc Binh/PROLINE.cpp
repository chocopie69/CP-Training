#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PROLINE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ], res = 0, cnt[SZ];
vector<int> v;
bool exist[SZ];

namespace sub12
{
    void solve()
    {
        for(int mask = 0; mask < (1 << n); mask++)
        {
            while(!v.empty()) v.pop_back();
            for(int i = 0; i < n; i++)
            {
                if(mask >> i & 1)
                {
                    v.push_back(a[i+1]);
                }
            }
            if(v.size() < 3) continue;
            bool check = true;
            for(int i = 1; i < v.size()-1; i++)
            {
                if(v[i] - v[i-1] != v[i+1] - v[i] || v[i] - v[i-1] <= 0) check = false;
            }
            res += int(check);
//            if(check)
//            {
//                for(int i = 0; i < n; i++)
//                {
//                    if(mask >> i & 1)
//                    {
//                        cout << i+1 << " ";
//                    }
//                }
//                cout << '\n';
//            }
        }
        cout << res;
    }
}

namespace sub3
{
    void solve()
    {
        memset(exist,false,sizeof(exist));
        for(int j = 3; j <= n; j++)
        {
            for(int i = 2; i < j; i++)
            {
                if(a[i] < a[j])
                {
                    int d = a[j] - a[i];
                    cnt[a[i]]++;
                    v.push_back(a[i]);
                    exist[a[i]] = true;
                    for(int k = i-1; k >= 1; k--)
                    {
                        if(a[k] < a[i] && (a[i] - a[k]) % d == 0)
                        {
                            res = (res + cnt[a[k] + d]) % MOD;
                            cnt[a[k]]++;
                            if(!exist[a[k]])
                            {
                                v.push_back(a[k]);
                                exist[a[k]] = true;
                            }
                            //cout << k << " " << j << " " << d << '\n';
                        }
                    }
                    while(!v.empty())
                    {
                        cnt[v.back()] = 0;
                        exist[v.back()] = false;
                        v.pop_back();
                    }
                }
            }
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n <= 20)
    {
        sub12::solve();
    } else if(n <= 500)
    {
        sub3::solve();
    } else
    {
        sub3::solve();
    }
}

/*
6
3 9 1 5 7 5

8
3 1 3 5 7 9 7 6
*/
