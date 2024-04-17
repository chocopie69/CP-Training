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

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, LIM = 1e18;
const double epsilon = 1e-3;

vector<ll> hamming;
bool check[SZ][SZ][SZ];

void gen(ll x, ll cnt2, ll cnt3, ll cnt5)
{
    if(check[cnt2][cnt3][cnt5]) return;
    check[cnt2][cnt3][cnt5] = true;
    hamming.pb(x);
    if(x * 2 <= LIM)
    {
        gen(x * 2, cnt2 + 1, cnt3, cnt5);
    }
    if(x * 3 <= LIM)
    {
        gen(x * 3, cnt2, cnt3 + 1, cnt5);
    }
    if(x * 5 <= LIM)
    {
        gen(x * 5, cnt2, cnt3, cnt5 + 1);
    }
}

int main()
{
    init();
    gen(1LL,0,0,0);
    sort(all(hamming));
    //for(ll x : hamming) cout << x << " ";
    int q;
    cin >> q;
    while(q--)
    {
        ll x;
        cin >> x;
        int pos = lwb(all(hamming), x) - hamming.begin();
        cout << (hamming[pos] == x ? pos + 1 : -1) << '\n';
    }
}

