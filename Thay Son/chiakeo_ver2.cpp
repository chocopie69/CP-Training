#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1001;
const int MAXW = 200001;

int n, W, S;
bool F[MAXN][MAXW];
int a[MAXN],b[MAXW],ans[MAXN]; ///,cnt[MAXN];

void Nhap() {
    cin >> n; ///W;
    S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }
    ///cout << S << endl;
    W = S / 2;
}

void QHD() {
    for(int j = 1;j <= W;++j) F[0][j] = false;
    for(int i = 0;i <= n;++i) F[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= W; j++)
            if (a[i] > j) F[i][j] = F[i-1][j];
                else F[i][j] = F[i-1][j] || F[i-1][j - a[i]];
}

void TruyVet(int i, int j) {
    if (i == 0) return;
    if (j == 0) return;

    ///... i > 0 and j > 0
    if (a[i] > j) TruyVet(i-1, j);
        else { /// a[i] <= j
            if (F[i-1][j - a[i]]) {
                TruyVet(i-1, j - a[i]);
                ans[i] = 1;
            }
                else TruyVet(i-1, j);
        }
}

void InKQ() {
    /*
    cout << F[n][W] << endl;
    ///memset(cnt, 0, sizeof(cnt));
    if (F[n][W] == true)
        TruyVet(n, W);
    */
    int P1 = W;
    while(F[n][P1] == false)
    {
        P1--;
    }

    int P2 = S - P1;
    ///cout << P1 << " " << P2 << " " << S << endl;
    cout << S - 2*P1 << '\n';
    ///cout << P1 << endl;
    ///cout << S << endl;
    for(int i = 1; i <= n; i++)
        ans[i] = 2;
    TruyVet(n, P1);
    for(int i = 1; i <= n; i++)
        if (ans[i] == 1)
        cout << i << " ";
    cout << endl;
    for(int i = 1; i <= n; i++)
        if (ans[i] == 2)
        cout << i << " ";
}

signed main() {

        Nhap();
        QHD();
        InKQ();
}
