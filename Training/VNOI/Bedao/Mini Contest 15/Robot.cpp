#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int n,res=0;
string s;

int main()
{
    cin >> n >> s;
    if(n % 2 != 0)
    {
        cout << -1;
        return 0;
    }
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'L') cnt1++;
        else if(s[i] == 'R') cnt2++;
        else if(s[i] == 'U') cnt3++;
        else cnt4++;
    }
    int a = max(cnt1,cnt2), b = min(cnt1,cnt2),mid = (cnt1+cnt2)/2;
    res += mid-b;
    b = mid;
    a -= res;
    int c = max(cnt3,cnt4), d = min(cnt3,cnt4);
    c -= (a-b);
    res += (a-b);
    int mid2 = (cnt3+cnt4)/2;
    res += mid2-d;
    cout << res;
}
