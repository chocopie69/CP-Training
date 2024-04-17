#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+5;
int n,a[LIMIT];
stack<int> st;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DELNUM.INP","r",stdin);
    freopen("DELNUM.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int i = 0;
    while(i < n)
    {
        bool flag = false;
        if(st.size() >= 2 && a[i] > st.top())
        {
            int tmp = st.top();
            st.pop();
            if(st.top() <= tmp)
            {
                st.push(tmp);
            }
            else
            {
                i--;
                flag = true;
            }
        }
        if(flag == false)
            st.push(a[i]);
        i++;
    }
    cout << st.size();
}
