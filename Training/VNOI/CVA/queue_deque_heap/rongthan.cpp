#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e6+5;
deque<int> dq;
int dp[LIMIT],N,A[LIMIT],K;

int main()
{
    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        cin >> A[i];
    }
    int ans = 0;
    dq.push_back(0);
    for (int i = 1; i <= N + 1; ++i) {
        while (dq.size() && dq.front() < i - K) dq.pop_front();
        dp[i] = dp[dq.front()] + A[i];
        ans += A[i];
        while (dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << ans - dp[N + 1];
}
