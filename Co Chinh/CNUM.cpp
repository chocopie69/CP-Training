#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e6+5;
int q,a,b,ans[LIMIT];
bool validNum[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CNUM.INP","r",stdin);
    freopen("CNUM.OUT","w",stdout);
}

void preCalc()
{
    memset(validNum,true,sizeof(validNum));
    for(int i=2;i*i<LIMIT;i++)
    {
        int sqr = i*i;
        for(int j=sqr;j<LIMIT;j+=sqr)
        {
            validNum[j] = false;
        }
    }
    ans[0] = 0;
    for(int i=1;i<LIMIT;i++)
    {
        ans[i] = ans[i-1] + validNum[i];
    }
}

int main()
{
    init();
    preCalc();
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        cout << ans[b] - ans[a-1] << '\n';
    }
}
