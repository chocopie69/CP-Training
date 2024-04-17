#include <bits/stdc++.h>
#define ll long long
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

int t,n,m;
string s;
int x;

string chiasl(string a, int b)
    {
        string c = "";
        int du = 0;
        for(int i = 0; i < a.size(); i++)
        {
            du = du*10 + int(a[i] - '0');
            if(du != 1)
            {
                c.push_back(char(du/b + '0'));
                du %= b;
            }
        }
        while(c[0] == '0') c.erase(0, 1);
        return c;
    }

namespace even
{
    void solve()
    {
        string ans = chiasl(s, 2);
        cout << ans << ' ' << ans <<'\n';
    }
}

namespace odd
{
    bool flag = false;

    void try1(string a, string b)
    {
        //cout << a << " " << b << " try1" << '\n';
        char c = b[m-2];
        if(c == '0') return;
        b[m-2] = char(int(c) - 1);
        if(m == 0 && b[m-2] == '0') b.erase(0,1);
        if(max(int(a[n-1]) - 48, int(b[m-1]) - 48) > 9-5) return;
        a[n-1] = char(int(a[n-1]) + 5);
        b[m-1] = char(int(b[m-1]) + 5);
        cout << a << " " << b << '\n';
        flag = true;
    }

    void try2(string a, string b)
    {
        //cout << a << " " << b << " try2" << '\n';
        char c = a[n-2];
        if(c == '9') return;
        a[n-2] = char(int(c) + 1);
        if(min(int(a[n-1]) - 48, int(b[m-1]) - 48) < 5) return;
        a[n-1] = char(int(a[n-1]) - 5);
        b[m-1] = char(int(b[m-1]) - 5);
        cout << a << " " << b << '\n';
        flag = true;
    }

    void solve()
    {
        flag = false;
        s[s.length()-1] = char(int(s[s.length() - 1]) - 1);
        string a = chiasl(s,2), b = chiasl(s,2);
        n = a.length();
        m = b.length();
        char c = b[m - 1];
        if(c == '9')
        {
            cout << -1 << '\n';
            return;
        }
        b[m-1] = char(int(c) + 1);
        try1(a,b);
        if(flag) return;
        try2(a,b);
        if(!flag)
        {
            cout << -1 << '\n';
            return;
        }
    }
}

namespace trau
{
    int tongcs(int h)
    {
        int sum = 0;
        while(h > 0)
        {
            sum += (h % 10);
            h /= 10;
        }
        return sum;
    }
    void solve()
    {
        bool flag = false;
            for(int a = 1; a < x; a++)
            {
                int b = x-a;
                if(tongcs(a) == tongcs(b))
                {
                    cout << a << " " << b << '\n';
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                cout << -1 << '\n';
            }
    }
}
namespace stupid
{
    void solve()
    {
        string a = "";
        string b = "";
        int du = 0;
        for(auto i: s)
        {
            int cur = int(s[i] - '0') + du;
            if(cur % 2 == 0)
            {
                a = a + s[i];
                b = b + s[i];
            } else
            {
                du = 1;

            }
        }
    }
}
int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s.size() <= 6)
        {
            x = stoi(s);
            trau::solve();
        } else if(int(s[s.length()-1]) % 2 == 0)
        {
            even::solve();
        } else
        {
            odd::solve();
        }
    }
}
