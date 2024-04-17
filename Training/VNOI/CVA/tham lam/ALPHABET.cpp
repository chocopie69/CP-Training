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

int t,n;
char a[LIMIT][LIMIT];

bool check(char c, int i, int j)
{
    if(i > 1 && c == a[i-1][j]) return false;
    if(i < n && c == a[i+1][j]) return false;
    if(j > 1 && c == a[i][j-1]) return false;
    if(j < n && c == a[i][j+1]) return false;
    return true;
}

int main()
{
    init();
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << '\n';
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[i][j] == '.')
                {
                    for(int x = 65; x <= 90; x++)
                    {
                        if(check(char(x),i,j))
                        {
                            a[i][j] = char(x);
                            break;
                        }
                    }
                }
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}

