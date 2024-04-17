#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ANAGRAMS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,k;
string x[SZ], y[SZ], s;
vector<int> res;
bool vis[SZ], multiple = false;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> s;
        s = " " + s;
        x[i] = s;
        cin >> s;
        s = " " + s;
        y[i] = s;
    }
    for(int i = 1; i <= n; i++)
    {
        bool foundAns = false;
        for(int j = 1; j <= n; j++)
        {
            if(vis[j]) continue;
            bool check = true;
            for(int p = 1; p <= k; p++)
            {
                if(y[p][i] != x[p][j]) check = false;
            }
            if(check)
            {
                if(!foundAns)
                {
                    res.push_back(j);
                    vis[j] = true;
                } else
                {
                    multiple = true;
                }
                foundAns = true;
            }
        }
        if(!foundAns)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }
    if(multiple)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    for(int cur : res)
    {
        cout << cur << " ";
    }
}
