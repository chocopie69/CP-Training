#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Guest
{
    int time,type,food,index;
};

int n,m,k,t,d,a;
string ans[1002];
vector<Guest> guests;

bool cmp(Guest x, Guest y)
{
    if(x.time != y.time)
        return x.time < y.time;
    return x.type > y.type;
}

int main()
{
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++)
    {
        cin >> t >> d >> a;
        guests.push_back({t,1,a,i});
        guests.push_back({t+d-1,0,a,i});
    }
    sort(guests.begin(),guests.end(),cmp);
    for(Guest g: guests)
    {
        if(g.type == 1)
        {
            if(g.food == 1)
            {
                if(n > 0 && m > 0)
                {
                    ans[g.index] = "Yes";
                    n--;
                    m--;
                }
                else
                {
                    ans[g.index] = "No";
                }
            }
            else
            {
                if(n > 0)
                {
                    ans[g.index] = "Yes";
                    n--;
                }
                else
                {
                    ans[g.index] = "No";
                }
            }
        }
        else
        {
            if(g.food == 1)
            {
                if(ans[g.index] == "Yes")
                {
                    n++;
                    m++;
                }
            }
            else
            {
                if(ans[g.index] == "Yes")
                {
                    n++;
                }
            }
        }
    }
    for(int i=1;i<=k;i++) cout << ans[i] << endl;
}


