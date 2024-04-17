#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "JUDGER"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


ll n,m, points[SZ];
multiset<ll> ms1;
multiset<ll,greater<ll>> ms2;

int main()
{
    init();
    cin >> n >> m;
    memset(points,0,sizeof(points));
    for(int i = 1; i <= n; i++)
    {
        ms1.insert(i);
        ms2.insert(0);
    }
    ll type, i, x;
    while(m--)
    {
        cin >> type;
        if(type != 4)
        {
            cin >> i;
            if(i < 1 || i > n) continue;
            if(type == 3) cin >> x;
        }
        if(type == 1)
        {
            if(ms1.find(i) == ms1.end())
            {
                ms1.insert(i);
                ms2.insert(0);
                points[i] = 0;
            }
        }
        else if(type == 2)
        {
            if(ms1.find(i) != ms1.end())
            {
                auto it = ms2.find(points[i]);
                ms2.erase(it);
                ms1.erase(i);
            }
        }
        else if(type == 3)
        {
            if(ms1.find(i) != ms1.end())
            {
                //cout << (ms2.find(points[i]) == ms2.end()) << ' ' << i << '\n';
                auto it = ms2.find(points[i]);
                ll val = *it;
                ms2.insert(val+x);
                ms2.erase(it);
                points[i] += x;
                //cout << points[i] << " a" << '\n';
            }
        }
        else
        {
            if(ms1.empty())
            {
                cout << "EMPTY" << '\n';
            }
            else
            {
                auto it = ms2.begin();
                int cnt = 0;
                while(cnt < 3 && it != ms2.end())
                {
                    cout << *it << ' ';
                    it++;
                    cnt++;
                }
                cout << '\n';
            }
        }
    }
}

