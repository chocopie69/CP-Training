#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 12,maxM = 1e6+5;

int n;
ll m,s,res=1e18*2;
pair<ll,ll> a[maxN];
bool flag = false;

void recur(int i, ll cnt, ll sj)
{
    if(sj==0) res = min(res,cnt),flag=true;
    if(i == n) i = 0;
    if(sj == s && cnt > 0) return;
    ll cur = (sj*a[i].first + a[i].second) % m;
    recur(i+1,cnt+1,cur);
    recur(i+1,cnt,sj);
}

int main()
{
    cin >> m >> n >> s;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    recur(0,0LL,s);
    if(flag) cout << res;
    else cout << -1;
}
