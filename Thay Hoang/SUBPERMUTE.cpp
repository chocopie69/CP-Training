#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+5;
int t,n,k,a[LIMIT],last[LIMIT];
bool check[LIMIT];
deque<int> dq;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBPERMUTE.INP","r",stdin);
    freopen("SUBPERMUTE.OUT","w",stdout);
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        memset(last,-1,sizeof(last));
        memset(check,false,sizeof(check));
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            last[a[i]] = i;
        }
        for(int i=1;i<=n;i++)
        {
            if(check[a[i]] == true) continue;
            while(!dq.empty() && a[i] < dq.back() && i < last[dq.back()])
            {
                check[dq.back()] = false;
                dq.pop_back();
            }
            dq.push_back(a[i]);
            check[a[i]] = true;
        }
        while(!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << '\n';
    }
}

