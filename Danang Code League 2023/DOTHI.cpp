#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Toado
{
    ll x,y;
};

Toado a[5];

int main()
{
    init();
    for(int i = 0; i < 3; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    ll xBA = a[0].x - a[1].x;
    ll yBA = a[0].y - a[1].y;
    ll xBC = a[2].x - a[1].x;
    ll yBC = a[2].y - a[1].y;
    ll crossProduct = xBA*yBC-xBC*yBA;
    if(crossProduct > 0)
    {
        cout << "RIGHT";
    }
    else if(crossProduct < 0)
    {
        cout << "LEFT";
    }
    else
    {
        cout << "TOWARDS";
    }
}

