#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5*5;
long long n,res=0,s,a[maxN],cong[maxN];

void tknp()
{
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l+r)/2;
        bool flag = false;
        for(int i=mid;i<=n;i++) {
            if(cong[i] - cong[i-mid] >= s) {
                flag = true;
            }
        }
        if(flag) {
            r = mid-1;
            res = mid;
        } else {
            l = mid+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    long long maxA = -INT_MAX;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        if(a[i] > maxA) maxA = a[i];
    }
    if(maxA >= s) {
        cout << 1;
        return 0;
    }
    cong[1] = a[1];
    for(int i=2;i<=n;i++) cong[i] = cong[i-1] + a[i];
    tknp();
    cout << res;
}

