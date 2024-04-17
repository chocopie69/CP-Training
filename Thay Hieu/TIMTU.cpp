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

int n;

struct Trie
{
    struct Node
    {
        int child[26], cnt;
    } nodes[int(1e6)];

    int id;

    void reset(int id)
    {
        memset(nodes[id].child, -1, sizeof(nodes[id].child));
        nodes[id].cnt = 0;
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
            nodes[pos].cnt++;
        }
    }
} trie;

string s, a[SZ];
map<string,int> mp;

struct Query
{
    string s;
    int pos,id;

    Query(string _s = "", int _pos = 0, int _id = 0) : s(_s), pos(_pos), id(_id) {}

    bool operator < (const Query& other) const
    {
        return pos < other.pos;
    }
};

Query queries[SZ];

ll res[SZ];
vector<int> v;
int q;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()) mp[a[i]] = i;
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        cin >> s;
        queries[i] = { s, (mp.find(s) == mp.end() ? n : mp[s]), i };
    }
    sort(queries + 1, queries + q + 1);
    int j = 1;
    for(int i = 1; i <= q; i++)
    {
        v.clear();
        s = queries[i].s;
        int pos = queries[i].pos, id = queries[i].id;
        //cout << s << " " << pos << " " << id << '\n';
        while(j <= pos)
        {
            trie.add(a[j]);
            j++;
        }
        int p = 0;
        for(char c : s)
        {
            int t = c - 'a';
            if(trie.nodes[p].child[t] == -1) break;
            p = trie.nodes[p].child[t];
            v.push_back(trie.nodes[p].cnt);
            //cout << trie.nodes[p]
        }
        v.push_back(0);
        ll cur = 0;
        for(int i = 0; i < v.size() - 1; i++)
        {
            cur += (i+1) * (v[i] - v[i+1]);
        }
        //cout << cur << " " << pos << '\n';
        res[id] = cur + pos;
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}
