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

int m,k,cur;
string s;
deque<int> dq;

int main()
{
    init();
    cin >> m >> k >> s;
    for(int i = 0; i < m; i++)
    {
        dq.push_back(i);
    }
    for(char c : s)
    {
        ll cur = dq.front();
        if(c == 'A')
        {
            dq.pop_front();
            dq.push_back(cur);
        } else if(c == 'B')
        {
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
            dq.push_front(cur);
        }
    }
    while(!dq.empty())
    {
        dq.pop_front();
        k--;
        if(k <= 1 && k >= -1) cout << dq.front() << " ";
    }
}

