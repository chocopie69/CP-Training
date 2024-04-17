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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int LG = 18;

struct Trie
{
    struct Node
    {
        int child[2],mn;
    };

    Node nodes[int(2e7)];
    int root[SZ], id;

    Trie()
    {
        id = 0;
        memset(root,-1,sizeof(root));
    }

    void reset(int id)
    {
        memset(nodes[id].child,-1,sizeof(nodes[id].child));
        nodes[id].mn = INF;
    }

    int newTree(int k)
    {
        id++;
        root[k] = id;
        reset(id);
        return id;
    }

    int newNode()
    {
        id++;
        reset(id);
        return id;
    }

    void add(int x, int k)
    {
        int pos;
        if(root[k] == -1) pos = newTree(k);
        else pos = root[k];
        for(int i = LG; i >= 0; i--)
        {
            int c = (x >> i) & 1;
            if(nodes[pos].child[c] == -1) nodes[pos].child[c] = newNode();
            pos = nodes[pos].child[c];
            nodes[pos].mn = min(nodes[pos].mn,x);
        }
    }

    int query(int x, int k, int mn)
    {
        int res = 0;
        if(root[k] == -1) return -1;
        int pos = root[k];
        for(int i = LG; i >= 0; i--)
        {
            int c = (x >> i) & 1;
            if(nodes[pos].child[c ^ 1] != -1 && nodes[nodes[pos].child[c ^ 1]].mn <= mn)
            {
                pos = nodes[pos].child[c ^ 1];
                res += ( (c ^ 1) << i );
            } else if(nodes[pos].child[c] != -1 && nodes[nodes[pos].child[c]].mn <= mn)
            {
                pos = nodes[pos].child[c];
                res += ( c << i );
            } else return -1;
        }
        return res;
    }

} trie;

vector<int> uoc[SZ];

void preCompute()
{
    for(int i = 1; i < SZ; i++)
    {
        for(int j = i; j < SZ; j += i)
        {
            uoc[j].push_back(i);
        }
    }
}

int q, type, u, x, k, s;

int main()
{
    init();
    preCompute();
    cin >> q;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> u;
            for(int k : uoc[u]) trie.add(u,k);
        } else
        {
            cin >> x >> k >> s;
            if(x % k != 0)
            {
                cout << "-1\n";
            } else
            {
                cout << trie.query(x,k,s-x) << '\n';
            }
        }
    }
}
