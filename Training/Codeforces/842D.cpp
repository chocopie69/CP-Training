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

const int LG = 19;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int curXor = 0;

struct Trie
{
    struct Node
    {
        int child[2],cnt;

    };
    //Node nodes[int(6e6)];
    vector<Node> nodes;
    Trie()
    {
        Node node;
        fill(node.child, node.child + 2, -1);
        node.cnt = 0;
        nodes.push_back(node);
    }
    int newNode()
    {
        Node node;
        fill(node.child, node.child + 2, -1);
        node.cnt = 0;
        nodes.push_back(node);
        return (int)nodes.size() - 1;
    }
    void add(int x)
    {
        int pos = 0;
        for(int i = LG; i >= 0; i--)
        {
            int c = (x >> i) & 1;
            if(nodes[pos].child[c] == -1) nodes[pos].child[c] = newNode();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
    }

    int mex()
    {
        int pos = 0, res = 0;
        for(int i = LG; i >= 0; i--)
        {
            int c = (curXor >> i) & 1;
            if(nodes[pos].child[c] != -1 && nodes[nodes[pos].child[c]].cnt == (1 << i))
            {
                pos = nodes[pos].child[c ^ 1];
                res += (1 << i);
            } else
            {
                pos = nodes[pos].child[c];
            }
            if(pos == -1) break;
        }
        return res;
    }
} trie;

int n,q,a[SZ],x;
bool vis[SZ];

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(!vis[a[i]])
        {
            trie.add(a[i]);
            vis[a[i]] = true;
        }
    }
    while(q--)
    {
        cin >> x;
        curXor ^= x;
        cout << trie.mex() << '\n';
    }
}
