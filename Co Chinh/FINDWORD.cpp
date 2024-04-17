#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "FINDWORD"

using namespace std;

const int SZ = 1e3+5, SZ2 = 28;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s, cur;
int a[SZ][SZ2], start=1;
string s1[SZ];
ll mul[SZ], x, cnt = 0;
queue<char> res;

int main()
{
    init();
    cin >> s;
    for(char c : s)
    {
        if(c == '#') cnt++;
    }
    mul[0] = 1;
    bool flag = false;
    for(int i = 1; i <= cnt; i++)
    {
        int j = 0;
        cin >> cur;
        s1[i] = cur;
        for(char c : cur)
        {
            j++;
            a[i][j] = int(c);
        }
        sort(a[i] + 1, a[i] + cur.length() + 1);
        //mul[i] = mul[i-1]*cur.length();
    }
    while(cin >> cur)
    {
        if(int(cur[0]) >= 48 && int(cur[0]) <= 57)
        {
            x = stoll(cur);
        }
    }
    //cin >> x;
    ll curMul = 1;
    for(int i = cnt; i >= 1; i--)
    {
        if(curMul > x / s1[i].length())
        {
            start = i;
            //cout << curMul << " " << x << " " << start << '\n';
            break;
        } else
        {
            //cout << curMul << " " << s1[i].length() << '\n';
            curMul *= s1[i].length();
        }
        //cout << curMul << " a" << '\n';
    }
    for(int i = 1; i < start; i++)
    {
        res.push(char(a[i][1]));
    }
    mul[start] = 1;
    for(int i = start+1; i <= cnt; i++)
    {
        mul[i] = mul[i-1] * s1[i].length();
    }
    //cout << x << '\n';
    for(int i = start; i <= cnt; i++)
    {
        //int cur = 0;
        int cur = x / (mul[cnt] / mul[i]) - (x % (mul[cnt] / mul[i]) == 0);
        res.push(char(a[i][cur+1]));
        //cout << i << " " << cur << " " << a[i][cur+1] << '\n';
        //cout << i << " " << cur << " " << x << " " << mul[cnt]/mul[i] << " " << (x % (mul[cnt] / mul[i]) == 0) << '\n';
        x -= (mul[cnt] / mul[i] ) * cur;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '#')
        {
            s[i] = res.front();
            res.pop();
        }
    }
    //cout << start << " " << s1[start][0] << " " << s;
    cout << s;
}

