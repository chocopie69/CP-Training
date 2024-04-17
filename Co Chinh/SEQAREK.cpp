#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SEQAREK"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,k,a[LIMIT],b[LIMIT], res = 1;
deque<int> dqMin,dqMax;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int left = 2, right = n;
    while(left <= right)
    {
        bool flag = false;
        while(!dqMin.empty()) dqMin.pop_front();
        while(!dqMax.empty()) dqMax.pop_front();
        int mid = (left + right) / 2;
        for(int i = 1; i <= n; i++)
        {
            while(!dqMin.empty() && a[dqMin.back()] >= a[i])
                dqMin.pop_back();
            dqMin.push_back(i);
            if(dqMin.front() + mid <= i)
                dqMin.pop_front();
            while(!dqMax.empty() && a[dqMax.back()] <= a[i])
                dqMax.pop_back();
            dqMax.push_back(i);
            if(dqMax.front() + mid <= i)
                dqMax.pop_front();
            if(i >= mid && a[dqMax.front()] - a[dqMin.front()] <= k)
                flag = true;
        }
        if(flag)
        {
            res = mid;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    cout << res;
}


