#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

using namespace __gnu_pbds;


typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,

             tree_order_statistics_node_update>

    ordered_set;


int seed, mul, add,n, k, t, a[250000], res = 0;


signed main() {

	cin >> seed >> mul >> add >> n >> k;

	a[0] = seed;
	for(int i = 1; i < n; i++)
	{
	    a[i] = (a[i-1] * mul + add) % 65536;
	}

	ordered_set oset;

	for (int i = 0; i < n; i++) {
		oset.insert({a[i], t++});

		if (i >= k) { oset.erase(oset.lower_bound({a[i - k], 0})); }

		if (i >= k - 1) {

			//cout << (*oset.find_by_order((k - 1) / 2)).first << endl;
            res += (*oset.find_by_order((k - 1) / 2)).first;
		}
	}
	cout << res;
}
