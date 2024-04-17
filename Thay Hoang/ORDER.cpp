#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ORDER"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m, visit[SZ];
string s;

vector<int> adj[SZ];

stack<int> st;

void dfs(int u)
{
    visit[u] = 1;
    for(int v : adj[u])
    {
        if(visit[v] == 1)
        {
            cout << "NO";
            exit(0);
        }
        if(!visit[v]) dfs(v);
    }
    visit[u] = 2;
    st.push(u);
}

vector<pii> v;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> s;
        s += ' ';
        int cur = 0;
        int u = -1;
        bool dir = false;
        for(char c : s)
        {
            if(c != '<' && c != '>' && c != ' ')
            {
                cur = cur * 10 + int(c) - 48;
            } else
            {
                if(c == ' ')
                {
                    if(dir) swap(u,cur);
                    adj[u].push_back(cur);
                    //cout << u << " " << cur << '\n';
                }
                else
                {
                    if(c == '>') dir = true;
                    u = cur;
                    cur = 0;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visit[i]) dfs(i);
    }
    cout << "YES" << '\n';
    int i = 0;
    while(!st.empty())
    {
        i++;
        v.push_back({st.top(), i });
        //cout << st.top() << " ";
        st.pop();
    }
    sort(all(v));
    for(pii p : v)
    {
        cout << p.se << " ";
    }
}
