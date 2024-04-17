#include <bits/stdc++.h>
using namespace std;

char type;
int v;
priority_queue<int> pq;

int main()
{
    while(cin >> type)
    {
        if(type == '+')
        {
            cin >> v;
            pq.push(v);
        }
        else if(!pq.empty())
        {
            int top = pq.top();
            while(!pq.empty() && top == pq.top())
            {
                pq.pop();
            }
        }
    }
    cout << pq.size() << '\n';
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

