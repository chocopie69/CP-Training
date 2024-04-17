#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,cnt[SZ][2], try1, try2, try3, try4;
char c[SZ][SZ],c2[SZ][SZ];
set<string> s,sB,sC,sD,sE;
vector<string> res,resB,resC,resD,resE;

void reset()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            c[i][j] = c2[i][j];
        }
    }
}

int trySolution1()
{
    for(int j = 1; j <= m; j++)
    {
        if(cnt[j][0] >= n/2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(c[i][j] == '*')
                    c[i][j] = '1';
            }
        } else if(cnt[j][1] >= n/2)
        {
            for(int i = 1; i <= n; i++)
            {
                if(c[i][j] == '*')
                    c[i][j] = '0';
            }
        } else
        {
            char cur = (cnt[j][0] > cnt[j][1] ? '1' : '0');
            for(int i = 1; i <= n; i++)
            {
                if(c[i][j] == '*')
                {
                    c[i][j] = cur;
                    if(cur == '1') cur = '0';
                    else cur = '1';
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        string cur = "";
        for(int j = 1; j <= m; j++)
        {
            cur += c[i][j];
        }
        sB.insert(cur);
        resB.push_back(cur);
    }
    return sB.size();
}

int trySolution2()
{
    char cur2 = (cnt[1][0] > cnt[1][1] ? '1' : '0');
    for(int i = 1; i <= n; i++)
    {
        string cur = "";
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '*')
            {
                c[i][j] = cur2;
            }
            cur += c[i][j];
        }
        if(cur2 == '1') cur2 = '0';
        else cur2 = '1';
        sC.insert(cur);
        resC.push_back(cur);
    }
    return sC.size();
}

int trySolution3()
{
    char cur2 = '0';
    for(int i = 1; i <= n; i++)
    {
        string cur = "";
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '*')
            {
                c[i][j] = cur2;
                if(cur2 == '1') cur2 = '0';
                else cur2 = '1';
            }
            cur += c[i][j];
        }
        sD.insert(cur);
        resD.push_back(cur);
    }
    return sD.size();
}

int trySolution4()
{
    char cur2 = '1';
    for(int i = 1; i <= n; i++)
    {
        string cur = "";
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '*')
            {
                c[i][j] = cur2;
                if(cur2 == '1') cur2 = '0';
                else cur2 = '1';
            }
            cur += c[i][j];
        }
        sE.insert(cur);
        resE.push_back(cur);
    }
    return sE.size();
}


int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            c2[i][j] = c[i][j];
        }
    }
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            cnt[j][0] += int(c[i][j] == '0');
            cnt[j][1] += int(c[i][j] == '1');
        }
    }
    for(int i = 1; i <= n; i++)
    {
        string cur = "";
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '*')
            {
                if(cnt[j][0] >= cnt[j][1]) c[i][j] = '0';
                else c[i][j] = '1';
            }
            cur += c[i][j];
        }
        s.insert(cur);
        res.push_back(cur);
    }
    cout << s.size() << " ";
    for(string cur : res)
    {
        cout << cur << " ";
    }
    cout << '\n';
    reset();
    try1 = trySolution1();
    reset();
    try2 = trySolution2();
    reset();
    try3 = trySolution3();
    reset();
    try4 = trySolution4();
    if(try1 == max({try1,try2,try3,try4}))
    {
        cout << try1 << ' ';
        for(string cur : resB)
        {
            cout << cur << " ";
        }
    } else if(try2 == max({try1,try2,try3,try4}))
    {
        cout << try2 << ' ';
        for(string cur : resC)
        {
            cout << cur << " ";
        }
    } else if(try3 == max({try1,try2,try3,try4}))
    {
        cout << try3 << ' ';
        for(string cur : resD)
        {
            cout << cur << " ";
        }
    } else if(try4 == max({try1,try2,try3,try4}))
    {
        cout << try4 << ' ';
        for(string cur : resE)
        {
            cout << cur << " ";
        }
    }
}

