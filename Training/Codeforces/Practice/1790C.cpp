#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define endl '\n'
using namespace std;

const int INF = INT_MAX, LIMIT = 1e2+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,n,a[LIMIT][LIMIT];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int j = 1; j < n; j++)
        {
            int num1 = a[1][j],num2,cnt1 = 0, cnt2 = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i][j] == num1)
                {
                    cnt1++;
                }
                else
                {
                    cnt2++;
                    num2 = a[i][j];
                }
            }
            if(cnt1 > cnt2)
            {
                if(n % 2 == 0)
                {
                    if(j == (n/2 - 1))
                        cout << num1 << " " << num2 << " ";
                    else if(j == (n/2 + 1))
                        cout << num2 << " " << num1 << " ";
                    else
                        cout << num1 << " ";
                }
                else
                {
                    if(j == (n/2))
                        cout << num1 << " " << num2 << " ";
                    else
                        cout << num1 << " ";
                }
            }
            else if(cnt1 < cnt2)
            {
                if(n % 2 == 0)
                {
                    if(j == (n/2 - 1))
                        cout << num2 << " " << num1 << " ";
                    else if(j == (n/2 + 1))
                        cout << num1 << " " << num2 << " ";
                    else
                        cout << num2 << " ";
                }
                else
                {
                    if(j == (n/2))
                        cout << num2 << " " << num1 << " ";
                    else
                        cout << num2 << " ";
                }
            }
        }
        cout << endl;
    }
}

