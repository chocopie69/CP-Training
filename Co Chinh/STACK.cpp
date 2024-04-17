#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "STACK"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, a[SZ];
multiset<int> ms;
stack<int> st;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
    }
    //cout << *ms.begin();
    int i = 1;
    while(!st.empty() || !ms.empty())
    {
        if(st.empty() || (!ms.empty() && st.top() > *ms.begin()))
        {
            //cout << *ms.begin() << " ";
            while(a[i] != *ms.begin())
            {
                st.push(a[i]);
                ms.erase(ms.lower_bound(a[i]));
                //cout << i << " ";
                i++;
            }
            cout << a[i] << " ";
            ms.erase(ms.lower_bound(a[i]));
            i++;
        } else
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
}

/*
11
10 12 21 1 3 8 3 9 7 8 6
*/
