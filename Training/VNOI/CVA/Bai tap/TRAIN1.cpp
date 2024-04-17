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

int n,x;
bool found = true,inB[SZ];
deque<int> dqA, dqB, dqC;
vector<string> res;

int main()
{
    init();
    cin >> n;
    memset(inB,false,sizeof(false));
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        dqC.push_back(x);
        dqA.push_back(i);
    }
    while(!dqC.empty())
    {
        ll cur = dqC.front();
        if(inB[cur])
        {
            if(dqB.front() == cur)
            {
                res.push_back("B->C");
                dqC.pop_front();
                dqB.pop_front();
            }
            else
            {
                found = false;
                break;
            }
        }
        else
        {
            while(!dqA.empty() && dqA.front() != cur)
            {
                dqB.push_back(dqA.front());
                inB[dqA.front()] = true;
                dqA.pop_front();
                res.push_back("A->B");
            }
            if(dqA.empty())
            {
                found = false;
                break;
            }
            else
            {
                res.push_back("A->C");
                dqC.pop_front();
                dqA.pop_front();
            }
        }
    }
    if(found)
    {
        cout << "YES" << '\n';
        for(string s : res)
        {
            cout << s << '\n';
        }
    }
    else
    {
        cout << "NO";
    }
}


