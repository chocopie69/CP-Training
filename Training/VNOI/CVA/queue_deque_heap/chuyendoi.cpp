#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e4+2;
int n,k;
queue<int> a;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> n >> k;
    k %= n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    while(k--)
    {
        a.push(a.front());
        a.pop();
    }
    while(!a.empty())
    {
        cout << a.front() << " ";
        a.pop();
    }
}
