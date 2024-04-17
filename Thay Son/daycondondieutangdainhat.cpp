#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int n;
double a[MAXN];
int F[MAXN], Truoc[MAXN];

void Nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void QHD() {
    F[1] = 1;
    Truoc[1] = -1;
    for (int i = 2; i <= n; i++) {
        F[i] = 1;
        Truoc[i] = -1;
        for (int j = i-1; j >= 1; j--) {
                if (a[j] < a[i]) {
                    ///F[i] = max(F[i], F[j] + 1);
                    if (F[i] < F[j] + 1) {
                        F[i] = F[j] + 1;
                        Truoc[i] = j;
                    }
                }
                    /*
                    if (F[i] < F[j] + 1) {
                        F[i] = F[j] + 1;
                    }
                    */
        }

    }

}

void TruyVet(int i) {
    if (Truoc[i] == -1) cout << a[i];
        else {
            TruyVet(Truoc[i]);
            cout << " " << a[i];
        }
}

void InKQ() {
    int maxlen = -1, chisocuoi;
    for (int i = n; i >= 1; i--)
        if (maxlen < F[i]) {
            maxlen = F[i];
            chisocuoi = i;
        }
    cout << maxlen << endl;

    TruyVet(chisocuoi);
}

int main(){
    Nhap();
    QHD();
    InKQ();
}
