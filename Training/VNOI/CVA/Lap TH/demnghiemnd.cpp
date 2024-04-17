#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int x,y,z;
int main()
{
    cin>>a>>b>>c>>d;
    int dem=0;
    for(int x=1;x<=(d-b-c)/a;x++)
    {
        for(int y=1;y<=(d-a-c)/b;y++)
        {
            int cz = d-a*x-b*y;
           if(cz > 0 && cz % c == 0)
           {
               dem++;
           }
        }
    }
    cout<<dem;
}
