#include <bits/stdc++.h>
using namespace std;

int m[125];

bool check()
{
    bool flag = true;
    for(int i=0;i<=122;i++) if(m[i]) flag = false;
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(m,0,sizeof(m));
    int g,g1,res=0;
    cin >> g >> g1;
    string w,s;
    cin >> w >> s;
    for(int i=0;i<g;i++) m[int(w[i])]++,m[int(s[i])]--;
    bool flag = false;
    for(int i=0;i<=122;i++) if(m[i]) flag = true;
    if(flag == false) res++;
    for(int i=g;i<g1;i++)
    {
        m[int(s[i])]--;
        m[int(s[i-g])]++;
        if(check()) res++;
    }
    cout << res;
}
