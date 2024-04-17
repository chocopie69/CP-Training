#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SORTNUM"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;
vector<string> v;

bool isNum(char x)
{
    return int(x) >= 48 && int(x) <= 57;
}

bool cmp(string x, string y)
{
    if(x.size() != y.size())
        return x.size() < y.size();
    return x < y;
}

int main()
{
    init();
    cin >> s;
    int n = s.length();
    s = s + ' ';
    string curNum = "";
    for(char c : s)
    {
        if(isNum(c))
            curNum += c;
        else if(curNum != "")
        {
            v.push_back(curNum);
            //cout << curNum << " ";
            curNum = "";
        }
    }
    sort(v.begin(),v.end(), cmp);
    int i = 0, idx = 0;
    while(i <= n)
    {
        if(isNum(s[i]))
        {
            cout << v[idx];
            idx++;
            while(isNum(s[i]))
                i++;
        }
        else
        {
            cout << s[i];
            i++;
        }
    }
}

