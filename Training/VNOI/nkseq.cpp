/// https://oj.vnoi.info/problem/nkseq

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX, LIMIT = 1e5+5;
int n,a[LIMIT],prefixSum[LIMIT],suffixSum[LIMIT],minPrefixSum[LIMIT],maxSuffixSum[LIMIT],res = 0;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void preComputation()
{
    memset(minPrefixSum,0,sizeof(minPrefixSum));
    memset(maxSuffixSum,0,sizeof(maxSuffixSum));
    minPrefixSum[1] = a[1];
    maxSuffixSum[n] = a[n];
    for(int i = 1;i <= n;i++)
    {
        prefixSum[i]  = prefixSum[i-1] + a[i];
        minPrefixSum[i] = min(minPrefixSum[i-1],prefixSum[i]);
    }
    for(int i = n;i >= 1;i--)
    {
        suffixSum[i] = suffixSum[i+1] + a[i];
        maxSuffixSum[i] = max(maxSuffixSum[i+1],suffixSum[i]);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    preComputation();
    for(int i = 1;i <= n;i++)
    {
        if(suffixSum[i] - maxSuffixSum[i+1] > 0 && suffixSum[i] + minPrefixSum[i-1] > 0)
            res++;
    }
    cout << res;
}

