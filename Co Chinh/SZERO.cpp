#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
ll n,a,sum=0,maxLen = 0,startIndex,endIndex;
map<ll,ll> m;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("SZERO.INP","r",stdin);
    //freopen("SZERO.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    m[0] = -1;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        sum += a;
        if(m.find(sum) != m.end())
        {
            if(i-m[sum] > maxLen)
            {
                maxLen = max(maxLen,i-m[sum]);
                startIndex = m[sum] + 1;
                endIndex = i;
            }
            //cout << i << " " << m[sum] << '\n';
        }
        else m[sum] = i;
    }
    cout << startIndex + 1 << " " << endIndex + 1;
}
