#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],dem=0,mn=1000000;
    int chiso;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(a[i]);
    }
    //for(int i=0;i<v.size();i++) cout << v[i] << " ";
    while(v.size() > 0)
    {
        mn=1000000;
        for(int i=0;i<v.size();i++)
        {
            if(mn>v[i])
            {
                mn=v[i];
                chiso=i;
            }
        }
        dem++;
        if(chiso==0)
        {
            v.erase(v.begin()+chiso);
            if(v.size() > 0)
                v.erase(v.begin()+chiso);
        }
        else if(chiso==v.size()-1 && v.size() > 0)
        {
            v.erase(v.begin()+chiso);
            v.erase(v.begin()+chiso-1);
        }
        else
        {
            v.erase(v.begin()+chiso);
            v.erase(v.begin()+chiso);
            v.erase(v.begin()+chiso-1);
        }
        //cout << chiso << '\n';
    }
    cout<<dem;
}
