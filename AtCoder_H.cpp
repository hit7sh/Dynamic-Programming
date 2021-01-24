// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7, mxN = 2e5+5, INF = 0x3f3f3f3f;



template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }




void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	cin >> s;
	vector<vector<long long>> dp(n, vl(m));

	int i, j;
	for (i = 1; i < n; i++)
		if (s[i][0] == '#')
			break;
		else
			dp[i][0] = 1;

	for (j = 1; j < m; j++)
		if (s[0][j] == '#')
			break;
		else
			dp[0][j] = 1;

	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			if (j-1 >= 0 && s[i][j-1] == '.') // from up
				dp[i][j] += dp[i][j-1];

			if (i-1 >= 0 && s[i-1][j] == '.') // form left
				dp[i][j] += dp[i-1][j];

			dp[i][j] %= mod;
		}
	}
  
	print(dp.back().back());
}









int main() {
    solve();

    return 0;
}
