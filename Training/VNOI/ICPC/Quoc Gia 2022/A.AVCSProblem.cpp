#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

struct point
{
    int endPoint,snapshot;
    bool captured;
};

const int maxN = 1e6;
int n,q,s,u,v,curSnapshot=1;
vector<point> graph[maxN];
char type;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(graph,0,sizeof(graph));
}

void solve()
{
    if(type == 'A')
    {
        cin >> u >> v;
        graph[u].push_back({v,curSnapshot,false});
        graph[v].push_back({u,curSnapshot,false});
    }
    else if(type == '?')
    {
        cin >> u >> v;
        if(u == v) cout << 'Y';
        else
        {
            bool flag=false;
            for(point p: graph[u])
            {
                if(p.endPoint == v && p.snapshot <= curSnapshot)
                {
                    cout << 'Y';
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {
                for(point p: graph[v])
                {
                    if(p.endPoint == u && p.snapshot <= curSnapshot)
                    {
                        cout << 'Y';
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == false) cout << 'N';
        }
    }
    else if(type == 'C')
    {
        for(int i=0;i<maxN;i++) {
            for(point p: graph[i])
            {
                p.captured = true;
            }
        }
        curSnapshot++;
    }
    else
    {
        cin >> s >> u >> v;
        if(u == v) cout << 'Y';
        else
        {
            bool flag=false;
            for(point p: graph[u])
            {
                if(p.endPoint == v && p.snapshot <= s && p.captured)
                {
                    cout << 'Y';
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {
                for(point p: graph[v])
                {
                    if(p.endPoint == u && p.snapshot <= s && p.captured)
                    {
                        cout << 'Y';
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == false) cout << 'N';
        }
    }
}

int main()
{
    init();
    cin >> n >> q;
    while(q--)
    {
        cin >> type;
        solve();
    }
}

