#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+5;
int n,a[LIMIT],res=0,cnt=0;
bool watered[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WATERING.INP","r",stdin);
    freopen("WATERING.OUT","w",stdout);
    memset(watered,false,sizeof(watered));
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        if(cnt == 0 || x != a[cnt])
        {
            cnt++;
            a[cnt] = x;
        }
    }
    watered[0] = false;
    a[0] = 0;
    for(int i=1;i<=cnt;i++)
    {
        if(a[i] <= a[i-1])
        {
            if(watered[i-1])
            {
                watered[i] = true;
            }
            else
            {
                res++;
                //cout << i-1 << " ";
                watered[i-1] = true;
                watered[i] = true;
            }
        }
        else
        {
            if(i == cnt) {
                res++;
                //cout << i << " ";
                watered[i] = true;
            }
        }
    }
    cout << res;
}

/*
10
7 5 2 1 3 10 29 6 12 4
*/
