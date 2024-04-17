#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "RESEARCH"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin);
    freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,u,v,deg[SZ], cur = 1, cnt = 0, res = 0, lab[SZ];
char c;
vector<int> adj[SZ];
queue<int> quA, quB;
bool unlocked[SZ];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> c;
        lab[i] = char(c) - 'A';
    }
    memset(deg,0,sizeof(deg));
    memset(unlocked,false,sizeof(unlocked));
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] != 0) continue;
        if(lab[i] == 0 || lab[i] == 2)
            quA.push(i);
        else quB.push(i);
    }
    while(cnt < n)
    {
        if(quA.empty() && quB.empty())
        {
            cout << -1;
            return 0;
        }
        if(cur == 1)
        {
            while(!quA.empty())
            {
                u = quA.front();
                //cout << u << " quA" << '\n';
                quA.pop();
                cnt++;
                for(int v : adj[u])
                {
                    if(!unlocked[v])
                    {
                        deg[v]--;
                        if(deg[v] == 0)
                        {
                            if(lab[v] == 0 || lab[v] == 2)
                            {
                                quA.push(v);
                            } else
                            {
                                quB.push(v);
                            }
                            unlocked[v] = true;
                        }
                    }
                }
            }
            cur = 2;
            if(cnt < n) res++;
        } else
        {
            while(!quB.empty())
            {
                u = quB.front();
                //cout << u << " quB" << '\n';
                quB.pop();
                cnt++;
                for(int v : adj[u])
                {
                    if(!unlocked[v])
                    {
                        deg[v]--;
                        if(deg[v] == 0)
                        {
                            if(lab[v] == 1 || lab[v] == 2)
                            {
                                quB.push(v);
                            } else
                            {
                                quA.push(v);
                            }
                            unlocked[v] = true;
                        }
                    }
                }
            }
            cur = 1;
            if(cnt < n) res++;
        }
    }
    cout << res;
}
