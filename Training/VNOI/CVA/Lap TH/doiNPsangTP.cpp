#include <bits/stdc++.h>
#define ll long long
using namespace std;

string n;
int res = 0;

int main()
{
    cin >> n;
    for(int i=0;i<n.length();i++)
    {
        res += pow(2,n.length()-i-1)*int(n[i]-48);
    }
    cout << res;
}
