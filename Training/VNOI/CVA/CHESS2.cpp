#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int bita,bitb;
bool vis[N+5];
void bfs() {
    queue<pair<int,int>>q;
    q.push({bita,0});
    vis[bita]=true;
    while (!q.empty()) {
        int bit=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if (bit==bitb) {
            cout<<cnt;
            return;
        }
        for (int i=0;i<16;i++) {
            if (((bit>>i)&1)==0) continue;
            if (i%4!=3) { //right
                if (((bit>>(i+1))&1)==0) {
                    int temp=bit|(1<<(i+1));
                    temp&=~(1<<i);
                    if (!vis[temp]) {
                        vis[temp]=true;
                        q.push({temp,cnt+1});
                    }
                }
            }
            if (i%4!=0) { //left
                if (((bit>>(i-1))&1)==0) {
                    int temp=bit|(1<<(i-1));
                    temp&=~(1<<i);
                    if (!vis[temp]) {
                        vis[temp]=true;
                        q.push({temp,cnt+1});
                    }
                }
            }
            if (i>=4) { //up
                if (((bit>>(i-4))&1)==0) {
                    int temp=bit|(1<<(i-4));
                    temp&=~(1<<i);
                    if (!vis[temp]) {
                        vis[temp]=true;
                        q.push({temp,cnt+1});
                    }
                }
            }
            if (i<=11) { //down
                if (((bit>>(i+4))&1)==0) {
                    int temp=bit|(1<<(i+4));
                    temp&=~(1<<i);
                    if (!vis[temp]) {
                        vis[temp]=true;
                        q.push({temp,cnt+1});
                    }
                }
            }
        }
    }
}
int main() {
    for (int i=0;i<16;i++) {
        char c;
        cin>>c;
        if (c=='1') bita|=(1<<i);
    }
    for (int i=0;i<16;i++) {
        char c;
        cin>>c;
        if (c=='1') bitb|=(1<<i);
    }
    bfs();
}
