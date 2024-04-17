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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

bool check[SZ][SZ];
int n, m, w, k, s, a[SZ], trace[SZ][SZ];
vector<int> adj[SZ];
bool dp[SZ][SZ];
stack<int> st;

int main()
{
    init();
    cin >> n >> m >> k >> w >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        check[u][v] = true;
        check[v][u] = true;
    }
    memset(trace, -1, sizeof(trace));
    memset(dp, false, sizeof(dp));
    dp[k][a[k]] = true;
    for(int j = a[k]; j <= s; j++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(int v : adj[u])
            {
                if(j - a[u] >= 0 && dp[v][j - a[u]] == true)
                {
                    dp[u][j] = true;
                    trace[u][j] = v;
                    break;
                }
            }
        }
    }
    int u = w, j = s;
    while(true)
    {
        st.push(u);
        int d = a[u];
        u = trace[u][j];
        j -= d;
        if(u == -1) break;
    }
    int sum = 0, prev = -1;
    bool flag = false;
    while(!st.empty())
    {
        cout << st.top() << " ";
        sum += a[st.top()];
        if(prev != -1 && check[prev][st.top()] == false && check[st.top()][prev] == false) flag = true;
        prev = st.top();
        st.pop();
    }
    //cout << '\n' << ( (sum == s && !flag) ? "YES" : "NO");
}

/*
10 38 10 6 1000
5 10 10 7 4 3 5 10 8 6
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
2 3
2 4
2 5
2 7
2 8
2 9
2 10
3 4
3 5
3 7
3 8
3 9
3 10
4 5
4 7
4 8
4 9
4 10
5 7
5 9
5 10
6 7
6 10
7 8
7 9
7 10
8 9
8 10
9 10
*/
