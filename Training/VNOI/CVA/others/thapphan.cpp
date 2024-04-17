#include <bits/stdc++.h>
using namespace std;

const int maxArr = 1e6;
int m,n,pos[maxArr],du,len,thuong;
string res = "";

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}

int main()
{
    //freopen("Thapphan.inp","r",stdin); freopen("Thapphan.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(pos,0,sizeof(pos));

    cin >> m >> n;
    du = m % n, thuong = m / n;
    if(du == 0)
    {
        cout << thuong;
        return 0;
    }
    res += toString(thuong) + ",";
    len = res.length();
    while(du != 0)
    {
        du *= 10;
        if(pos[du] == 0)
        {
            thuong = du/n;
            pos[du] = len;
            len++;
            res += toString(thuong);
            du = du % n;
        }
        else
        {
            res.insert(pos[du],"(");
            res += ")";
            break;
        }
    }
    cout << res;
}
