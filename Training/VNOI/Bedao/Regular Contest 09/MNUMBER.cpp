#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c;

int main()
{
    cin >> c;
    /*for(int i=1;i*i<=c;i++)
    {
        if(c % i == 0)
        {
            int j = c/i;
            if((i + j) % 2 == 0)
            {
                int b = (i+j)/2, a = b-i;
                if(b > 0 && a > 0) {
                    cout << "YES" << endl << b << " " << a;
                    return 0;
                }
            }
        }
    }
    cout << "NO";*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(c % 4 == 2 || c == 1) cout << "NO";
    else if(c % 2 == 0) cout << "YES" << '\n' << (c/2+2)/2 << " " << (c/2-2)/2;
    else cout << "YES" << '\n' << (c+1)/2 << " " << (c-1)/2;
}
