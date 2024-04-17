#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e5+5;
int n;
ll L;
vector<pair<ll,ll>> a;
map<ll,ll> m;

bool cmp(pair<ll,ll> x, pair<ll,ll> y)
{
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

int main()
{
    cin >> n >> L;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin >> x >> y;
        a.push_back({x,y*L+x});
    }
    vector<pair<ll, ll>> b = a;
    sort(a.begin(),a.end(),cmp);
    for(int i=1;i<n;i++)
    {
        if(a[i].first == a[i-1].first)
        {
            m[a[i].first] = max(a[i-1].second,a[i].second);
            a[i].second = max(a[i-1].second,a[i].second);
        }
    }
    for(int i=1;i<n;i++)
    {
        if(a[i].second <= a[i-1].second)
        {
            m[a[i].first] = a[i-1].second;
            a[i].second = a[i-1].second;
        } else {
            m[a[i].first] = a[i].second;
        }

    }
    for(int i=0;i<n;i++) {
        cout << m[b[i].first] << '\n';
    }
    /*for(int i=0;i<n;i++)
    {
        cout << a[i].first << " " << a[i].second.first << " " << a[i].second.second << '\n';
    }*/
}
