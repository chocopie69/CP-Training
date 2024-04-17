#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 5005, MOD = 1e9+7;
int n,fibo[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void generateFiboNumbers()
{
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i=2;i<LIMIT;i++)
    {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    }
}

int main()
{
    init();
    cin >> n;
    generateFiboNumbers();
    cout << fibo[n];
}
