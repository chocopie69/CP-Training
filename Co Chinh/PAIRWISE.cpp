#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Person
{
    ll height,index;
};

const int LIMIT = 1e6+2;
ll n,cnt[LIMIT],res=0;
Person a[LIMIT];
stack<Person> st;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cnt,0,sizeof(cnt));
}

int main()
{
    init();
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
            res++;
        }
        if(!st.empty())
        {
            res++;
            if(a[i].height == st.top().height)
            {
                res += cnt[st.top().index];
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

