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
string a,b;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        int n = a.length(), m = b.length();
        a = " " + a;
        b = " " + b;
        int c = __gcd(n,m);
        bool check = true;
        for(int i = 1; i <= c; i++)
        {
            bool flag = false;
            for(int j = i; j <= n; j += c)
            {
                if(a[i] != a[j])
                {
                    check = false;
                    flag = true;
                }
            }
            if(flag) break;
        }
        for(int i = 1; i <= c; i++)
        {
            bool flag = false;
            for(int j = i; j <= m; j += c)
            {
                if(b[i] != b[j])
                {
                    check = false;
                    flag = true;
                }
            }
            if(flag) break;
        }
        if(a.substr(1,c) != b.substr(1,c)) check = false;
        if(check)
        {
            cout << a.substr(1,c) << '\n';
        }
        else
        {
            cout << '!' << '\n';
        }
    }
}

