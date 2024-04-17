#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2005;
int n;
pair<ll,ll> a[maxN];

double getDist(ll posX1,ll posY1, ll posX2,ll posY2)
{
    return sqrt(pow(abs(posX1-posX2),2) + pow(abs(posY1-posY2),2));
}

int main()
{
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a,a+n);
        int res = 1;
        ll xLocation = a[0].first, yLocation = a[0].second;
        for(int i=1;i<n;i++)
        {
            double dist = getDist(a[i].first,a[i].second,xLocation,yLocation);
            if(dist >= 1.3)
            {
                res++;
                xLocation = a[i].first;
                yLocation = a[i].second;
            }
        }
        cout << res << '\n';
    }
}

