#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXW = 1001;

int n, W;
int F[MAXN][MAXW],a[MAXN],b[MAXW];

void Nhap() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
}

void QHD() {
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
            if (a[i] > j) F[i][j] = F[i-1][j];
                else F[i][j] = max(F[i-1][j], b[i] + F[i-1][j - a[i]]);
}

void TruyVet(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;

    ///... i > 0 and j > 0
    if (a[i] > j) TruyVet(i-1, j);
        else { /// a[i] <= j
            if (F[i][j] == b[i] + F[i-1][j - a[i]]) {
                TruyVet(i - 1, j - a[i]);
                cout << i << " ";
            }
                else TruyVet(i-1, j);
        }
}

void InKQ() {
    cout << F[n][W] << endl;
    TruyVet(n, W);
}

int main() {
    Nhap();
    QHD();
    InKQ();
}
