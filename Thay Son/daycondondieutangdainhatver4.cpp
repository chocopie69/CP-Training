#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30005;
const int oo = INT_MAX/2;

int n;
double a[MAXN];
double b[MAXN];
int F[MAXN], Truoc[MAXN];
int ma, m;

void Nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = +oo;
    }
}

void Solve() {
        for (int i = 1; i <= n; i++) {
            int vt = lower_bound(b+1, b + n + 1, a[i]) - b;
            b[vt] = a[i];
            F[i] = vt;
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
            else TruyVet(i - 1);
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
    Solve();
    InKQ();
}
