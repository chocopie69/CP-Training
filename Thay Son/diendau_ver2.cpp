#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int MAXW = 20002;

int n, W, S;
bool F[MAXN][MAXW];
int a[MAXN],b[MAXW]; ///,cnt[MAXN];

void Nhap() {
    cin >> n >> W; ///W;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S += abs(a[i]);
    }
}

void QHD() {
    memset(F, false, sizeof(F));
    F[1][a[1]+S] = true;
    for (int i = 2; i <= n; i++)
        for (int j = -S; j <= S; j++) {
            if (-S <= j + a[i] && j + a[i] <= S) F[i][j + S] = F[i-1][j + a[i] + S];
            if (-S <= j - a[i] && j - a[i] <= S) F[i][j + S] = F[i][j + S] || F[i-1][j - a[i] + S];
        }
}

void TruyVet(int i, int j) {
    if (i == 1) return;

    if(-S <= j + a[i] && j + a[i] <= S && F[i][j + S] == F[i-1][j + a[i] + S])
    {
        TruyVet(i-1, j + a[i]);
        cout << "-";
    }
    else
    {
        TruyVet(i-1, j - a[i]);
        cout << "+";
    }
}

void InKQ() {
    cout << F[n][W + S];
    ///memset(cnt, 0, sizeof(cnt));
    if (F[n][W + S] == true)
        TruyVet(n, W);
}

int main() {
    Nhap();
    QHD();
    InKQ();
}
