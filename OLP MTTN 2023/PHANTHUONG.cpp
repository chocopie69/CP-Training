#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    //freopen("input.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Prize
{
    ll w,v,c;
};

ll n,s, sumW = 0, sumV = 0, res, x, d;
Prize a[LIMIT];
vector<int> v1, v2;

int main()
{
    init();
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        ll w,v,c;
        cin >> w >> v >> c;
        a[i].w = w;
        a[i].v = v;
        a[i].c = c;
        if(c == 1)
        {
            v1.push_back(i);
            sumW += w;
            sumV += v;
        }
        else
        {
            v2.push_back(i);
        }
    }
    res = sumV;
    for(int i = 0; i < v1.size();i++)
    {
        for(int j = 0; j < v2.size();j++)
        {
            Prize prize1 = a[v1[i]], prize2 = a[v2[j]];
            if(sumW - prize1.w + prize2.w <= s)
            {
                if(sumV-prize1.v+prize2.v > res)
                {
                    x = prize1.v;
                    d = prize2.v;
                    res = sumV-prize1.v+prize2.v;
                }
            }
            //cout << v1[i] << " " << v2[j] << " ";
        }
        //cout << '\n';
    }
    cout << res << " " << sumW;
    //cout << x << " " << d;
}
