#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int k,n,m,x;
priority_queue<int> pqa,pqb;
queue<int> qa,qb;

int main()
{
    init();
    cin >> k >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        pqa.push(x);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> x;
        pqb.push(x);
    }
    while(true)
    {
        int num = min(k,(int) min(pqa.size(),pqb.size()));
        while(num--)
        {
            int topa = pqa.top(), topb = pqb.top();
            if(topa > topb)
            {
                qa.push(topa-topb);
            }
            else if(topb > topa)
            {
                qb.push(topb-topa);
            }
            pqa.pop();
            pqb.pop();
        }
        while(!qa.empty())
        {
            pqa.push(qa.front());
            qa.pop();
        }
        while(!qb.empty())
        {
            pqb.push(qb.front());
            qb.pop();
        }
        if(pqa.empty() && pqb.empty())
        {
            cout << "An and Binh draw";
            return 0;
        }
        else if(pqb.empty())
        {
            cout << "An wins" << '\n';
            while(!pqa.empty())
            {
                cout << pqa.top() << " ";
                pqa.pop();
            }
            return 0;
        }
        else if(pqa.empty())
        {
            cout << "Binh wins" << '\n';
            while(!pqb.empty())
            {
                cout << pqb.top() << " ";
                pqb.pop();
            }
            return 0;
        }
    }
}
