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

const int SZ = 8e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

const ll BASE = 311;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
int n, res;
ll hashS[SZ], powBase[SZ], hashVal;

void buildHash()
{
    hashS[0] = 0;
    powBase[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        powBase[i] = (powBase[i-1] * BASE) % MOD;
        hashS[i] = (hashS[i-1] * BASE + int(s[i])) % MOD;
    }
}

ll getHash(int lo, int hi)
{
    if(lo > hi) return -1LL;
    return (hashS[hi] - hashS[lo-1] * powBase[hi-lo+1] + MOD*MOD) % MOD;
}

int main()
{
    init();
    cin >> s;
    n = s.length();
    if(n % 2 == 0 || n < 3)
    {
        cout << "NOT POSSIBLE";
        return 0;
    }
    s = " " + s;
    buildHash();
    bool flag = false;
    int mid = (n-1)/2 + 1;
    for(int i = 1; i <= mid; i++)
    {
        int len = i-1, len2 = mid - 1 - len;
        if( getHash(1,len) == getHash( mid + 1, mid + 1 + len - 1)  && getHash(i+1, i+1+len2-1) == getHash(n-len2+1,n) )
        {
            if(!flag)
            {
                flag = true;
                res = i;
                hashVal = getHash(mid+1,n);
                //cout << "gay";
            } else if(getHash(mid+1,n) != hashVal)
            {
                cout << "NOT UNIQUE";
                //cout << " " << res << " " << i;
                return 0;
            }
        }
    }
    for(int i = mid + 1; i <= n; i++)
    {
        int len = i - 1 - mid + 1, len2 = mid - 1 - len;
        if( getHash( mid , mid + len - 1 ) == getHash(1, 1 + len - 1) && getHash(i+1, i+1 + len2 - 1) == getHash( mid - 1 - len2 + 1, mid - 1 ) )
        {
            if(!flag)
            {
                flag = true;
                res = i;
                hashVal = getHash(1,mid-1);
            } else if(getHash(1,mid-1) != hashVal)
            {
                cout << "NOT UNIQUE" ;
                //cout << '\n' << getHash( (n-1)/2 + 1 , (n-1)/2 + 1 + len - 1 ) << " " << getHash(1, 1 + len - 1);
                return 0;
            }
        }
    }
    if(!flag)
    {
        cout << "NOT POSSIBLE";
        return 0;
    }
    //cout << res << '\n';
    if(res <= mid)
    {
        for(int i = 1; i <= mid; i++)
        {
            if(i != res) cout << s[i];
        }
    } else
    {
        for(int i = mid; i <= n; i++)
        {
            if(i != res) cout << s[i];
        }
    }
}
