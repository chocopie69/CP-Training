#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Action
{
    char type, c;
    int pos;
    Action(char _type, int _pos, char _c)
    {
        type = _type;
        pos = _pos;
        c = _c;
    }
};

string x,y;
int dp[LIMIT][LIMIT], cnt = 0;
vector<Action> res;

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}


void recur(int i, int j)
{
    if(i == 0 && j == 0) return;
    if(i == 0)
    {
        recur(i,j-1);
        res.push_back({'I',1,y[j]});
    }
    else if(j == 0)
    {
        recur(i-1,j);
        res.push_back({'D',i,' '});
    }
    else if(x[i] == y[j])
    {
        recur(i-1,j-1);
    }
    else if(dp[i][j] == dp[i-1][j] + 1)
    {
        recur(i-1,j);
        res.push_back({'D',i,' '});
    }
    else if(dp[i][j] == dp[i][j-1] + 1)
    {
        recur(i,j-1);
        res.push_back({ 'I', i+1, y[j] });
    }
    else
    {
        recur(i-1,j-1);
        res.push_back({ 'R',i, y[j] });
    }
}


int main()
{
    init();
    cin >> x >> y;
    int n = x.length(), m = y.length();
    x = ' ' + x;
    y = ' ' + y;
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i] == y[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }
    cout << dp[n][m] << '\n';
    recur(n,m);
    for(Action a : res)
    {
        cout << a.type << " " << a.pos - cnt << " ";
        if(a.type != 'D')
            cout << a.c;
        if(a.type == 'D')
            cnt++;
        else if(a.type == 'I')
            cnt--;
        cout << '\n';
    }
}

/*
anfgowpndffdgdobs
anfgowpndffdgdobs
*/
