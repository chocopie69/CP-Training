#include <bits/stdc++.h>
using namespace std;

int x;
vector<int> a;

int main()
{
    while(cin >> x)
    {
        a.push_back(x);
    }
    cout << a[ int(a.size())/2 ];
}
