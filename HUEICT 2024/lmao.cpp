#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll k;
string s;
vector<pll> vec, st;

void solveMax(ll x)
{
    st.clear();
    for(pll p : vec)
    {
        while(!st.empty() && p.fi > st.back().fi && x > 0)
        {
            pll cur = st.back();
            if(x >= cur.se)
            {
                x -= cur.se;
                st.pop_back();
            } else
            {
                st.back().se -= x;
                x = 0;
            }
        }
        st.pb(p);
    }
    while(!st.empty() && x > 0)
    {
        if(x >= st.back().se)
        {
            x -= st.back().se;
            st.pop_back();
        } else
        {
            st.back().se -= x;
            x = 0;
        }
    }
    for(int i = 1; i < st.size(); i++)
    {
        if(st[i].fi == st[i-1].fi)
        {
            st[i].se += st[i-1].se;
            st[i-1].se = 0;
        }
    }
    for(pll p : st)
    {
        if(p.se == 0) continue;
        cout << char(p.fi + 'a') << p.se;
    }
}

void solveMin(ll x)
{
    st.clear();
    for(pll p : vec)
    {
        while(!st.empty() && p.fi < st.back().fi && x > 0)
        {
            pll cur = st.back();
            if(x >= cur.se)
            {
                x -= cur.se;
                st.pop_back();
            } else
            {
                st.back().se -= x;
                x = 0;
            }
        }
        st.pb(p);
    }
    while(!st.empty() && x > 0)
    {
        if(x >= st.back().se)
        {
            x -= st.back().se;
            st.pop_back();
        } else
        {
            st.back().se -= x;
            x = 0;
        }
    }
    for(int i = 1; i < st.size(); i++)
    {
        if(st[i].fi == st[i-1].fi)
        {
            st[i].se += st[i-1].se;
            st[i-1].se = 0;
        }
    }
    for(pll p : st)
    {
        if(p.se == 0) continue;
        cout << char(p.fi + 'a') << p.se;
    }
}

int main()
{
    init();
    cin >> k >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            ll cur = 0, j = i+1;
            while(j < s.length() && s[j] >= '0' && s[j] <= '9')
            {
                cur = cur*10 + (s[j] - '0');
                j++;
            }
            vec.pb({ s[i] - 'a', cur });
        }
    }
//    for(pll p : vec)
//    {
//        cout << char(p.fi + 'a') << " " << p.se << '\n';
//    }
    solveMax(k);
    cout << '\n';
    solveMin(k);
}

/*
2
a1d3e2d5
*/

