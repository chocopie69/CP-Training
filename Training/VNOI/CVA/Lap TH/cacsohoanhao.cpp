#include <bits/stdc++.h>
using namespace std;


int n1,n2,ans[4] = {6,28,496,8128};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n1 >> n2;
    for(int i=0;i<4;i++)
    {
        if(ans[i] >= n1 && ans[i] <= n2) cout << ans[i] << " ";
    }
}
