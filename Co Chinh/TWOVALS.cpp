#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "TWOVALS"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[LIMIT], res = 1;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int right = 1;
    while(a[right] == a[0] && right < n) right++;
    if(right == n)
    {
        cout << 0;
        return 0;
    }
    int cnt1 = 1, cnt2 = 1, val1 = a[0], val2 = a[right], left = 0;
    //cout << val1 << " " << val2 << '\n';
    res = max(res,right+1);
    for(int i = right + 1; i < n; i++)
    {
        if(a[i] == val1)
        {
            cnt1++;
        }
        else if(a[i] == val2)
        {
            cnt2++;
        }
        else
        {
            int curCnt1 = 0,curCnt2 = 0;
            while(left < i)
            {
                if(a[left] == val1) curCnt1++;
                else if(a[left] == val2) curCnt2++;
                if(curCnt1 == cnt1)
                {
                    cnt1 = cnt2;
                    val1 = val2;
                    cnt2 = 1;
                    val2 = a[i];
                    break;
                }
                else if(curCnt2 == cnt2)
                {
                    cnt2 = 1;
                    val2 = a[i];
                    break;
                }
                left++;
            }
            left++;
            //cout << left << '\n';
        }
        //cout << val1 << " " << cnt1 << '\n' << val2 << " " << cnt2 << '\n' << '\n';
        res = max(res,i-left+1);
    }
    cout << res;
}


