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

    int n;

    void recur(int n, string a, string c, string b)
    {
        if(n == 1)
        {
            cout << a << "->" << c << '\n';
            return;
        }
        recur(n-1, a, b , c);
        recur(1, a , c, b);
        recur(n-1, b, c, a);
    }

    int main()
    {
        init();
        cin >> n;
        recur(n, "A", "C", "B");
    }

