#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[102];

bool cmp(pair<int,int> x, pair<int,int> y)
{
    if(x.second != y.second)
    {
        return x.second < y.second;
    }
    return x.first > y.first;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
}
