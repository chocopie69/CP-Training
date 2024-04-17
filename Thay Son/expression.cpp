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
        sum += a[i];
    }
    fill(res,res+MAXN,2);
}

void QHD() {
    for(int j = 1;j <= sum;++j) F[0][j] = false;
    for(int i = 0;i <= n;++i) F[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (a[i] > j) F[i][j] = F[i-1][j];
                else F[i][j] = F[i-1][j] || F[i-1][j - a[i]];
}

void TruyVet(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;

    ///... i > 0 and j > 0
    if (a[i] > j) TruyVet(i-1, j);
        else { /// a[i] <= j
            if (F[i][j] == F[i-1][j - a[i]]) {
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
    int t = sum/2;
    while(F[n][t] == false)
    {
        t--;
    }
    cout << sum - 2*t << endl;
    TruyVet(n,t);
    ///cout << t*(sum-t);
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
