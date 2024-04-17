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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Trie
{
    struct Node
    {
        int child[26], cnt;
    };
    Node nodes[int(1e6+5)];

    int id;

    Trie()
    {
        id = 0;
        memset(nodes[id].child,-1,sizeof(nodes[id].child));
        nodes[id].cnt = 0;
    }

    int newNode()
    {
        id++;
        memset(nodes[id].child,-1,sizeof(nodes[id].child));
        nodes[id].cnt = 0;
        return id;
    }

    void add(string s)
    {
        int pos = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if(nodes[pos].child[c] == -1) nodes[pos].child[c] = newNode();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
    }

    int query(string s)
    {
        int pos = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if(nodes[pos].child[c] == -1) return 0;
            pos = nodes[pos].child[c];
        }
        return nodes[pos].cnt;
    }

} trie;

string s;
int n,q;

int main()
{
    init();
    cin >> n >> q;
    while(n--)
    {
        cin >> s;
        trie.add(s);
    }
    while(q--)
    {
        cin >> s;
        cout << trie.query(s) << '\n';
    }
}
