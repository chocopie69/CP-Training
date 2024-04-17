#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Diem
{
    int x, type;
    Diem(int _x, int _type)
    {
        x = _x;
        type = _type;
    }
};

int t,n,x,r, res = 0;
vector<Diem> v;

bool cmp(Diem z, Diem y)
{
    return z.x < y.x;
}

signed main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> r;
            v.push_back({x-r,69});
            v.push_back({x+r,727});
        }
        sort(v.begin(),v.end(), cmp);
        res = 0;
        int cnt = 0;
        for(int i = 0; i < v.size();i++)
        {
            if(cnt > 0)
            {
                res += (v[i].x - v[i-1].x);
            }
            if(v[i].type == 69) cnt++;
            else cnt--;
        }
        cout << res << '\n';
        while(!v.empty()) v.pop_back();
    }
}

