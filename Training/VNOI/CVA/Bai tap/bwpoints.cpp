#include <bits/stdc++.h>
#define ll long long
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

int n,a[LIMIT],b[LIMIT], res = 0;
vector<Diem> v;

bool cmp(Diem z, Diem y)
{
    return z.x < y.x;
}

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back({a[i],69});
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        v.push_back({ b[i], 727 });
    }
    sort(v.begin(),v.end(), cmp);
    for(int i = 1; i < v.size();i++)
    {
        if(v[i].type != v[i-1].type)
        {
            res++;
            i++;
        }
    }
    cout << res;
}

