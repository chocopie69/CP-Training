/* Solution:
Nhận xét: Nếu không tồn tại 1 hình vuông độ dài cạnh = k gồm toàn số 1 thì không tồn tại
hình vuông nào có độ dài cạnh > k gồm toàn số 1
=> Chặt nhọ phân k, thử tất cả các ô (i,j) và tìm u,v
u = i+k-1, v = j+k-1
if(sum(u,v,i,j) == k*k) => là 1 hình vuông gồm toàn số 1
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int LIMIT = 1005;
int n,m,a[LIMIT][LIMIT],sum[LIMIT][LIMIT],res=1;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TABLE.INP","r",stdin); freopen("TABLE.OUT","w",stdout);
    memset(sum,0,sizeof(sum));
}

int main()
{
    init();
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    int left = 1,right = min(n,m),mid;
    bool found;
    while(left <= right)
    {
        found = false;
        mid = (left+right)/2;
        for(int i=1;i<=n-mid+1;i++)
        {
            for(int j=1;j<=m-mid+1;j++)
            {
                int u = i+mid-1, v = j+mid-1;
                if(sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1] == mid*mid)
                {
                    res = max(res,mid);
                    found = true;
                }
            }
        }
        if(found)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    cout << res;
}

