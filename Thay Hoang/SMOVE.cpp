#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct line
{
    long double a,b,c;
};

long double xa,ya,xb,yb,xm,ym,xn,yn1;
long double res = 0;
line mn,ab;

void init()
{
    freopen("SMOVE.INP","r",stdin);
    freopen("SMOVE.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void createLine()
{
    mn.a = ym - yn1;
    mn.b = xn - xm;
    mn.c = xm*yn1-xn*ym;
    ab.a = ya - yb;
    ab.b = xb - xa;
    ab.c = xa*yb-xb*ya;
}

long double calcLine(line l,long double x,long double y)
{
    return l.a*x + l.b*y + l.c;
}

long double calcDist(long double x1,long double x2, long double y1, long double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    init();
    cin >> xa >> ya >> xb >> yb >> xm >> ym >> xn >> yn1;
    createLine();
    if(calcLine(mn,xa,ya)*calcLine(mn,xb,yb) < 0 && calcLine(ab,xm,ym)*calcLine(ab,xn,yn1) < 0)
    {
        long double dist1 = calcDist(xm,xa,ym,ya) + calcDist(xa,xn,ya,yn1);
        long double dist2 = calcDist(xm,xb,ym,yb) + calcDist(xb,xn,yb,yn1);
        cout << fixed << setprecision(4) << min(dist1,dist2);
    }
    else
    {
        cout << fixed << setprecision(4) << calcDist(xm,xn,ym,yn1);
    }
}
