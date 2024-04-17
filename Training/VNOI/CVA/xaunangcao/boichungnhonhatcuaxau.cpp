#include <bits/stdc++.h>
using namespace std;

int lcd(int a,int b)
{
    return a*b/__gcd(a,b);
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        bool flag = false;
        string s,t;
        cin >> s >> t;
        int lcdLength = lcd(s.length(),t.length());
        int uoc1 = lcdLength / s.length(), uoc2 = lcdLength / t.length();
        string s1=s,t1 = t;
        for(int i=1;i<uoc1;i++) s+=s1;
        for(int i=1;i<uoc2;i++) t+=t1;
        if(s == t) cout << s;
        else cout << -1;
        cout << '\n';
    }
}
