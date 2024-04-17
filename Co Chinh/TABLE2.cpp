/* Solution:
Nhận xét: Nếu đáp số không thể là một số V thì cũng không thể là các giá trị lớn hơn V
=> Chặt nhị phân đáp án V

Với mỗi số V, cần kiểm tra xem có hình vuông k*k nào mà chứa toàn các số lớn hơn hoặc bằng V
Cách thức: Xây dựng 1 mảng B từ A, nếu a[i][j] >= V thì b[i][j] = 1, ngược lại bằng 0

Cần tìm 1 hình vuông kích thước k*k gồm toàn số 1
Cách thức: For các chỉ số i,j:
u = i+k-1, v = j+k-1
if(sumB(u,v,i,j) == k*k) => là 1 hình vuông gồm toàn số 1
*/

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
int n,m,k,a[LIMIT][LIMIT],b[LIMIT][LIMIT],sum[LIMIT][LIMIT],res=1;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TABLE2.INP","r",stdin); freopen("TABLE2.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    int left = 1,right = 1e9,mid;
    bool found;
    while(left <= right)
    {
        for(int i = 0; i <= n; i++) sum[i][0] = 0;
        for(int j = 0; j <= m; j++) sum[0][j] = 0;
        found = false;
        mid = (left+right)/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                b[i][j] = (a[i][j] >= mid);
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + b[i][j];
            }
        }
        for(int i=1;i<=n-k+1;i++)
        {
            for(int j=1;j<=m-k+1;j++)
            {
                int u = i+k-1, v = j+k-1;
                if(sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1] == k*k)
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

/*
4 5
3
4 3 7 6 10
10 6 4 15 3
6 7 13 4 3
8 7 3 4 2
*/



