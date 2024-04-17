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

int t,n,a[LIMIT],b[LIMIT];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        char res = 'Y';
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[i])
            {
                res = 'N';
                break;
            }
        }
        cout << res << '\n';
    }
}

