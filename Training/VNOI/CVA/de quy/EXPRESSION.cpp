#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int a[SZ];
bool flag;

void recur(int x, int i)
{
    if(i == 6)
    {
        if(x == 23) flag = true;
        return;
    }
    recur(x + a[i], i+1);
    recur(x - a[i], i+1);
    recur(x * a[i], i+1);
}

int main()
{
    init();
    while(cin >> a[1])
    {
        cin >> a[2] >> a[3] >> a[4] >> a[5];
        if(a[1] == 0) break;
        sort(a + 1, a + 6);
        flag = false;
        do
        {
            recur(a[1], 2);
        } while(next_permutation(a+1, a+6));
        cout << (flag == true ? "Possible" : "Impossible") << '\n';
    }
}
