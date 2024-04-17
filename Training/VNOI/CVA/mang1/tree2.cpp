#include <bits/stdc++.h>

using namespace std;

#define N 1000
vector <int> p,res;

int main() {
    int n,k,kq;

    int a[N+2],x[N+2];

    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    p.resize(n+3);
    res.resize(n+3);
    kq=n;
    for(int c=1;c<=1000;c++) {
        x[1]=c;
        for(int i=2;i<=n;i++)
            x[i]=x[i-1]+k;
        int d=0;
        for(int i=1;i<=n;i++) {
            p[i]=x[i]-a[i];
            if(p[i]!=0) d++;
        }
        if(d<kq) {
            kq=d; res=p;
        }
    }
    cout<<kq<<'\n';
    for(int i=1;i<=n;i++) {
        if(res[i] == 0) continue;
        if(res[i]<0)
            cout<<"- ";
        else if(res[i]>0)
            cout<<"+ ";
        cout<<i<<" "<<abs(res[i])<<'\n';
    }
}
