#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FRAC"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
vector<pii> v;

bool cmp(pii x, pii y)
{
    return (double)x.first / x.second < (double) y.first / y.second;
}

void recur(pii left, pii right)
{
    pii mid = {left.first + right.first, left.second + right.second};
    if(mid.second > n) return;
    recur(left,mid);
    recur(mid,right);
    v.push_back(mid);
}

int main()
{
    init();
    cin >> n;
    recur({0,1}, {1,1});
    sort(v.begin(),v.end(),cmp);
    for(pii p : v)
    {
        cout << p.first << " " << p.second << '\n';
    }
}

