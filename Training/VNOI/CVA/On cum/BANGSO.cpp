#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[100005],res[LIMIT][LIMIT],x=1,y=1,cnt=0;
char dir = 'r';

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n*n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n*n+1);
    cout << n << '\n';
    for(int i = 1; i <= n*n;i++)
    {
        res[y][x] = a[i];
        //cout << y << " " << x << '\n';
        if(dir == 'r')
        {
            if(x == n-cnt)
            {
                dir = 'd';
                y++;
                //cout << i << " 1" << '\n';
            }
            else x++;
        }
        else if(dir == 'd')
        {
            if(y == n-cnt)
            {
                dir = 'l';
                x--;
                //cout << i << " 2" << '\n';
            } else y++;
        }
        else if(dir == 'l')
        {
            if(x == 1+cnt)
            {
                dir = 'u';
                y--;
                cnt++;
                //cout << i << " 3" << '\n';
            }
            else x--;
        }
        else if(dir == 'u')
        {
            if(y == 1+cnt)
            {
                dir = 'r';
                x++;
                //cout << i << " 4" << '\n';
            }
            else y--;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}

