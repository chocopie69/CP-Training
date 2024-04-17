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
    //freopen("input.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Prize
{
    ll w,v,c;
};

ll n,s, sumW = 0, sumV = 0, res, x,d, maxV[LIMIT];
Prize a[LIMIT];
vector<int> v1, v2;

bool cmp1(int x, int y)
{
    return a[x].w > a[y].w;
}

bool cmp2(int x, int y)
{
    /*if(a[x].w == a[y].w)
    {
        return a[x].v < a[y].v;
    }*/
    return a[x].w < a[y].w;
}


int main()
{
    init();
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        ll w,v,c;
        cin >> w >> v >> c;
        a[i].w = w;
        a[i].v = v;
        a[i].c = c;
        if(c == 1)
        {
            v1.push_back(i);
            sumW += w;
            sumV += v;
        }
        else
        {
            v2.push_back(i);
        }
    }
    res = sumV;
    sort(v1.begin(),v1.end(),cmp1);
    sort(v2.begin(),v2.end(),cmp2);
    /*for(int i = 0 ; i < v1.size(); i++)
    {
        cout << a[v1[i]].w << " ";
    }
    cout << '\n';
    for(int i = 0 ; i < v2.size(); i++)
    {
        cout << a[v2[i]].w << " ";
    }
    cout << '\n';*/
    for(int i = 0 ; i < v2.size(); i++)
    {
        if(i == 0)
        {
            maxV[0] = a[v2[0]].v;
        }
        else
        {
            maxV[i] = max(maxV[i-1],a[v2[i]].v);
        }
        //cout << maxV[i] << ' ';
    }
    int i = 0, j = v2.size()-1;
    while(i < v1.size())
    {
        Prize prize1 = a[v1[i]];
        while(j >= 0 && sumW - prize1.w + a[v2[j]].w > s) j--;
        if(j < 0) break;
        if(sumV-prize1.v + maxV[j] > res)
        {
            x = prize1.v;
            d = maxV[j];
            res = sumV-prize1.v+maxV[j];
        }
        i++;
    }
    cout << res;
    //cout << x << " " << d;
}

