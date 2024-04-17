#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 2e6+5, LG = 33;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, a[SZ];

struct Trie
{
    struct Node
    {
        int child[2];
    } nodes[signed(4e6)];

    int id;

    void reset(int id)
    {
        memset(nodes[id].child,-1,sizeof(nodes[id].child));
    }

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

    void add(int x)
    {
        int pos = 0;
        for(int i = LG; i >= 0; i--)
        {
            int t = (x >> i & 1LL);
            if(nodes[pos].child[t] == -1) nodes[pos].child[t] = newNode();
            pos = nodes[pos].child[t];
        }
    }
} trie;

int res = 0;

signed main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int pos = 0, sum = 0;
        for(int k = LG; k >= 0; k--)
        {
            int t = (x >> k & 1LL);
            if(trie.nodes[pos].child[t ^ 1] != -1)
            {
                pos = trie.nodes[pos].child[t ^ 1];
                sum += (1LL << k);
            } else if(trie.nodes[pos].child[t] != -1)
            {
                pos = trie.nodes[pos].child[t];
            } else break;
        }
        res = max(res, sum);
        trie.add(x);
    }
    cout << res;
}
