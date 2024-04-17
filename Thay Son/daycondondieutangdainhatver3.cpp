#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int oo = INT_MAX/2;

int n;
double a[MAXN];
int F[MAXN], Truoc[MAXN];
int ma, m;

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
    if (m >= 1) {
        if (F[i] == m) {
            if (a[i] < ma) {
                m--;
                ma = a[i];
                TruyVet(i - 1);
                cout << a[i] << " ";
            }
            else TruyVet(i-1);
        }
        else TruyVet(i - 1);
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
    ma = +oo;

    m = maxlen;
    TruyVet(n);
    /*
    vector<int> T;
    for (int i = n; i >= 1; i--)
        if (F[i] == m)
            if (a[i] < ma) {
                T.push_back(a[i]);
                m--;
                ma = a[i];
            }

    for (int i = T.size() - 1; i >= 0; i--)
        cout << T[i] << " ";
    */
}

int main(){
    Nhap();
    QHD();
    InKQ();
}
