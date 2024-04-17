#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a,b,res=0;
    cin>>n>>m>>a>>b;
    int xa=ceil((float)a/(float)m),xb=ceil((float)b/(float)m);
    int ya=a%m,yb=b%m;
    if (ya==0) ya=m;
    if (yb==0) yb=m;
    //cout<<xa<<' '<<ya<<' '<<xb<<' '<<yb<<endl;
    if(xa==xb) {
        cout<<1;
    } else if (xb-xa==1) {
        if (ya==1&&(yb==m||b==n)) cout<<1;
        else cout<<2;
    } else{
        if (ya-yb==1) cout<<2;
        else {
            if (ya==1&&(yb==m||b==n)) cout<<1;
            else if (ya==1||(yb==m||b==n)) cout<<2;
            else cout<<3;
        }
    }
}
