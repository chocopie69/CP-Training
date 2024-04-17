#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30005;
const int oo = INT_MAX/2;

int n;
double a[MAXN];
double b[MAXN];
int F[MAXN], Truoc[MAXN],pos[MAXN];
int ma, m;

void Nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = +oo;
            Truoc[i] = -1;
    }
}

void Solve() {
        for (int i = 1; i <= n; i++) {
            int vt = lower_bound(b+1, b + n + 1, a[i]) - b;
            b[vt] = a[i];
            F[i] = vt;
            pos[vt] = i;
            if(vt > 1) Truoc[i] = pos[vt - 1];
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
    ma = +oo;

    m = maxlen;
    TruyVet(chisocuoi);
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
