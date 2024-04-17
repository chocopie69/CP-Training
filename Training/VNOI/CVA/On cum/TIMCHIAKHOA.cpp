#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 2500+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[LIMIT], res = 0, cnt = 0;
map<int,int> mp;
vector<int> v;

bool check(int x)
{
    int sum = 0;
    for(int i = 0; i < x;i++)
    {
        sum += v[i];
    }
    return sum >= n;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(pii p : mp)
    {
        v.push_back(p.second);
    }
    sort(v.begin(),v.end(),greater<int>());
    int L = 1, R = v.size()-1;
    while(L <= R)
    {
        int mid = (L+R)/2;
        if(check(mid))
        {
            R = mid-1;
        }
        else
        {
            L = mid+1;
        }
    }
    cout << R;
}

