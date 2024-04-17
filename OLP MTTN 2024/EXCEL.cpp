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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m,a[SZ][SZ];
pii x[SZ];

int get(char ca, char cb)
{
    int x = ca - 'A' + 1, y = cb - '0';
    //cout << "get " << ca << " " << cb << " " << x << " " << y << '\n';
    return a[y][x];
}

vector<int> vec1, vec2;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    string s;
    int q;
    cin >> q;
    while(q--)
    {
        cin >> s;
        vec1.clear();
        vec2.clear();
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                if(s[i-1] == 'M')
                    vec1.pb(0);
                else if(s[i-1] == 'X')
                    vec1.pb(1);
            } else if(s[i-1] >= 'A' && s[i-1] <= 'Z' && s[i] >= '1' && s[i] <= '9')
            {
                vec2.pb(get(s[i-1], s[i]));
                //cout << get(s[i-1], s[i]) << " " << i << '\n';
            } else if(s[i] == ')')
            {
                if(vec1.back() == 0)
                {
                    vec1.pop_back();
                    int cur1 = vec2.back(), cur2 = vec2[vec2.size()-2];
                    vec2.pop_back();
                    vec2.pop_back();
                    vec2.pb(cur1 + cur2);
                } else
                {
                    vec1.pop_back();
                    int cur1 = vec2.back(), cur2 = vec2[vec2.size()-2];
                    vec2.pop_back();
                    vec2.pop_back();
                    vec2.pb(max(cur1,cur2));
                }
            }
        }
        cout << vec2[0] << '\n';
    }
}

/*
9 26
1 2 3 4 5 6 7 8 9 10 11 12 13 1232 15 16 17 18 19 20 21 22 23 24 25 26
1 2 3 4 5 6 7 3213 9 10 11 12 1232 14 15 16 17 18 19 20 231 22 23 24 25 26
1 2 3 4 5 6 7 28 39 10 11 312 132 14 15 16 17 18 19 20 21 22 23 24 25 2231
1132 2 3 234 5 6 7 28 39 120 11 3212 132 14 15 16 17 18 19 220 21 22 23 24 25 2231
1 2 53 4 5 26 7 3213 9 10 11 12 1232 14 15 16 17 18 19 20 2312 22 23 24 25 26
1 2 3 4 5 36 7 28 39 10 11 3112 132 14 125 16 17 18 19 20 21 22 23 242 25 2231
1132 2 3 234 5 6 7 28 39 120 11 3212 132 14 15 16 17 118 19 220 21 22 23 24 25 2231
1 2 3 4 5 6 7 3213 9 103 11 12 1232 14 15 16 17 18 19 20 231 22 23 24 25 26
1 2 3 42 5 6 7 28 39 10 11 312 132 14 15 16 17 18 19 20 21 22 23 24 25 2231
5
SUM(Z1,MAX(A1,B1))
SUM(MAX(SUM(A1,MAX(SUM(E1,G2),X1)),MAX(B1,C1)),MAX(A3,D1))
MAX(SUM(G3,X3),SUM(H3,MAX(J3,K2)))
SUM(MAX(A2,B1),B3)
SUM(MAX(J3,MAX(SUM(G2,X3),H3)),MAX(SUM(X8,MAX(A7,G3)),MAX(SUM(A3,B5),G9)))
*/

