#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 5e5+5;
int m,n;
ll a[LIMIT],res=1;
stack<int> st;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RECT.INP","r",stdin);
    freopen("RECT.OUT","w",stdout);
}

int main()
{
    //init();
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if
        res = max(res,1LL*(i-st.top())*a[i]);
        st.push(i);
    }
    cout << res;
}
