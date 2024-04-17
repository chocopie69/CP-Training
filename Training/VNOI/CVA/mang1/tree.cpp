#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mii map<int,int>
using namespace std;

const int MN = 1002;
int n,k,a[MN],cnt[MN],max1=0,val;

int main()
{
    cin >> n >> k;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i] -= (k*i);
        if(a[i] > 0)
            cnt[a[i]]++;
    }
    for(int i=0;i<MN;i++)
    {
        if(cnt[i] > max1)
        {
            max1 = cnt[i];
            val = i;
        }
    }
    cout << n-max1 << endl;
    for(int i=0;i<n;i++)
    {
        if(a[i] < val)
        {
            cout << "+" << " " << i+1 << " " << val-a[i] << endl;
        }
        else if(a[i] > val)
        {
            cout << "-" << " " << i+1 << " " << a[i]-val << endl;
        }
    }
}

/*
8 4
1 6 0 9 2 15 3 20
*/
