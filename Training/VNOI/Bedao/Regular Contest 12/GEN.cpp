#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3+2;
int n,maxLen=0,maxNum = -INT_MAX,res1,len;
string a[maxN];

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        maxNum = max(maxNum,stoi(a[i]));
        maxLen = max(maxLen,int(a[i].length()));
    }
    int cur = pow(10,maxLen-1);
    res1 = max(maxNum,cur);
    len = toString(res1).length();
    cout << res1 << '\n';
    for(int i=0;i<len;i++) cout << 9;
}
