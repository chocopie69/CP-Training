#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxN = 1e6+5;
ll a[maxN];
int n;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cout << a[i]/2 << endl;
}
