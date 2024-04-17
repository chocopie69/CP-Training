#include<bits/stdc++.h>
using namespace std;

int n,m,kq=INT_MAX;
int a[1005][1005],d[1005][1005];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

bool check(int x, int y){
    if(x>=1 && x<=m && y>=1 && y<=n)
        return true;
    return false;
}

void bfs(){
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            d[i][j] = INT_MAX;
    queue<pair<int,int>>q1,q2;
    for(int i=1;i<=m;i++){
        q1.push(make_pair(i,1));
        d[i][1]=1;
    }

    while(!q1.empty()){
        pair<int,int> u=q1.front();
        q1.pop();
        if(u.second==n)
            kq=min(kq,d[u.first][u.second]);

        for(int p=0;p<4;p++){
            int x=u.first+dx[p],y=u.second+dy[p];
            if(check(x,y) && d[u.first][u.second]+(a[u.first][u.second]!=a[x][y])<d[x][y]){
                d[x][y]=d[u.first][u.second]+(a[u.first][u.second]!=a[x][y]);
                if(a[u.first][u.second]==a[x][y]) q1.push(make_pair(x,y));
                else q2.push(make_pair(x,y));
            }
        }

//        while(!q1.empty()){
//            pair<int,int> t=q1.front();
//            q1.pop();
//            for(int i=t.first;i<=m;i++){
//                for(int j=t.second;j<=n;j++){
//                    if(a[i][j]==a[i][j+1])
//                        q1.push(make_pair(i,j+1));
//                    else if(a[i][j]==a[i+1][j])
//                        q1.push(make_pair(i+1,j));
//                    if(a[i][j]!=a[i+1][j])
//                        q2.push(make_pair(i+1,j));
//                    else if(a[i][j]!=a[i][j+1])
//                        q2.push(make_pair(i,j+1));
//                }
//            }
//        }

        if(q1.empty())
            swap(q1,q2);
    }

    cout<<kq;
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    bfs();
}
