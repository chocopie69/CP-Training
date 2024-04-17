#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TILE"

using namespace std;

const int SZ = 1e3+5;
const int SZ2 = 2;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Matrix
{
    ll val[SZ2][SZ2];
    Matrix(){};
    Matrix(ll x[SZ2][SZ2])
    {
        for(int i = 0; i < SZ2; i++)
        {
            for(int j = 0; j < SZ2; j++)
            {
                val[i][j] = x[i][j];
            }
        }
    }
};
Matrix operator * (const Matrix& a, const Matrix& other)
{
    Matrix res;
    for(int i = 0; i < SZ2; i++)
    {
        for(int j = 0; j < SZ2; j++)
        {
            res.val[i][j] = 0;
            for(int k = 0; k < SZ2; k++)
            {
                res.val[i][j] = (res.val[i][j] + (a.val[i][k] % MOD * other.val[k][j] % MOD) % MOD) % MOD;
            }
        }
    }
    return res;
}

Matrix power(const Matrix& a, ll x)
{
    if(x == 1) return a;
    Matrix c = power(a,x/2);
    if(x % 2 == 0) return c * c;
    return c * c * a;
}

int t;
ll n, base[SZ2][SZ2] = {1,2,1,0};

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        if(n == 2)
        {
            cout << 3 << '\n';
            continue;
        }
        Matrix F(base);
        F = power(F,n-1);
        cout << ((F.val[0][0] + F.val[0][1]) % MOD) << '\n';
    }
}
