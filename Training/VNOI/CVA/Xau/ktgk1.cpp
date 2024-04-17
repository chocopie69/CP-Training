#include<bits/stdc++.h>
using namespace std;
int dem[7];
bool ktnt(int a)
{
    if(a==1) return 0;
    else if(a==0) return 0;
    else if(a==2) return 1;
    else if(a==3) return 1;
    else if(a==4) return 0;
    else if(a==5) return 1;
    else if(a==6) return 0;
    else if(a==7) return 1;
    else if(a==8) return 0;
    else if(a==9) return 0;
    return 1;
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(ktnt(s[i]-48) ==1) {
            if(dem[s[i]-48] ==0 ){
            dem[s[i]-48]++;
            cout<< s[i]<< " ";
            }
        }
    }
}
