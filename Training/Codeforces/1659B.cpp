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

int t,n,k,cnt1,cnt0, res[SZ];
string s;
char c;

void flip(int k, int pos)
{
    k %= 2;
    if(k == 0) return;
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == pos) continue;
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        s = " " + s;
        cnt1 = 0;
        cnt0 = 0;
        for(int i = 1; i <= n; i++)
        {
            cnt0 += (s[i] == '0');
            cnt1 += (s[i] == '1');
            res[i] = 0;
        }
        if(n == 1)
        {
            flip(k,1);
            cout << s << '\n' << k << '\n';
            continue;
        }
        if(k % 2 == 0)
        {
            if(cnt0 >= 2)
            {
                cout << "hello" << '\n';
                int pos1 = -1, pos2 = -1;
                for(int i = 1; i <= n; i++)
                {
                    if(pos1 == -1 && s[i] == '0')
                    {
                        pos1 = i;
                        flip(1,i);
                        res[i] = 1;
                        k--;
                    }
                    if(pos1 != -1 && pos2 == -1 && s[i] == '1')
                    {
                        pos2 = i;
                        flip(k,i);
                        res[i] = k;
                    }
                }
            } else if(cnt0 == 0)
            {
                res[1] = k;
            } else
            {
                int pos1 = -1;
                for(int i = 1; i <= n; i++)
                {
                    if(pos1 == -1 && s[i] == '0')
                    {
                        pos1 = i;
                        flip(1,i);
                        res[i] = 1;
                        k--;
                    }
                    if(i == n)
                    {
                        flip(k,i);
                        res[i] += k;
                    }
                }
            }
        }
        cout << s << '\n';
        for(int i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
        cout << '\n';
    }
}

/*
3
6 4
100011
6 0
000000
6 12
001110
*/
