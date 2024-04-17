#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, adj[26][26];
vector<int> id[26][26], cyc;
string s, a[SZ];

void dfs(int u)
{
    for(int v = 0; v < 26; v++)
    {
        if(adj[u][v] > 0)
        {
            adj[u][v]--;
            dfs(v);
        }
    }
    cyc.push_back(u);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        a[i] = s;
        char c = s[0], x = s[s.size()-1];
        adj[int(c) - 'a'][int(x) - 'a']++;
        id[int(c) - 'a'][int(x) - 'a'].push_back(i);
    }
    dfs(int(a[1][0]) - 'a');
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(adj[i][j] > 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    for(int i = cyc.size()-1; i > 0; i--)
    {
        int u = cyc[i], v = cyc[i-1];
        cout << id[u][v].back() << " ";
        id[u][v].pop_back();
    }
}
