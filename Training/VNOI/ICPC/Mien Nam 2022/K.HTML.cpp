#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int cr,cg,cb;

struct color
{
    string name;
    int r,g,b;
    color(int _r, int _g, int _b, string _name)
    {
        r=_r,g=_g,b=_b;
        name = _name;
    }
    double dist()
    {
        return sqrt(pow(cr-r,2) + pow(cg-g,2) + pow(cb-b,2));
    }
};
color c[16] = { {255,255,255,"White"}, {192,192,192,"Silver"} , {128,128,128,"Gray"},{0,0,0,"Black"},{255,0,0,"Red"},{128,0,0,"Maroon"},
    {255,255,0,"Yellow"},{128,128,0,"Olive"},{0,255,0,"Lime"},{0,128,0,"Green"},{0,255,255,"Aqua"},{0,128,128,"Teal"},{0,0,255,"Blue"},
    {0,0,128,"Navy"},{255,0,255,"Fuchsia"},{128,0,128,"Purple"} };


string res;

void solve()
{
    double minDist = (double)INT_MAX;
    for
    for(int i=0;i<16;i++)
    {
        double curDist = c[i].dist();
        if(curDist < minDist)
        {
            minDist = curDist;
            res = c[i].name;
        }
    }
    cout << res << endl;
}

int main()
{
    while(cin >> cr >> cg >> cb)
    {
        if(cr == -1) break;
        solve();
    }
}
