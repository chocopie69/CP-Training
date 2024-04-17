#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;
    int dem=0,a=0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='x' && s[i]==s[i+1]) {
            dem++;
            if(dem==3) {
            dem=2;
            a++;
            }
        } else {
            dem =1;
        }
    }
    cout << a;
}
