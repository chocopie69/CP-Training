#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,s;
    cin>>n>>p>>s;
    string s1,s2,s3,s4,s5;
    int m;
    map<string,int> mp;
    map<string,int> ma;
    for(int i=0;i<n;i++)
    {
        cin>>s1;
        mp[s1]=0;
    }
    for(int i=0;i<p;i++)
    {
        cin>>s2>>m;
        ma[s2]=m;
    }
    for(int i=0;i<s;i++)
    {
        cin>>s3>>s4>>s5;
        if(s5=="AC")
        {
            if(mp.count(s3)>0)
            {
                mp[s3]+=ma[s4];
            }
        }
        else
        {
            if(mp.count(s3)>0)
            {
                mp[s3]+=0;
            }
        }
    }
    for(auto i:mp)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
