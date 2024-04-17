#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll a,b,c,m,n;

namespace sub1
{
    ll dp[SZ];

    ll solve()
    {
        dp[1] = 1 % m;
        dp[2] = 2 % m;
        dp[3] = 3 % m;
        for(int i = 4; i <= n; i++)
        {
            if(i % 3 == 1) dp[i] = ( (a*dp[i-1] % m) + (b*dp[i-2] % m) + (c*dp[i-3] % m) ) % m;
            else if(i % 3 == 2)
            {
                dp[i] = ( (b*dp[i-1] % m) + (c*dp[i-2] % m) + (a*dp[i-3] % m) ) % m;
                //cout << i << " " << dp[i] << " " << b*dp[i-1] << " " << c*dp[i-2] << " " << a*dp[i-3] << '\n';
            }
            else dp[i] = ( (c*dp[i-1] % m) + (a*dp[i-2] % m) + (b*dp[i-3] % m) ) % m;
        }
        return dp[n];
    }
}

namespace sub2
{
    struct Matrix
    {
        ll val[3][3];

        Matrix()
        {
            memset(val, 0, sizeof(val));
        }

        Matrix operator * (const Matrix& other) const
        {
            Matrix res;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    ll s = 0;
                    for(int k = 0; k < 3; k++)
                    {
                        s = (s % m  + (val[i][k]*other.val[k][j]) % m ) % m;
                    }
                    res.val[i][j] = s;
                }
            }
            return res;
        }
    };

    Matrix base;

    Matrix power(Matrix x, ll y)
    {
        if(y == 1) return x;
        Matrix cur = power(x, y/2);
        if(y % 2 == 0) return cur*cur;
        return ((cur * cur) * x);
    }

    ll solve()
    {
        base.val[0][0] = base.val[0][1] = base.val[0][2] = base.val[1][0] = base.val[2][1] = 1;
        if(n <= 3) return n % m;
        Matrix p = power(base, n - 3);
        return (3LL*p.val[0][0] + 2LL*p.val[0][1] + p.val[0][2]) % m;
    }
}

namespace sub3
{
    struct Matrix
    {
        ll val[3][3];

        Matrix()
        {
            memset(val, 0, sizeof(val));
        }

        Matrix operator * (const Matrix& other) const
        {
            Matrix res;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    ll s = 0;
                    for(int k = 0; k < 3; k++)
                    {
                        s = (s % m  + (val[i][k]*other.val[k][j]) % m ) % m;
                    }
                    res.val[i][j] = s;
                }
            }
            return res;
        }
    };

    Matrix base1, base2, base3, mvu;

    Matrix power(Matrix x, ll y)
    {
        if(y == 0) return mvu;
        if(y == 1) return x;
        Matrix cur = power(x, y/2);
        if(y % 2 == 0) return cur*cur;
        return ((cur * cur) * x);
    }

    ll solve()
    {
        base1.val[0][0] = a;
        base1.val[0][1] = b;
        base1.val[0][2] = c;
        base1.val[1][0] = base1.val[2][1] = 1;
        base2.val[0][0] = b;
        base2.val[0][1] = c;
        base2.val[0][2] = a;
        base2.val[1][0] = base2.val[2][1] = 1;
        base3.val[0][0] = c;
        base3.val[0][1] = a;
        base3.val[0][2] = b;
        base3.val[1][0] = base3.val[2][1] = 1;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                mvu.val[i][j] = 1;
            }
        }
        if(n <= 3) return n % m;
        ll h1 = (n - 4) / 3 + 1, h2 = (n >= 5 ? (n - 5) / 3 + 1 : 0) , h3 = (n >= 6 ? (n - 6) / 3 + 1 : 0 );
        Matrix p1 = power(base1, h1), p2 = power(base2, h2), p3 = power(base3, h3);
        Matrix p;
        if(h3 > 0) p = (p1 * p2) * p3;
        else if(h2 > 0) p = (p1 * p2);
        else p = p1;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << p1.val[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << p2.val[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << p3.val[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << p.val[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        Matrix ok = base1*base2;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << ok.val[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        return (3LL*p.val[0][0] + 2LL*p.val[0][1] + p.val[0][2]) % m;
    }
}

int main()
{
    init();
    while(cin >> a)
    {
        if(a == -1) break;
        cin >> b >> c >> m >> n;
        a %= m;
        b %= m;
        c %= m;
        if(n <= 1)
        {
            cout << sub1::solve() << '\n';
        } else if(a == b == c == 1)
        {
            cout << sub2::solve() << '\n';
        } else
        {
            cout << sub3::solve() << '\n';
        }
    }
}

/// 1 1 1 1009132 4590

