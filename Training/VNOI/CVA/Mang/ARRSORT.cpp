#include <bits/stdc++.h>
using namespace std;

const int maxN = 1002;
int n;
double a[maxN];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) cout << fixed << setprecision(2) << a[i] << " ";
    cout << endl;
    sort(a+1,a+n+1,greater<double>());
    for(int i=1;i<=n;i++) cout << fixed << setprecision(2) << a[i] << " ";
}

