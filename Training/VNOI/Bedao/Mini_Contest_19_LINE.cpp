#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

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

int n, xA = 0, yA = 0, xB = 0, yB = 1;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            cout << xA << " " << yA << '\n';
            xA++;
            yA += 2;
        } else
        {
            cout << xB << " " << yB << '\n';
            xB += 2;
            yB++;
        }
    }
    cout << "0 0 " << xA-1 << " " << yA-2 << '\n';
    cout << "0 1 " << xB-2 << " " << yB-1;

}

