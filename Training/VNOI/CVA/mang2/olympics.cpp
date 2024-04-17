#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 1e5+5;
int n,m,a[MN],gold[MN],silver[MN],bronze[MN];

int main()
{
    cin >> n >> m;
    gold[0] = 0;
    silver[0] = 0;
    bronze[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        gold[i] = gold[i-1] + (a[i] == 1);
        silver[i] = silver[i-1] + (a[i] == 2);
        bronze[i] = bronze[i-1] + (a[i] == 3);
    }
    int l,r;
    while(m--)
    {
        cin >> l >> r;
        cout << gold[r] - gold[l-1] << " " << silver[r] - silver[l-1] << " " << bronze[r] - bronze[l-1] << endl;
    }
}
