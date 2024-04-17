#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "ZERO"

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

int n;
bool visited[LIMIT];
vector<int> res;
queue<int> qu;

int main()
{
    init();
    memset(visited,false,sizeof(visited));
    cin >> n;
    qu.push(n);
    visited[n] = true;
    while(!qu.empty())
    {
        int cur = qu.front();
        for(int i = 1; i * i <= cur; i++)
        {
            if(cur % i == 0)
            {
                int next = (i-1) * (cur/i+1);
                if(!visited[next])
                {
                    qu.push(next);
                    res.push_back(next);
                    visited[next] = true;
                }
            }
        }
        qu.pop();
    }
    sort(res.begin(),res.end());
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
        //if((i+1) % 10 == 0) cout << '\n';
    }
}

