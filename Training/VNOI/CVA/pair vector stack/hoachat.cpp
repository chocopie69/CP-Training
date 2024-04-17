#include <bits/stdc++.h>
using namespace std;

string s;
int res = 0;
char c;
stack<int> pos1,pos2;

string multiply(string x,int times)
{
    string res = "";
    for(int i=0;i<times;i++)
    {
        res += x;
    }
    return res;
}

bool isNum(char x)
{
    return int(x) >= 48 && int(x) <= 57;
}

int main()
{
    cin >> s;
    int len;
    string cur;
    for(int i=0;i<s.length();i++)
    {
        char c = s[i];
        if(c == '(') pos1.push(i);
        else if(isNum(c))
        {
            if(s[i-1] != ')')
            {
                s.insert(i+1,multiply(s.substr(i-1,1),int(c)-48-1));
                s.erase(i,1);
            }
            else
            {
                s.insert(i+1,multiply(cur,int(c)-48-1));
                s.erase(i,1);
                if(s[i] == '(') pos1.push(i);
            }
        } else if(c == ')')
        {
            len = i-pos1.top()-1;
            cur = s.substr(pos1.top()+1,len);
            pos1.pop();
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'C') res += 12;
        else if(s[i] == 'H') res += 1;
        else if(s[i] == 'O') res += 16;
    }
    cout << res;
}
