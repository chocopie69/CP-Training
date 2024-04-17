#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s, res;

bool check(string cur)
{

}

int main()
{
    init();
    cin >> s;
    int n = s.length();
    int L = 0, R = n;
    while(L <= R)
    {
        string cur = s;
        int mid = (L+R)/2;
        for(int i = 1; i <= mid; i++)
        {
            cur += " ";
        }
        if(check(cur))
        {
            R = mid-1;
        }
        else
        {
            L = mid+1;
        }
    }
    cout << L;
}
