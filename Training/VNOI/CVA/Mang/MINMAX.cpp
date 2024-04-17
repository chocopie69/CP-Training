#include <bits/stdc++.h>
using namespace std;

const int maxN = 1002;
int n;
double a[maxN];

int main()
{
    cin >> n;
    double maxNum = -999999999, minNum = 999999999;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        maxNum = max(maxNum,a[i]);
        minNum = min(minNum,a[i]);
    }
    cout << fixed << setprecision(2) << maxNum << " " << minNum;
}
