#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dem = 1,dem2 = 0;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == s[i+1] && s[i] == 'x'){
            ++dem;
        }
        else {
            dem = 1;
        }
        if(dem == 3){
            dem = 2;
            ++dem2;
        }
    }
    cout << dem2;
}
