#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define int long long

#define TASKNAME "ROBOT"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,x[LIMIT],y[LIMIT], sumX[LIMIT], sumY[LIMIT], curX = 0, curY = 0;
string s;

void moveRobot(char c)
{
    if(c == 'E') curX++;
    else if(c == 'W') curX--;
    else if(c == 'N') curY++;
    else curY--;
}

signed main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    sumX[0] = 0;
    sumY[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sumX[i] = sumX[i-1] + x[i];
        sumY[i] = sumY[i-1] + y[i];
    }
    cin >> s;
    for(char c : s)
    {
        moveRobot(c);
        int posX = upper_bound(x+1,x+n+1,curX) - x - 1, posY = upper_bound(y+1,y+n+1,curY) - y - 1;
        int resX = (curX*posX-sumX[posX]) + ((sumX[n]-sumX[posX])-curX*(n-posX)),
            resY = (curY*posY-sumY[posY]) + ((sumY[n]-sumY[posY])-curY*(n-posY));
        cout << resX + resY << '\n';
    }
}

