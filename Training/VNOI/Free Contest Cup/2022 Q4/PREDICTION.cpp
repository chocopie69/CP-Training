#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define foru(i,a,b) for(int i = a; i <= b; i++)
#define ford(i,a,b) for(int i = a; i >= b; i--)
#define fi first
#define se second

typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 7;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;
const int block_size = 750;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int u, k;
        cin >> u >> k;

        vector<int>R;

        bool isFound = false;
        for(int i = 1; i * i <= u; i++) {
            if(u % i == 0) {
                if(--k == 0) {
                    cout << i << endl;
                    isFound = true;
                    break;
                }
                if(i * i == u) continue;
                R.pb(u / i);
            }
        }

        if(isFound) continue;

        if(k > R.size()) cout << -1 << endl;
        else {
            int len = R.size();
            cout << R[len - k] << endl;
        }
    }
}


