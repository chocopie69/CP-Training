#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m;
string x[SZ], y[SZ], s;

string better(string x, string y)
{
    if(x.size() > y.size()) return x;
    if(y.size() > x.size()) return y;
    if(x > y) return y;
    return x;
}

struct Trie
{
    struct Node
    {
        int child[26];
        bool exist;
        string p;
    } nodes[int(1e6+5)];

    void reset(int id)
    {
        memset(nodes[id].child, -1, sizeof(nodes[id].child));
        nodes[id].exist = false;
        nodes[id].p = "";
    }

    int id;

    Trie()
    {
        id = 0;
        reset(id);
    }

    int newNode()
    {
        id++;
        reset(id);
        return id;
    }

    void add(string s, string old)
    {
        int pos = 0;
        for(char c : s)
        {
            int t = c - 'a';
            if(nodes[pos].child[t] == -1) nodes[pos].child[t] = newNode();
            pos = nodes[pos].child[t];
        }
        nodes[pos].exist = true;
        nodes[pos].p = better(old, nodes[pos].p);
    }
} trie;

string res = "";

void recur(int i, int pos)
{
    if(pos == -1) return;
    if(trie.nodes[pos].exist) res = better(res, trie.nodes[pos].p);
    if(i == s.length())
    {
        return;
    }
    recur(i+1, trie.nodes[pos].child[ s[i] - 'a' ]);
    recur(i+1, pos);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        string cur = x[i];
        sort(all(x[i]));
        //cout << x[i] << " ";
        trie.add(x[i], cur);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        res = "";
        cin >> s;
        sort(all(s));
        recur(0,0);
        cout << (res == "" ? "IMPOSSIBLE" : res) << '\n';
    }
}
