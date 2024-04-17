#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e4+5;
ll res=0;
int n,a[maxN];
vector<int> v;

bool prime(int x)
{
    if(x < 2) return false;
    for(int i=2;i * i <= x;i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(prime(a[i]))
        {
            res+=1LL*a[i];
            v.push_back(a[i]);
        }
    }
    cout << res << '\n';
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
}
