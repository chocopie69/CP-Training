#include <bits/stdc++.h>
using namespace std;

string s,res="";

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}

string convert(string x)
{
    int len = x.length(),res=0;
    for(int i=0;i<len;i++)
    {
        res += pow(2,len-i-1)*(x[i]-'0');
    }
    return toString(res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BINTOCT.INP","r",stdin); freopen("BINTOCT.OUT","w",stdout);

    cin >> s;
    while(s.length() % 3 != 0) s = "0" + s;
    for(int i=0;i<s.length();i+=3)
    {
        string subS = s.substr(i,3);
        res += convert(subS);
    }
    cout << res;
}
