#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
long long n,m,a[maxN],s[maxN],res=0;

bool check(long long mid)
{
    int pos = upper_bound(a+1,a+n+1,mid) - a;
    long long tong = s[n] - s[pos-1] - mid*(n-pos+1);
    if(tong >= m) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    s[1] = a[1];
    for(int i=2;i<=n;i++) s[i] = s[i-1] + a[i];
    long long l = 1, r = 2*1e9;
    while(l <= r) {
        long long mid = (l+r)/2;
        if(check(mid)) {
            l = mid+1;
            res = mid;
        } else r = mid-1;
    }
    cout << res;
}

