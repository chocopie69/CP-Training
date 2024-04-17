#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll a[7];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        ll sum = 0;
        for(int i = 0; i < 7; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sum /= 4;
        sort(a,a+7);
        for(int i = 0; i < 7-2; i++)
        {
            bool flag1 = false;
            for(int j = i+1; j < 7-1; j++)
            {
                bool flag2 = false;
                for(int k = j+1; k < 7; k++)
                {
                    if(a[i] + a[j] + a[k] == sum)
                    {
                        cout << a[i] << " " << a[j] << " " << a[k] << '\n';
                        flag2 = true;
                        break;
                    }
                }
                if(flag2)
                {
                    flag1 = true;
                    break;
                }
            }
            if(flag1)
            {
                break;
            }
        }
    }
}
