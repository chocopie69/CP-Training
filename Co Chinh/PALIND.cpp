#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PALIND"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;

int main()
{
    init();
    cin >> s;
    int n = s.length();
    bool flag = false;
    string s1 = s;
    for(int i = 0; i <= n/2-1; i++)
    {
        s[n-i-1] = s[i];
    }
    if(s < s1)
    {
        int i,j;
        if(n % 2 == 0)
        {
            i = n/2-1;
            j = n/2;
        }
        else
        {
            i = n/2;
            j = n/2;
        }
        while(s[i] == '9')
        {
            s[i] = '0';
            s[j] = '0';
            j++;
            i--;
        }
        s[i] = char(int(s[i]) + 1);
        s[j] = s[i];
    }
    cout << s;
}

