#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "BIGTAB"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,n,a[LIMIT][LIMIT], validH[LIMIT][LIMIT], validK[LIMIT][LIMIT], res = 1;
stack<int> st,st2;

int main()
{
    init();
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int leftH = 1, rightH = m;
    cout << endl;
    while(leftH <= rightH)
    {
        bool flagH = false;
        memset(validH,false,sizeof(validH));
        int midH = (leftH+rightH)/2;
        for(int j = 1; j <= n; j++)
        {
            for(int i = 1; i <= m; i++)
            {
                while(!st.empty() && st.top() != a[i][j])
                {
                    st.pop();
                }
                st.push(a[i][j]);
                if(i >= midH)
                {
                    validH[i][j] = (st.size() >= midH);
                    //if(midH == 3) cout << validH[i][j] << " " << i-midH+1 << " " << j << '\n';
                }
            }
            while(!st.empty())
            {
                st.pop();
            }
        }
        int leftK = 1, rightK = n;
        while(leftK <= rightK)
        {
            bool flagK = false;
            memset(validK,false,sizeof(validK));
            int midK = (leftK + rightK)/2;
            for(int i = 1; i <= m; i++)
            {
                for(int j = 1; j <= n; j++)
                {
                    while(!st2.empty() && st2.top() != a[i][j])
                    {
                        st2.pop();
                    }
                    st2.push(a[i][j]);
                    if(j >= midK)
                    {
                        validK[i][j] = (st2.size() >= midK);
                        //if(midK == 4 && midH == 3) cout << validK[i][j] << " " << i << " " << j-midK+1 << '\n';
                    }
                }
                while(!st2.empty())
                {
                    st2.pop();
                }
            }
            for(int i = 1; i <= m-midH+1; i++)
            {
                for(int j = 1; j <= n-midK+1;j++)
                {
                    if(validH[i+midH-1][j] && validK[i][j+midK-1])
                    {
                        flagK = true;
                        flagH = true;
                    }
                    if(midK == 4 && midH == 3) cout << (validH[i+midH-1][j] && validK[i][j+midK-1]) << " " << i << " " << j << '\n';
                }
            }
            if(flagK)
            {
                rightK = midK-1;
            } else
            {
                leftK = midK+1;
            }
        }
        if(flagH)
        {
            leftH = midH+1;
            res = max(res,midH*leftK);
            cout << midH << '\n';
        } else
        {
            rightH = midH+1;
        }
    }
    cout << res;
}

