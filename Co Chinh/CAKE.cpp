#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Event
{
    int type,x;
};

const int LIMIT = 1e6+5;
ll n,q,sum=0,tt=0;
deque<ll> dq;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAKE.INP","r",stdin);
    freopen("CAKE.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        int cur;
        cin >> cur;
        sum += cur;
        dq.push_back(sum);
    }
    while(q--)
    {
        Event ev;
        cin >> ev.type >> ev.x;
        if(ev.type == 0)
        {
            cout << upper_bound(dq.begin(),dq.end(),ev.x-tt) - dq.begin() << '\n';
        }
        else if(ev.type == 1)
        {
            tt += ev.x;
            dq.push_front(-tt+1);
        }
        else
        {
            dq.push_back(dq.front() + ev.x);
        }
    }
    /*dq.push_back(2);
    dq.push_back(10);
    dq.push_back(14);
    cout << upper_bound(dq.begin(),dq.end(),2) - dq.begin() << '\n';*/
}
