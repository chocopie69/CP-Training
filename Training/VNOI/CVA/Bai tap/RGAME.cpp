#include<bits/stdc++.h>
using namespace std;
int t,n;
const int MAX=1e7+5;
int a[MAX];
map<int,int,greater<int>> mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        long long dem=0,tich=1;
        bool flag = false;
        for(auto i:mp)
        {
            if(i.second>=2)
            {
                if(i.second >= 4)
                {
                    if(dem==0)
                    {
                        tich=i.first*i.first;
                        cout << tich << '\n';
                        flag = true;
                        break;
                    }
                }
                tich*=i.first;
                //cout<<tich<<endl;
                dem++;
            }
            if(dem==2)
            {
                cout<<tich<<'\n';
                break;
            }
            //cout<<i.first<<" " << i.second << " " << tich <<'\n';
        }
        if(dem != 2 && !flag)
        {
            cout << -1 << '\n';
        }
        //cout<<tich<<'/n';
        mp.clear();
    }
}
