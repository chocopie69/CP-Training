#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
int n,k,a[LIMIT];
deque<int> dq;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        while(!dq.empty() && a[dq.back()] >= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(dq.front() + k <= i) dq.pop_front();
        if(i >= k-1) cout << a[dq.front()] << '\n';
    }
}
