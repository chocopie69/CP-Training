#include <bits/stdc++.h>
using namespace std;

int n,a;
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> a;
        pq.push(a);
    }
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
