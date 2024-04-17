#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+6;
int t,a,b;
//bool prime[maxN+2];
int ans[maxN+2],cnt[maxN+2],prime[maxN+2];

void sang()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i*i<=maxN;i++)
    {
        if(prime[i] == 0) for(int j=i*i;j<=maxN;j+=i)
        {
            if(prime[j] == 0) prime[j] = i;
        }
    }
    for(int i=1;i<=maxN;i++)
    {
        if(prime[i] == 0) prime[i] = i;
    }
}

bool check(int x)
{
    int n=x,res=1;
    while(n != 1)
    {
        int cur = 0,i = prime[n];
        while(prime[n] == i)
        {
            n /= prime[n];
            cur++;
        }
        res *= (cur+1);
    }
    return res == prime[res];
}

void calcUoc()
{
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=maxN;i++)
    {
        for(int j=i;j<=maxN;j+=i)
        {
            cnt[j]++;
        }
    }
}

void calc()
{
    memset(ans,0,sizeof(ans));
    for(int i=2;i<=maxN;i++)
    {
        ans[i] = ans[i-1] + int(check(i));
        //cout << i << " " << check(i) << " " << prime[check(i)] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sang();
    //calcUoc();
    calc();
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << ans[b] - ans[a-1] << '\n';
    }
}
