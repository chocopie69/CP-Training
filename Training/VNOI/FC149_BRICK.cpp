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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,k, pos;
ll a[SZ], sum1 = 0, sum2 = 0, x, mn = INFLL;
multiset<ll> lower, upper;

void moveElements()
{
    while( (int) lower.size() > (k+1) / 2)
    {
        ll top = *lower.rbegin();
        upper.insert(top);
        sum2 += top;
        lower.erase(lower.find(top));
        sum1 -= top;
    }
    while( (int) upper.size() > k / 2)
    {
        ll top = *upper.begin();
        lower.insert(top);
        sum1 += top;
        upper.erase(upper.find(top));
        sum2 -= top;
    }
}

void add(ll x)
{
    ll med = (lower.empty() ? -1 : *lower.rbegin());
    if(x <= med)
    {
        lower.insert(x);
        sum1 += x;
    } else
    {
        upper.insert(x);
        sum2 += x;
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(a[i]);
        if(i < k) continue;
        if(i > k)
        {
            ll cur = a[i - k];
            if(lower.find(cur) != lower.end())
            {
                lower.erase(lower.find(cur));
                sum1 -= cur;
            } else
            {
                upper.erase(upper.find(cur));
                sum2 -= cur;
            }
        }
        moveElements();
        ll med = *lower.rbegin(), val1 = med * lower.size() - sum1, val2 = sum2 - med * upper.size();
//        for(ll x : lower) cout << x << " ";
//        cout << "| ";
//        for(ll x : upper) cout << x << " ";
//        cout << "| " << med << " " << val1 << " " << val2 << '\n';
        if(val1 + val2 < mn)
        {
            mn = val1 + val2;
            pos = i;
            x = med;
        }
    }
    cout << mn << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(i >= pos - k + 1 && i <= pos)
        {
            cout << x << '\n';
        } else
        {
            cout << a[i] << '\n';
        }
    }
}
