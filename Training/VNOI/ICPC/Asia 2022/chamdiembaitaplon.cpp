#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxN = 1e5+5;
ll n,k,a[maxN],sum,sum1,minRight[maxN];
double maxScore = 0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    minRight[n] = a[n];
    for(int i=n-1;i>=1;i--)
    {
        minRight[i] = min(minRight[i+1],a[i]);
    }
    sum1 = sum;
    for(int i=1;i<=n-2;i++)
    {
        if(i > 1) sum += minRight[i];
        sum -= (a[i] + minRight[i+1]);
        maxScore = max(maxScore,(double)sum/(n-i-1));
    }
    for(int i=1;i<=n-2;i++)
    {
        if(i > 1) sum1 += minRight[i];
        sum1 -= (a[i] + minRight[i+1]);
        double score = (double)sum1/(n-i-1);
        if(score == maxScore) cout << i << " ";
    }
}

