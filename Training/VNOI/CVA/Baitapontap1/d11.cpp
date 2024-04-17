#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m,res=0;
    cin >> m;
    int menhgia[8] = {500,200,100,50,20,10,5,1};
    for(int i=0;i<8;i++)
    {
        if(m >= menhgia[i])
        {
            res += m/menhgia[i];
            m = m % menhgia[i];
        }
        if(m == 0) break;
    }
    cout << res;
}
