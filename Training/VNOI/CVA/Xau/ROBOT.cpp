#include <bits/stdc++.h>
using namespace std;

pair<int,int> pos[9] = { {0,0}, {-1,0}, {1,0}, {0,1}, {0,-1}, {1,1}, {-1, -1}, {-1, 1}, {1,-1} };

int main()
{
    bool flag = false;
    int n,x,y,curX = 0, curY = 0;
    cin >> x >> y >> n;
    string s;
    cin >> s;
    s = " "+s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'D')
        {
            curY--;
        }
        else if(s[i] == 'L')
        {
            curX--;
        }
        else if(s[i] == 'U')
        {
            curY++;
        }
        else if(s[i] == 'R')
        {
            curX++;
        }
        for(int j=0;j<9;j++)
        {
            if(x + pos[j].first == curX && y+pos[j].second == curY)
            {
                cout << i << endl;
                flag = true;
                break;
            }
        }
    }
    if(flag == false) cout << -1;
}
