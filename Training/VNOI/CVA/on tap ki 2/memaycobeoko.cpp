    #include<bits/stdc++.h>
    using namespace std;
    const int maxN=1e7+5;
    int n,s,k,res;
    vector<int> a(maxN+1,true);
    int main()
    {
        cin>>n>>s>>k;
        int m=n;
        int cur=0;
        for(int i=1;m>1;i=i%n+1)
        {
            if(a[i])
            {
                cur++;
            }
            if(cur==s)
            {
                m--;
                a[i]=false;
                cur=0;
            }
        }
        int i;
        for(i=1;!a[i];i=i%n+1)
        {
            res=i;
        }
        cout<<i<<'\n';
        if(res<=k)
        {
            cout<<(k%n)-res;
        }
        else cout<<(n-res+k)%n+1;
    }
