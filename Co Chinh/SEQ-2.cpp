#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e6+4;
int n,a[LIMIT],maxEnd=-INT_MAX,res=0;
vector<int> endValue;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(endValue.empty() || endValue[endValue.size()-1] > a[i])
        {
            endValue.push_back(a[i]);
        }
        else
        {
            int left=0,right = endValue.size()-1,mid,pos=0;
            while(left <= right)
            {
                int mid = (left+right)/2;
                if(a[i] >= endValue[mid])
                {
                    right = mid-1;
                    pos = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
            //cout << i << " " << a[i] << " " << pos << " | ";
            endValue[pos] = a[i];
        }
        /*for(int v: endValue)
        {
            cout << v << " ";
        }
        cout << endl;*/
    }
    cout << endValue.size();
}
