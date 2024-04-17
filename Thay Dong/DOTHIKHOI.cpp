#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

vector<int> nums = {0,1};
int n,x;

int main()
{
    init();
    cin >> n >> x;
    for(int i = 1; i < n; i++)
    {
        int s = nums.size();
        for(int j = nums.size() - 1; j >= 0; j--)
        {
            nums.push_back(nums[j] + (1 << i));
        }
    }
    int pos = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == x)
        {
            pos = i;
            break;
        }
    }
    for(int i = pos+1; i < nums.size(); i++) cout << nums[i] << "\n";
    for(int i = 0; i < pos; i++) cout << nums[i] << "\n";
}
