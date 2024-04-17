#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxN=6000,inf=2e18;
ll n,r[maxN+1],mx=-inf,a[maxN+1],tmp[maxN+1],mn=inf;
vector<ll> adj[maxN+1],pos;
void lis(ll n)
{
    vector<int> b(n+1,INT_MAX);
    b[0]=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        mx=max(mx,1LL*k);
    }
}

void lds(int n)
{
    vector<int> c(n+2,INT_MIN);
    c[0]=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int lo = 1, hi = n, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(c[mid] <= a[i])
            {
                hi = mid-1;
            } else
            {
                lo = mid+1;
            }
        }
        c[lo]=a[i];
        mx=max(mx,1LL*lo);
    }
}

void dfs(ll u,ll p,ll h)
{
    a[h]=r[u];
    if(adj[u].size()==1&&p!=-1)
    {
        lis(h);
        lds(h);
        return;
    }
    for(auto v:adj[u])
    {
        if(v!=p)
        {
            dfs(v,u,h+1);
        }

    }
}
int main()
{
    //freopen("THAMHIEM.INP","r",stdin);
    //freopen("THAMHIEM.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        mn=min(mn,r[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i]==mn)
        {
            pos.push_back(i);
        }
    }
    dfs(1,-1,1);
//    for(auto i:pos)
//    {
//        dfs(i,-1,1);
//    }
    cout<<mx;

}
/*
6
1 2 3 4 5 1
1 2
2 3
3 4
3 5
3 6
*/
/*11
1 2 3 1 2 3 2 3 1 2 3
1 2
2 3
1 7
7 8
2 4
4 5
5 6
5 9
9 10
10 11*/
