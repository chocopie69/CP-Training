#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SUBSET"

using namespace std;

const int LIMIT = 2e6+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n,l,r,a[LIMIT];
vector<ll> sumA, sumB, res;
vector<string> binaryA, binaryB;

namespace sub1and2
{
    void recurA(int i,string s)
    {
        if(i > n/2)
            return;
        if(i == n / 2)
        {
            binaryA.push_back(s);
            //cout << s << " ";
            ll cur = 0;
            for(int i = 0; i < s.size();i++)
            {
                cur += a[i+1] * (int(s[i]) - 48);
            }
            sumA.push_back(cur);
            //cout << cur << " A" << '\n';
        }
        recurA(i+1,s + "0");
        recurA(i+1,s + "1");
    }

    void recurB(int i,string s)
    {
        if(i > n)
            return;
        if(i == n)
        {
            binaryB.push_back(s);
            //cout << s << " ";
            ll cur = 0;
            for(int i = 0; i < s.size();i++)
            {
                cur += a[i+n/2+1] * (int(s[i]) - 48);
            }
            sumB.push_back(cur);
            //cout << cur << " B" << '\n';
        }
        recurB(i+1,s + "0");
        recurB(i+1,s + "1");
    }
    ll calc(string s)
    {
        ll cur = 0;
        for(int i = 0; i < s.size();i++)
        {
            cur += a[i+n/2+1] * (int(s[i]) - 48);
        }
        return cur;
    }

    bool cmp(string x, string y)
    {
        return calc(x) < calc(y);
    }

    void solve()
    {
        recurA(1,"0");
        recurA(1,"1");
        recurB(n/2 + 1, "0");
        recurB(n/2 + 1, "1");
        sort(sumB.begin(),sumB.end());
        sort(binaryB.begin(),binaryB.end(),cmp);
        for(int i = 0; i < sumA.size();i++)
        {
            ll pos = lower_bound(sumB.begin(),sumB.end(),l - sumA[i]) - sumB.begin();
            if(sumA[i] + sumB[pos] <= r)
            {
                //cout << sumA[i] << " " << sumB[pos] << '\n';
                for(int j = 0; j < binaryA[i].size(); j++)
                {
                    if(binaryA[i][j] == '1')
                        res.push_back(j + 1);
                }
                for(int j = 0; j < binaryB[pos].size(); j++)
                {
                    if(binaryB[pos][j] == '1')
                        res.push_back(j + n/2 + 1);
                }
                break;
            }
        }
        cout << res.size() << '\n';
        for(ll i : res)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    init();
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n <= 40)
        sub1and2::solve();
}

