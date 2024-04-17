#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Person
{
    ll height,index;
};

const int LIMIT = 5e5+5;
ll n,cnt[LIMIT],res=0;
Person a[LIMIT];
stack<Person> st;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PAIRS.INP","r",stdin);
    freopen("PAIRS.OUT","w",stdout);
}

int main()
{
    init();
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].height;
        a[i].index = i;
    }
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[i].height > st.top().height)
        {
            if(a[i].height != st.top().height)
                res++;
            st.pop();
        }
        if(!st.empty())
        {
            res++;
        }
        st.push(a[i]);
    }
    cout << res;
}

