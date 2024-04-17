/// https://codeforces.com/contest/1790/problem/A

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define endl '\n'

using namespace std;

const int INF = INT_MAX, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const string PI = "314159265358979323846264338327";
int t;
string n;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        int res = 0;
        for(int i=0;i<n.length();i++)
        {
            if(n[i] == PI[i]) res++;
            else break;
        }
        cout << res << endl;
    }
}
