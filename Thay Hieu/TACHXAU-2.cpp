#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using  namespace std;

const int SZ = 2e5+3;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,q;
string s, cur;

struct Node
{
    int child[26];
    bool exist;
};
Node nodes[int(1e6+5)];

int id = 0;

int newNode()
{
    id++;
    memset(nodes[id].child,-1,sizeof(nodes[id].child));
    nodes[id].exist = false;
    return id;
}

void add(string s)
{
    int pos = 0;
    for(char c : s)
    {
        int t = c - 'a';
        if(nodes[pos].child[t] == -1)
        {
            nodes[pos].child[t] = newNode();
        }
        pos = nodes[pos].child[t];
    }
    nodes[pos].exist = true;
}

ll dp[SZ];

int main()
{
    init();
    cin >> n;
    memset(nodes[0].child, -1, sizeof(nodes[0].child));
    nodes[0].exist = false;
    while(n--)
    {
        cin >> s;
        reverse(all(s));
        add(s);
    }
    q = 1;
    while(q--)
    {
        cin >> s;
        n = s.length();
        s = " " + s;
        dp[0] = 1LL;
        for(int i = 1; i <= n; i++)
        {
            int pos = 0;
            for(int j = i; j >= min(1,j-100) ; j--)
            {
                int t = s[j] - 'a';
                if(nodes[pos].child[t] == -1) break;
                pos = nodes[pos].child[t];
                if(nodes[pos].exist)
                {
                    dp[i] = (dp[i] + dp[j-1]) % MOD;
                }
            }
        }
        cout << dp[n];
    }
}


