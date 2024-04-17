#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct Person
{
    ll height,index;
};

const int LIMIT = 1e5+2;
ll n,q,cnt[LIMIT],res[LIMIT];
Person a[LIMIT];
stack<Person> st;
map<ll> mp;

int main()
{
    init();
    cin >> q;
    while(q--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i].height;
            a[i].index = i;
        }
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&a[i].height>st.top().height)
            {
                st.pop();
            }
            if(!st.empty())
            {
                if(a[i].height == st.top().height)
                {
                    mp[int] += cnt[st.top().index];
                    cnt[i] = cnt[st.top().index]+1;
                }
                else
                {
                    cnt[i] = 1;
                }
            }
            st.push(a[i]);
        }
        cout<<res;
    }
}
