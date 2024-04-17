#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=6e5;
struct pll
{
    ll fi,se;
};
struct area
{
    ll x,y1,y2,type;
};
bool cmp(area x,area y)
{
    if(x.x==y.x)
    {
        return x.type>y.type;
    }
    return x.x<y.x;
}
pll sum[4*maxN+5];
vector<area> v;
vector<ll> cprs;
ll n,l,r,val,res=0;
void Update(ll x,ll low,ll high)
{
    if(low>r||high<l)
    {
        return;
    }
    if(low>=l&&high<=r)
    {
        sum[x].se+=val;
        if(sum[x].se)
        {
            sum[x].fi=(cprs[high]-cprs[low-1]);
        }
        else
        {
            if(low==high)
            {
                sum[x].fi=0;
            }
            else sum[x].fi=sum[2*x].fi+sum[2*x+1].fi;
        }
        return;
    }
    ll mid=(low+high)/2;
    Update(2*x,low,mid);
    Update(2*x+1,mid+1,high);
    if(sum[x].se)
    {
        sum[x].fi=(cprs[high]-cprs[low-1]);
    }
    else if(low != high) sum[x].fi=sum[2*x].fi+sum[2*x+1].fi;
    else sum[x].fi = 0;
}
void update_val(ll l,ll r,ll val)
{
    ::l=l;
    ::r=r;
    ::val=val;
    Update(1,1,cprs.size());
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x1,x2,y1,y2;
        cin>>x1>>x2>>y1>>y2;
        v.push_back({x1,y1,y2,1});
        v.push_back({x2,y1,y2,-1});
        cprs.push_back(y1);
        cprs.push_back(y2);
        cprs.push_back(y2-1);
    }
    cprs.push_back(0);
    cprs.push_back(int(1e9));
    sort(cprs.begin(),cprs.end());
    //cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    cprs.erase(unique(cprs.begin(),cprs.end()), cprs.end());
    for(int i=0;i<v.size();i++)
    {
        v[i].y1=lower_bound(cprs.begin(),cprs.end(),v[i].y1)-cprs.begin()+1;
        v[i].y2=lower_bound(cprs.begin(),cprs.end(),v[i].y2)-cprs.begin()+1;
    }
    sort(v.begin(),v.end(),cmp);
    ll cur=0;
    for(int i=0;i<v.size()-1;i++)
    {
        update_val(v[i].y1,v[i].y2-1,v[i].type);
        res+=(v[i+1].x-v[i].x)*(sum[1].fi);
        //cur=v[i].x;
    }
    cout<<res;
}
