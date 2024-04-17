#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DELDIGIT"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
int k, cnt = 0;
vector<int> st;

int main()
{
    init();
    cin >> s >> k;
    int n = s.length(), cnt = 0;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && s[st.back()] < s[i] && cnt < k)
        {
            st.pop_back();
            cnt++;
        }
        st.push_back(i);
    }
    while(st.size() > n-k)
    {
        st.pop_back();
    }
    for(int i = 0;i < st.size(); i++)
    {
        cout << s[st[i]];
    }
}

