#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+5;
int n,a[LIMIT];
stack<int> st;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LINEUP.INP","r",stdin);
    freopen("LINEUP.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[i] >= a[st.top()])
        {
            st.pop();
        }
        cout << (st.empty() ? -1 : st.top()) << " ";
        st.push(i);
    }
}
