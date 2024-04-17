#include<bits/stdc++.h>
using namespace std;
const int MAX=1e7+5;
int n,a[MAX],b[MAX],res=0;
set<int> s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        s.insert(a[i]);
    }
    sort(b+1,b+n+1,greater<int>());
    for(int i=1;i<=n;i++)
    {
        auto it=s.upper_bound(b[i]);
        if(it==s.begin()&&!s.empty())
        {
            it=s.end();
            it--;
            s.erase(it);
        }
        else if(it!=s.begin()&&!s.empty())
        {
            it--;
            if(*it==b[i])
            {
                res+=1;
            }
            else res+=2;
            s.erase(it);
        }
    }
    cout<<res;
    return 0;
}
