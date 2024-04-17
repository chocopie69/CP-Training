#include<bits/stdc++.h>
using namespace std;
bool check(string a, string b) {
    int i=0,j=0;
    while (i<a.length()&&j<b.length()) {
        int count1=0;
        int count2=0;
        if (a[i]==b[j]) {
            while (a[i]==a[i+1]) {
                i++;
                count1++;
            }
            while (b[j]==b[j+1]) {
                j++;
                count2++;
            }
            if (count1>count2) {
                return false;
            }
        } else {
            return false;
        }
        i++;
        j++;
    }
    if (i!=a.length()||j!=b.length()) {
        return false;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    int kq[t];
    for (int i=0;i<t;i++) {
        string a,b;
        cin>>a>>b;
        if (check(a,b)==true)
            kq[i]=1;
        else
            kq[i]=0;
    }
    for (int i=0;i<t;i++) {
        if (kq[i]==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
