#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXW = 200001;

int n, sum = 0;
bool F[MAXN][MAXW];
int a[MAXN],b[MAXN], res[MAXN] ; ///,cnt[MAXN];

void Nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += abs(a[i]);
    }
    fill(res,res+MAXN,2);
}

void QHD() {
    for(int j = -sum;j <= sum;++j) F[0][j + sum] = false;
    for(int i = 0;i <= n;++i) F[i][0 + sum] = true;

    for (int i = 1; i <= n; i++)
        for (int j = -sum; j <= sum; j++)
            if (a[i] > j) F[i][j + sum] = F[i-1][j + sum];
                else {
                        if (-sum <= j - a[i] && j - a[i] <= sum)
                            F[i][j + sum] = F[i-1][j + sum] || F[i-1][j - a[i] + sum];
                }
}

void TruyVet(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;

    ///... i > 0 and j > 0
    if (a[i] > j) TruyVet(i-1, j);
        else { /// a[i] <= j
            if (F[i][j + sum] == F[i-1][j - a[i] + sum]) {
                TruyVet(i-1, j - a[i]);
                res[i] = 1;
            }
            else
            {
                TruyVet(i-1,j);
                //res[i] = 2;
            }
        }
}

void InKQ() {
    long long maxTich = -1;
    int t0;

    for (int t = -sum; t <= sum; t++)
        if (F[n][t + sum] == true)
         if (t*(sum-t) > maxTich) {
                maxTich = t*1LL*(sum-t);
                t0 = t;
         }
    ///cout << sum - 2*t0 << endl;
    TruyVet(n,t0);
    cout << t0*(sum-t0);
    for(int i=1;i<=n;i++)
    {
        if(res[i] == 1)
            cout << i << " ";
    }
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        if(res[i] == 2)
            cout << i << " ";
    }
}

int main() {
    Nhap();
    QHD();
    InKQ();
}
