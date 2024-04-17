#include <bits/stdc++.h>
using namespace std;

struct Person
{
    int height,index;
};

const int LIMIT = 1e4+2;
int n,k,m,ans[LIMIT];
queue<Person> a;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ans,0,sizeof(ans));
}

int main()
{
    init();
    cin >> n >> k >> m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        a.push({x,i});
    }
    while(m-- && !a.empty())
    {
        Person cur = a.front();
        if(cur.height > k)
        {
            a.push(cur);
        }
        ans[cur.index]++;
        a.pop();
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
    }
}
