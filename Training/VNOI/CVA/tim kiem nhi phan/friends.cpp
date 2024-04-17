#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+3;
int n;
long long b,a[maxN],res=0;
map<int,int> dict;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        dict[a[i]]++;
    }
    for(int i=1;i<=n;i++) {
        dict[a[i]]--;
        res += dict[b-a[i]];
    }
    cout << res;
}
