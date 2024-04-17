#include <bits/stdc++.h>
using namespace std;
bool ktnt (int x) {
    if (x<2) return false;
    else {
        if (x==2) return true;
        else {
            for (int i=2;i<=int(sqrt(x));i++) {
                if (x%i==0) return false;
            }
        }
    }
    return true;
}
    int main() {
        int n; cin>>n;
        for (int i=2;i<n;i++) {
            if (ktnt(i)==true) cout<<i<<" ";
        }
    }

