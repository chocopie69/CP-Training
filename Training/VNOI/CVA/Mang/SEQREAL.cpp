#include <bits/stdc++.h>
using namespace std;

const int maxN = 102;
int n;
double a[maxN];

int main()
{
    cin >> n;
    double tong1 = 0,tong2 = 0,tong3 = 0,tong4 = 0,tong5 = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        tong1 += a[i];
        if(a[i] < 0) tong2 += a[i];
        if(a[i] > 0) tong3 += a[i];
        if(i % 2 == 0) tong4 += a[i];
        if(i % 2 != 0) tong5 += a[i];
    }
    cout << fixed << setprecision(2) << tong1 << " " << tong2 << " " << tong3 << " " << tong4 << " " << tong5;
}

