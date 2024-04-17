#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,k,j;
    cin >> t;
    long long a[100000+2], b[100000+2];
    for(int i = 0; i < t; i++){
        cin >> k;
        for(j = 0; j < k; j++){
            cin >> a[j];
        }
        b[0] = a[0];
        cout << b[0] << " ";
        for(j = 1; j <= k; j++){
            if(j < k){
                b[j] = a[j-1]*a[j]/__gcd(a[j-1],a[j]);
                cout << b[j] << " ";
            } else {
                cout << a[j-1] << endl;
            }
        }
    }
    return 0;
}
