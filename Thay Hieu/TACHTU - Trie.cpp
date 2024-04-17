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

const int SZ = 5e2+3;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,q, trace[SZ];
string s, cur;
bool valid[SZ], space[SZ];

struct Trie
{
    struct Node
    {
        int child[26];
        bool exist;
    };
    Node nodes[int(2e5+5)];

    int id;

    Trie()
    {
        id = 0;
        memset(nodes[id].child,-1,sizeof(nodes[id].child));
        nodes[id].exist = false;
    }

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

} trie;

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> s;
        reverse(all(s));
        trie.add(s);
    }
    cin >> q;
    while(q--)
    {
        cin >> s;
        n = s.length();
        s = " " + s;
        memset(valid,false,sizeof(valid));
        memset(space,false,sizeof(space));
        valid[0] = true;
        for(int i = 1; i <= n; i++)
        {
            int pos = 0;
            for(int j = i; j >= 1; j--)
            {
                int t = s[j] - 'a';
                if(trie.nodes[pos].child[t] == -1) break;
                pos = trie.nodes[pos].child[t];
                if(trie.nodes[pos].exist && valid[j-1])
                {
                    trace[i] = j-1;
                    valid[i] = true;
                    break;
                }
            }
        }
        if(valid[n])
        {
            int i = n;
            while(i != 0)
            {
                space[i] = true;
                i = trace[i];
            }
            for(int i = 1; i <= n; i++)
            {
                cout << s[i];
                if(space[i]) cout << " ";
            }
            cout << '\n';
        } else
        {
            cout << -1 << '\n';
        }
    }
}
