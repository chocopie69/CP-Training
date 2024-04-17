#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SMPER"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n,x[LIMIT], flag[LIMIT];

struct Pair
{
    int a,b;
};

Pair pairs[LIMIT];
vector<int> choosed;
multiset<int> ms;

int main()
{
    init();
    cin >> t;
    memset(flag,false,sizeof(flag));
    for(ll i = 1; i <= 2e5+1;i++)
    {
        ms.insert(i);
    }
    while(t--)
    {
        bool found = true;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> x[i];
            if(ms.count(x[i]) == 0)
            {
                cout << -1 << '\n';
                found = false;
                break;
            }
            Pair cur;
            cur.a = 0;
            cur.b = x[i];
            pairs[i] = cur;
            choosed.push_back(x[i]);
            ms.erase(x[i]);
        }
        if(found)
        {
            for(int i = n; i >= 1; i--)
            {
                if(*ms.begin() > pairs[i].b)
                {
                    cout << -1 << '\n';
                    found = false;
                    break;
                }
                else
                {
                    auto it = ms.lower_bound(x[i]);
                    it--;
                    pairs[i].a = *it;
                    ms.erase(it);
                    choosed.push_back(*it);
                }
            }
        }
        while(!choosed.empty())
        {
            ms.insert(choosed.back());
            choosed.pop_back();
        }
        if(!found)
        {
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            cout << pairs[i].a << " " << pairs[i].b << " ";
        }
        cout << '\n';
    }
}

/*
6
3
4 3 6
2
2 4
4
8 7 2 3
3
6 4 2
2
4 4
4
8 7 4 5
*/

