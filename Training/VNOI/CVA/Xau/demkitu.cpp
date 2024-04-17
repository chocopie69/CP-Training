#include <bits/stdc++.h>
using namespace std;

int main(){
string x;
getline(cin,x);
string s;
getline(cin,s);
for(int i=0;i<s.size();i++){
        string d=s.substr(i,1);
        if(d==x) cout<<i<<" ";
        }
}
/*S la string
S[i] la ki tu
*/
