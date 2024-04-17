/// https://codeforces.com/problemset/problem/1343/B

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX;
int t,n;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        ll evenSum = 0, oddSum = 0;
        cin >> n;
        if(n % 4 != 0)
        {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        ll curEven = 0, curOdd = -1;
        for(int i = 1; i <= n/2; i++)
        {
            curEven += 2LL;
            evenSum += curEven;
            cout << curEven << " ";
        }
        for(int i = 1; i < n/2;i++)
        {
            curOdd += 2LL;
            oddSum += curOdd;
            cout << curOdd << " ";
        }
        cout << evenSum-oddSum << '\n';
    }
}
