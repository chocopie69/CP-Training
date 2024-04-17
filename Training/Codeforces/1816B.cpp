#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n, res[SZ], res2[SZ];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        int cur1 = 1,  cur2 = 2*n-3;
        cout << 2*n << " ";
        for(int i = 1; i < n; i++)
        {
            if(i % 2 == 1)
            {
                cout << cur1 << " ";
                cur1 += 2;
            }
            else
            {
                cout << cur2 << " ";
                cur2 -= 2;
            }
        }
        cout << '\n';
        cur1 = 2, cur2 = 2*n-2;
        for(int i = 1; i < n; i++)
        {
            if(i % 2 == 1)
            {
                cout << cur1 << " ";
                cur1 += 2;
            }
            else
            {
                cout << cur2 << " ";
                cur2 -= 2;
            }
        }
        cout << 2*n-1 << '\n';
    }
}

/*
12 1 9 3 7 5
2 10 4 8 6 11

n = 4
8 1 5 3
2 6 4 7

n = 2
4 1
2 3
*/

