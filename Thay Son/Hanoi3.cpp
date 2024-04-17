#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e3+5,END = 1e6;
int n,k,a[LIMIT],res=0;

bool check(int range)
{
    int cnt = 0, curRange=0;
    for(int i=0;i<n;i++)
    {
        curRange = a[i];
        for(int j=i;j<n;j++)
        {
            if(curRange + range >= a[j])
            {
                curRange += range;
            }
            else
            {

            }
        }
    }
}

void binarySearch()
{
    int left = 1,right = END,mid;
    while(left <= right)
    {
        mid = (left+right)/2;
        if(check(mid))
        {
            res = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
}

void init()
{
    ios_base::sync_with_stdio(0);
}

int main()
{
    init();
    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cin >> k;
    sort(a,a+n);
    a[n] = a[0] + END;
    binarySearch();
    cout << res;
}
