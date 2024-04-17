#include <bits/stdc++.h>
using namespace std;

long long res = -2*1e18,n;
pair<long long,long long> a[500002];

void recur(int i, long long curSum, long long curMax, long long curMin,int choose)
{
    if(choose > 0) res = max(res,curSum - (curMax - curMin));
    if(i == n) return;
    //cout << curSum << " " << curMax << " " << curMin << endl;
    recur(i+1,curSum + a[i].second,max(curMax,a[i].first),min(curMin,a[i].first),choose+1);
    recur(i+1,curSum ,curMax,curMin,choose);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n > 20) return 0;
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
    recur(0,0,-2*1e18,2*1e18,0);
    cout << res;
}

