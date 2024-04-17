#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
int n,x;
stack<int> st;
queue<int> qu;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(x % 2 == 0)
        {
            qu.push(x);
        }
        else
        {
            st.push(x);
        }
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    while(!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
}
