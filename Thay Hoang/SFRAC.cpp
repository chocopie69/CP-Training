#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct num
{
    int i,j;
    double val;
};

int n;
vector<num> v;

void init()
{
    freopen("SFRAC.INP","r",stdin);
    freopen("SFRAC.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool cmp(num a, num b)
{
    return a.val < b.val;
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(__gcd(i,j) == 1) v.push_back({i, j, double(i)/j});
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(num cur : v)
    {
        cout << cur.i << " " << cur.j << '\n';
    }
}

