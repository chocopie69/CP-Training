#include <bits/stdc++.h>
using namespace std;

string s, emojis[15] = {";-)", ";-(", ":)" , ":(", ":-b" , ":-P" , ":D" , ":C" , ":-0", ":-|", "8-0", ":-E", ":-X", ":~(","[:|||:]" };
int cnt[256],curCnt[200000][256],idx=0;
set<pair<string,int>> taken;
bool found = false;

void recur(int pos,bool take)
{
    string cur = emojis[pos];
    if(take)
    {
        /*if(taken.count({cur,pos}) == 0)
        {
           taken.insert({cur,pos});
            for(int i=0;i<cur.length();i++)
            {
                curCnt[index][int(s[i])]++;
            }
        }*/
        taken.insert({cur,pos});
    }
    else
    {
        /*if(taken.count({cur,pos}) == 0)
        {
            taken.erase({cur,pos});
            for(int i=0;i<cur.length();i++)
            {
                curCnt[index][int(s[i])]--;
            }
        }*/
        taken.erase({cur,pos});
    }
    for(int i=0;i<256;i++) curCnt[idx][i] = 0;
    for(auto it = taken.begin();it != taken.end();it++)
        {
            pair<string,int> p = *it;
            string x = p.first;
            for(int i=0;i<x.length();i++)
            {
                curCnt[idx][int(x[i])]++;
            }
        }
    bool flag = false;
    for(int i=0;i<256;i++)
    {
        if(cnt[i] != curCnt[idx][i])
        {
            flag = true;
            break;
        }
    }

    if(flag == false)
    {
        for(auto it = taken.begin();it != taken.end();it++)
        {
            pair<string,int> p = *it;
            if(p.second != 4) cout << p.first << '\n';
            else cout << ":-" << char(92) << '\n';
        }
        found = true;
        return;
    }
    /*bool flag2 = false;
    for(auto it = taken.begin();it != taken.end();it++)
        {
            if(taken.size() == 1) break;
            pair<string,int> p = *it;
            if(p.second != 0 && p.second != 14) break;
            if(p.second != 4) cout << p.first << '\n';
            else cout << ":-" << char(92) << '\n';
            flag2 = true;
        }
        if(flag2) {
            for(int i=0;i<256;i++)
            {
                if(curCnt[index][i] > 0) cout << char(i) << " " << curCnt[index][i] << '\n';
            }
            return;
        }*/
    idx++;
    if(pos == 15) return;
    recur(pos+1,true);
    recur(pos+1,false);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(cnt,0,sizeof(cnt));
    //memset(curCnt,0,sizeof(curCnt));

    cin >> s;
    for(int i=0;i<s.length();i++)
    {
        if(int(s[i]) == 92) s[i] = 'b';
        cnt[int(s[i])]++;
    }
    /*for(int i=0;i<256;i++)
    {
        if(cnt[i] > 0) cout << char(i) << " " << cnt[i] << '\n';
    }*/
    recur(0,true);
    if(found == false) recur(0,false);
}
