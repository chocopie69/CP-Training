#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int LIMIT = 2e5+5;
int a[LIMIT],b[LIMIT];
multiset<pair<int,int>> ms;
set<int> s;

int main()
{
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ms.insert({a[i],i});
        s.insert(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        auto it=ms.lower_bound({b[i],0});
        if(it==ms.end())
        {
            int cur = *s.begin();
            cout << cur << " ";
            ms.erase(ms.lower_bound({a[cur],0}));
            s.erase(s.begin());
        }
        else
        {
            cout<<(*it).second << " ";
            ms.erase(it);
            s.erase((*it).second);
        }
    }
}
