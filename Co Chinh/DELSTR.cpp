#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DELSTR"

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

int k, cnt[LIMIT];
string s;
vector<char> v;

int main()
{
    init();
    cin >> k >> s;
    int n = s.length();
    cnt[0] = 1;
    s += '0';
    for(int i = 0; i < n; i++)
    {
        v.push_back(s[i]);
        if(s[i] == s[i+1])
        {
            cnt[i+1] = cnt[i]+1;
        } else
        {
            int cur = cnt[i]/k;
            if(cur == 0)
            {
                cnt[i+1] = 1;
                continue;
            }
            for(int j = i-(cur*k)+1; j <= i;j++)
            {
                v.pop_back();
                cnt[j] = cnt[j-1];
            }
            if(s[i+1] == v.back())
                cnt[i+1] = cnt[i]+1;
            else
                cnt[i+1] = 1;
        }
    }
    if(v.empty())
    {
        cout << 0;
        return 0;
    }
    for(char c : v)
    {
        cout << c;
    }
}

