#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,n;
string s;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        int startPos = 0, endPos = s.size()-1;
        while(s[startPos] != s[endPos] && startPos < endPos)
        {
            startPos++;
            endPos--;
        }
        cout << endPos-startPos+1 << '\n';
    }
}

