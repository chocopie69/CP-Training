#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Sum
{
    ll value,index;
};

const int LIMIT = 1e6+3;
ll n,a[LIMIT],minIndex = INT_MAX,startIndex,endIndex,maxLen=0;
Sum s[LIMIT],s1[LIMIT];

bool cmp(Sum x, Sum y)
{
    if(x.value != y.value)
        return x.value < y.value;
    return x.index > y.index;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PS.INP","r",stdin);
    freopen("PS.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    s[0] = {0,0};
    s1[0] = {0,0};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i] = {s[i-1].value + a[i],i};
        s1[i] = s[i];
    }
    sort(s,s+n+1,cmp);
    for(int i=0;i<=n;i++)
    {
        if((i == 0 || s[i].value != s1[minIndex].value) && (s[i].index - minIndex) > maxLen)
        {
            maxLen = s[i].index - minIndex;
            startIndex = minIndex+1;
            endIndex = s[i].index;
        }
        //cout << s[i].index << " " << minIndex << endl;
        minIndex = min(minIndex,s[i].index);
        //cout << s[i].value << " " << s[i].index << " " << minIndex << endl;
    }
    cout << startIndex << " " << endIndex;
}

/*
10
-5 -2 -3 4 -6 7 -8 9 -1 -20
*/
