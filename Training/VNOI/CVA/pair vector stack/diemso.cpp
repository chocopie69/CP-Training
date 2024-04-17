#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int tin,theduc,tong,index;
};

int n;
int ranking[102];
Student a[102];

bool cmpVal(Student x,Student y)
{
    return x.tong > y.tong;
}

bool cmpIndex(Student x,Student y)
{
    return x.index < y.index;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].name >> a[i].tin >> a[i].theduc;
        a[i].tong = a[i].tin + a[i].theduc;
        a[i].index = i;
    }
    sort(a,a+n,cmpVal);
    for(int i=0;i<n;i++)
    {
        ranking[a[i].index] = (i != 0 && a[i].tong == a[i-1].tong ? ranking[a[i-1].index] : i+1);
    }
    sort(a,a+n,cmpIndex);
    for(int i=0;i<n;i++)
    {
        cout << a[i].name << " " << ranking[i] << '\n';
    }
}
