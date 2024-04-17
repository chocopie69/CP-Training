#include<bits/stdc++.h>
using namespace std;
int n,l,p,cnt;
int a[int(1e6+3)],b[int(1e6+3)];
priority_queue<int>q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    cin>>l>>p;
    if(p<l-a[n]){
        cout<<-1;
    }
    else{
        for(int i=n;i>=0;i--){
           p -= (l-a[i]);
           while((!q.empty())&&p<0){
                cnt++;
                p+=q.top();
                q.pop();
            }
            if(q.empty()&&p<0){
                cnt=-1;
                break;
            }
            l=a[i];
            if(i!=0)
                q.push(b[i]);
        }
       cout<<cnt;
    }
}
