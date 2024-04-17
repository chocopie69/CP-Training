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

ll t,n,a[SZ],cnt[SZ];
vector<string> res;

void recur(int i, string x)
{
    if(i == n)
    {
        res.push_back(x);
        return;
    }
    recur(i+1,x + "1");
    recur(i+1,x + "0");
}

bool check(string s)
{
    cnt[0] = 0;
    string x = " " + s;
    for(int i = 1; i <= n; i++)
    {
        cnt[i] = cnt[i-1] + int(x[i] == '1');
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 1)
        {
            if(x[i] == '1' && cnt[i-1] < cnt[n]-cnt[i]) return false;
            if(x[i] == '0' && cnt[i-1] >= cnt[n]-cnt[i]) return false;
        } else
        {
            if(x[i] == '0' && cnt[i-1] < cnt[n]-cnt[i]) return false;
            if(x[i] == '1' && cnt[i-1] >= cnt[n]-cnt[i]) return false;
        }
    }
    return true;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        res.clear();
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        recur(0,"");
        for(string s : res)
        {
            if(check(s))
            {
                for(char c : s)
                {
                    cout << c << " ";
                }
            }
        }
        cout << '\n';
    }
}
