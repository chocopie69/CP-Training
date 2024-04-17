#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e7+5;
int n,a[maxN],sum,cnt1,cnt2;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
        if(a[i] % 2 == 0) cnt1++;
        else cnt2++;
    }
    if(sum % 2 == 1)
    {
        cout << cnt1 * cnt2;
    }
    else
    {
        cout << cnt1*(cnt1-1)/2 + cnt2*(cnt2-1)/2;
    }
}
