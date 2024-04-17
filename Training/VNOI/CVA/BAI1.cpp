#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN=1e5+5;
int n,a[maxN+1],pos,l,r,vt[maxN+1];
struct sapxep
{
    int s,x;
}sum[4*maxN+1];
void Update1(int x,int low,int high)
{
    if(low==high)
    {
        sum[x].s=1;
        return;
    }
    int mid=(low+high)/2;
    if(pos<=mid)
    {
        Update1(2*x,low,mid);
    }
    else Update1(2*x+1,mid+1,high);
    sum[x].s=sum[2*x].s+sum[2*x+1].s;
}
void update_val1(int pos)
{
    ::pos=pos;
    Update1(1,1,n);
}
int gets(int x,int low,int high)
{
    if(low>r||high<l)
    {
        return 0;
    }
    if(low>=l&&high<=r)
    {
        return sum[x].s;
    }
    int mid=(low+high)/2;
    int get1=gets(2*x,low,mid);
    int get2=gets(2*x+1,mid+1,high);
    return get1+get2;
}
int querys(int l,int r)
{
    ::l=l;
    ::r=r;
    if(l>r)
    {
        swap(l,r);
    }
    return gets(1,1,n);
}
void Update2(int x,int low,int high)
{
    if(low==high)
    {
        sum[x].x=1;
        return;
    }
    int mid=(low+high)/2;
    if(pos<=mid)
    {
        Update2(2*x,low,mid);
    }
    else Update2(2*x+1,mid+1,high);
    sum[x].x=sum[2*x].x+sum[2*x+1].x;
}
void update_val2(int pos)
{
    ::pos=pos;
    Update2(1,1,n);
}
int getx(int x,int low,int high)
{
    if(low>r||high<l)
    {
        return 0;
    }
    if(low>=l&&high<=r)
    {
        return sum[x].x;
    }
    int mid=(low+high)/2;
    int get1=getx(2*x,low,mid);
    int get2=getx(2*x+1,mid+1,high);
    return get1+get2;
}
int queryx(int l,int r)
{
    ::l=l;
    ::r=r;
    if(l>r)
    {
        swap(l,r);
    }
    return getx(1,1,n);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        vt[a[i]]=i;
    }
    int tmp=(n+1)/2;
    int l=1,r=n,dem=0;
    while(dem!=n)
    {
        int cur1=queryx(1,vt[l]-1),cur2=querys(1,vt[l]-1);
        cout<<vt[l]-l+(l-cur2-1)-cur1<<'\n';
        update_val1(vt[l]);
        //cout<<vt[l]<<" "<<query()
        dem++;
        if(l==r)
        {
            continue;
        }
        int cur3=queryx(1,vt[r]-1),cur4=querys(vt[r]+1,n);
        cout<<r-vt[r]-cur4+cur3<<'\n';
        //cout<<vt[r]<<" "<<queryx(3,4)<<'\n';
        update_val2(vt[r]);
        dem++;
        l++;
        r--;
    }
    //cout<<queryx(3,4);
}
