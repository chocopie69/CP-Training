#include<bits/stdc++.h>
using namespace std;
int n;
int res=INT_MAX;
vector<int>v1,v2,v3;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x,t;
        cin>>x>>t;
        if (t==1) v1.push_back(x);
        else if (t==2) v2.push_back(x);
        else v3.push_back(x);
    }
    for (int i=0;i<v1.size();i++) {
        int x2,x3;
        auto it=lower_bound(v2.begin(),v2.end(),v1[i]);
        auto it2=lower_bound(v3.begin(),v3.end(),v1[i]);
        if (it==v2.end()||it2==v3.end()) break;
        x2=*it,x3=*it2;
        int l=v1[i],r=max(x2,x3);
        res=min(res,r-l);
    }
    for (int i=0;i<v2.size();i++) {
        int x1,x3;
        auto it=lower_bound(v1.begin(),v1.end(),v2[i]);
        auto it2=lower_bound(v3.begin(),v3.end(),v2[i]);
        if (it==v1.end()||it2==v3.end()) break;
        x1=*it,x3=*it2;
        int l=v2[i],r=max(x1,x3);
        res=min(res,r-l);
    }
    for (int i=0;i<v3.size();i++) {
        int x1,x2;
        auto it=lower_bound(v1.begin(),v1.end(),v3[i]);
        auto it2=lower_bound(v2.begin(),v2.end(),v3[i]);
        if (it==v1.end()||it2==v2.end()) break;
        x1=*it,x2=*it2;
        int l=v3[i],r=max(x1,x2);
        res=min(res,r-l);
    }
    cout<<res;
}
