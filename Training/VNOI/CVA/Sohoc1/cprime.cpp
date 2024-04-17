#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int n;
int revNum(int x)
{
    int a=x,res=0;
    while(a != 0)
    {
        res = res*10 + a%10;
        a /= 10;
    }
    return res;
}

bool prime(int x)
{
    if(x < 2) return false;
    for(int i=2;i <= sqrt(x);i++) if(x % i == 0) return false;
    return true;
}

int main()
{
    cin >> n;
    cout << (prime(n) && prime(revNum(n)));

}


