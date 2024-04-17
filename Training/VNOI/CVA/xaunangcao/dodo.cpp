#include <bits/stdc++.h>
using namespace std;

int dem1[26],dem2[26],sum=0;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int cnt = 0;
    for(int i=0;i<s1.length();i++)
    {
        dem1[s1[i] - 97]++;
    }
    for(int i=0;i<s2.length();i++)
    {
        dem2[s2[i] - 97]++;
    }
    for(int i=0;i<26;i++) sum += abs(dem1[i] - dem2[i]);
    cout << sum;
}
