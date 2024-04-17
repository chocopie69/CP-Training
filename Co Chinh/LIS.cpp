#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Phantu
{
    int value, index;
};

const int LIMIT = 1e6+4;
int n,maxEnd=-INT_MAX,cnt=0,maxLen=0,maxIndex;
Phantu a[LIMIT];
vector<Phantu> res[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LIS.INP","r",stdin);
    freopen("LIS.OUT","w",stdout);
}

int main()
{
    //init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].value;
        a[i].index = i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i == 1)
        {
            cnt++;
            res[cnt].push_back({a[i].value,a[i].index});
        }
        else
        {
            int left=1,right = cnt,mid,pos=0;
            bool flag = false;
            while(left <= right)
            {
                int mid = (left+right)/2;
                int sizeArray = res[mid].size()-1;
                if(a[i].value >= res[mid][sizeArray].value)
                {
                    right = mid-1;
                    pos = mid;
                    flag = true;
                }
                else
                {
                    left = mid+1;
                }
            }
            if(flag == false)
            {
                cnt++;
                pos = cnt;
            }
            //cout << i << " " << a[i] << " " << pos << " | ";
            res[pos].push_back({a[i].value,a[i].index});
            if(res[pos].size() > maxLen)
            {
                maxLen = res[pos].size();
                maxIndex = pos;
            }

        }
        for(int i=1;i<=cnt;i++)
        {
            for(Phantu v : res[i])
            {
                cout << v.value << " ";
            }
            cout << '\n';
        }
        cout << endl << endl;
    }
    cout << maxLen;
}
