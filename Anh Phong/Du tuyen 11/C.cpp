#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m;
string s[SZ], t[SZ];

struct Node
{
    int a[26], cnt[2];
    Node()
    {
        memset(a, -1, sizeof(a));
        cnt[0] = cnt[1] = 0;
    }
};
vector<Node> nodes(1);

void add1(int id, int pos, int cur)
{
    nodes[id].cnt[0]++;
    if(pos == s[cur].length()) return;
    if(nodes[id].a[s[cur][pos] - 'a'] == -1)
    {
        nodes[id].a[s[cur][pos] - 'a'] = nodes.size();
        nodes.pb(Node());
    }
    add1(nodes[id].a[s[cur][pos] - 'a'], pos+1, cur);
}

void add2(int id, int pos, int cur)
{
    nodes[id].cnt[1]++;
    if(pos == t[cur].length()) return;
    if(nodes[id].a[t[cur][pos] - 'a'] == -1 )
    {
        nodes[id].a[t[cur][pos] - 'a'] = nodes.size();
        nodes.pb(Node());
    }
    add2(nodes[id].a[t[cur][pos] - 'a'], pos+1, cur);
}

bool dp[SZ];

void dfs(int u, int d)
{
    if (!nodes[u].cnt[d]){
        dp[u] = false;
        return;
    }
    if(nodes[u].cnt[d] && !nodes[u].cnt[d ^ 1])
    {
        dp[u] = true;
        return;
    }
    for(int i = 0; i < 26; i++)
    {
        if(nodes[u].a[i] != -1)
        {
            dfs(nodes[u].a[i], d ^ 1);
            dp[u] |= (dp[nodes[u].a[i]] ^ 1);
        }
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        add1(0, 0, i);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> t[i];
        add2(0, 0, i);
    }
    dfs(0, 0);
    cout << (dp[0] ? "Nina" : "Emilija");
}

