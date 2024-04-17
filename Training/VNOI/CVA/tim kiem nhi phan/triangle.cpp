#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+3;
int n;
long long a[maxN],b[maxN],c[maxN],res=0;

void read()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    sort(c,c+n);
    c[n] = INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int pos = lower_bound(c,c+n,a[i]+b[j]) - c;
            int pos2 = upper_bound(c,c+n,abs(a[i]-b[j])) - c;
            res+=max(0,pos-pos2);
            //for(int k = pos2;k<pos;k++) cout << a[i] << " " << b[j] << " " << c[k] << '\n';
        }
    }
    cout << res;
}


