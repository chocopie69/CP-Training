#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

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

int q,t;
ull x,y,i,v;

int main()
{
    init();
    cin >> q;
    while(q--)
    {
        cin >> t >> x;
        if(t != 7)
        {
            cin >> y;
            switch(t)
            {
                case 1: {
                    cout << (x&y) << '\n';
                    break;
                }
                case 2: {
                    cout << (x|y) << '\n';
                    break;
                }
                case 3: {
                    cout << (x^y) << '\n';
                    break;
                }
                case 4: {
                    cout << (x << y) << '\n';
                    break;
                }
                case 5: {
                    cout << (x >> y) << '\n';
                    break;
                }
                case 6: {
                    cout << (x >> y & 1ULL) << '\n';
                    break;
                }
                default: {
                    break;
                }
            }
        } else
        {
            cin >> i >> v;
            if(v == 1)
            {
                cout << (x | (1ULL << i)) << '\n';
            } else
            {
                cout << (x & ~(1ULL << i)) << '\n';
            }
        }
    }
}
