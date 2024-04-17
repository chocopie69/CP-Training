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

int n,q;
string s;

struct Trie
{
    struct Node
    {
        int child[26], cnt, exist;
    } nodes[int(5e6+5)];

    int id;

    void reset(int id)
    {
        memset(nodes[id].child,-1,sizeof(nodes[id].child));
        nodes[id].cnt = 0;
        nodes[id].exist = 0;
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
        for(int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if(nodes[pos].child[c] == -1) nodes[pos].child[c] = newNode();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    pair<string,int> query(string s)
    {
        int pos = 0;
        string res = "";
        for(int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if(nodes[pos].child[c] == -1) return {"",-1};
            pos = nodes[pos].child[c];
        }
        res = s;
        while(true)
        {
            int mx = 0, bestC;
            for(char i = 'a'; i <= 'z'; i++)
            {
                int c = i - 'a';
                if(nodes[pos].child[c] != -1 && nodes[nodes[pos].child[c]].cnt > mx)
                {
                    mx = nodes[nodes[pos].child[c]].cnt;
                    bestC = c;
                }
            }
            if(mx == 0 || nodes[pos].exist == mx)
            {
                return {res + " ", nodes[pos].exist };
                break;
            } else
            {
                res += char(bestC + 'a');
                pos = nodes[pos].child[bestC];
            }
        }
    }
} trie;

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> s;
        trie.add(s);
    }
    cin >> q;
    while(q--)
    {
        cin >> s;
        pair<string,int> res = trie.query(s);
        cout << res.fi << res.se << '\n';
    }
}
