// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

using namespace std;


void solve() {
	int n, m, i, j, u, v;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> vis(n + 1);
	vector<int> dp(n + 1);

	for (i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].emplace_back(v);	
	}

	function<void(int)> dfs = [&](int p) {
		vis[p] = 1;
		dp[p] = 0;
		for (int& child : adj[p]) {
			if (!vis[child])
				dfs(child);
			dp[p] = max(dp[p], 1 + dp[child]);
		}
	};

	for (i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);
	cout << *max_element(dp.begin(), dp.end());
}


int main() {
  	solve();
    return 0;
}
