#include<bits/stdc++.h>
using namespace std;
int lot=INT_MAX,hit=INT_MIN;
int n,k;
int a[200001];
bool check(double m) {
    double r[n+1];
    for (int i=1;i<=n;i++) r[i]=a[i]-m;
    double rs=0,ls=0;
    for (int i=1;i<=k;i++) rs+=r[i];
    if (rs>=0) return true;
    for (int i=k+1;i<=n;i++) {
        rs+=r[i];
        ls+=r[i-k];
        if (ls<0) {
            rs-=ls;
            ls=0;
        }
        if (rs>=0) return true;
    }
    return false;
}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        lot=min(lot,a[i]);
        hit=max(hit,a[i]);
    }
    double lo=lot,hi=hit;
    while (hi-lo>1e-4) {
        double mid=lo+(hi-lo)/2;
        if (check(mid)==true) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    cout.precision(3);
    cout<<fixed<<lo;
}
