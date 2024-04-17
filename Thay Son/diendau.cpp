#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXW = 1001;

int n, W, S, res = 0;
bool F[MAXN][MAXW];
int a[MAXN],b[MAXW]; ///,cnt[MAXN];
char ans[MAXN];

void Nhap() {
    cin >> n >> S; ///W;
    W = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        W += a[i];
        ans[i] = '+';
    }
    W = (W - S);
}

void QHD() {
    for(int j = 1;j <= W;++j)
    {
        F[0][j] = false;
        F[1][j] = false;
    }
    for(int i = 0;i <= n;++i) F[i][0] = true;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (a[i] > j) F[i][j] = F[i-1][j];
                else F[i][j] = F[i-1][j] || F[i-1][j - a[i]];

        }
    }
}

void TruyVet(int i, int j) {
    if (i == 1) return;
    if (j == 0) return;

    ///... i > 0 and j > 0
    if (a[i] > j)
    {
        TruyVet(i-1,j);
    }
        else { /// a[i] <= j
            if (F[i-1][j - a[i]]) {
                TruyVet(i-1, j - a[i]);
                ans[i-1] = '-';
            }
            else
            {
                TruyVet(i-1, j);
            }
        }
}

void InKQ() {
    if(F[n][W])
    {
        cout << a[1];
        TruyVet(n,W);
        for(int i = 1; i < n; i++)
        {
            cout << ans[i] << a[i+1];
        }
    }
}

int main() {
    Nhap();
    if(W % 2 != 0)
    {
        return 0;
    }
    W /= 2;
    QHD();
    InKQ();
}
