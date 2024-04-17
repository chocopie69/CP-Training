#include <bits/stdc++.h>

using namespace std;

set<int> num[int(4e6)];
vector<int> v;

int x[11], n, s[11][11], res = 0, cnt = 0;
void solve(int a[]){
    int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += s[i][a[i]];
	}
	res = max(res,sum);
}
void dequy(int k){
    cnt++;
	for (int i : num[cnt]){
		x[k] = i;
        if (k == n){
            solve(x);
        } else {
            int cur = i;
            num[cnt+1] = num[cnt];
            num[cnt+1].erase(cur);
			dequy(k+1);
			num[cnt+1].insert(cur);
        }
	}
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
		num[1].insert(i);
	}
	dequy(1);
	cout << res;
}
