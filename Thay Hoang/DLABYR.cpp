#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DLABYR"

using namespace std;

const int LIMIT = 300+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,k;
vector<int> adj[LIMIT];
bool unlocked[LIMIT], b[LIMIT][LIMIT], a[LIMIT][LIMIT];

struct Message
{
    char type;
    int u,s,t;
};

int main()
{
    init();
    cin >> n >> m >> k;
    memset(unlocked,false,sizeof(unlocked));
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        a[u][v] = true;
    }
    Message msg;
    while(k--)
    {
        cin >> msg.type;
        if(msg.type == 'X')
        {
            cin >> msg.u;
            unlocked[msg.u] = true;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n;j++)
                {
                    if(!unlocked[i] || !unlocked[j]) continue;
                    b[i][j] !
                }
            }
            /*for(int k = 1; k <= n; k++)
            {
                for(int i = 1; i <= n; i++)
                {
                    if(!unlocked[i] || !unlocked[k]) continue;
                    b[i][msg.u] = (b[i][msg.u] || (b[i][k] && b[k][msg.u]));
                    b[msg.u][i] = (b[msg.u][i] || (b[msg.u][k] && b[k][i]));
                }
            }*/
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= n;j++)
                {
                    if(!unlocked[i] || !unlocked[j]) continue;
                    b[i][j] |= (b[i][msg.u] && b[msg.u][j]);
                }
            }
        }
        else
        {
            cin >> msg.s >> msg.t;
            cout << (b[msg.s][msg.t] ? 'Y' : 'N');
        }
    }
}


