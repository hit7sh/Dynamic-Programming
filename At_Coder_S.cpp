// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
 
#define __speed() ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define dbg(x) cout << "(" << __LINE__ << ": "<< #x << " = " << x << ")\n"
 
#define Yes(x) print((x) ? "Yes" : "No")
#define tt 	int t; for (cin >> t; t--; )
 
#define f0(i, n)  for (i = 0; i < (int)(n); i++)
#define f1(i, n)  for (i = 1; i <=(int)(n); i++)
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())
 
#define EB emplace_back
#define PB push_back

#define LB lower_bound
#define UB upper_bound

#define endl "\n"
#define S second
#define F first
 
using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
 
using ll = int64_t;
using vi = vector<int>;
 
using vvi = vector<vi>;
using vl = vector<ll>;
 
const int mod = 1e9 + 7, mxN = 1e5 + 5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
 
 
template <typename... T> void print(T... args) { ((cout << args << " "), ...), cout << endl; }
 
template <typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) { in >> p.F >> p.S; return in; }
template <typename T1, typename T2> ostream& operator<<(ostream& ot, pair<T1, T2>& p) { ot << p.F << ' ' << p.S; return ot; }

template <typename T1, typename T2> bool cmax(T1& a, T2 b) { if (b > a) { a = b; return true;} return false; }
template <typename T1, typename T2> bool cmin(T1& a, T2 b) { if (b < a) { a = b; return true;} return false; }
 
template <typename T> istream& operator>>(istream& in, vector<T>& v) { for (T& x:v) in >> x; return in; }
template <typename T> ostream& operator<<(ostream& ot, vector<T>& v) { for (T& x:v) ot << x << ' '; return ot; }


ll dp[10001][101][2];
string k;
int D, n;
ll f(int idx, ll d, bool c) {
	if (~dp[idx][d][c]) return dp[idx][d][c];
	int ub = c ? k[idx]^48 : 9;
	if (idx == n - 1) {
		ll ans = 0;
		for (int i = 0; i <= ub; i++)
			ans += i % D == d;
		return ans;
	}
	ll& ans = dp[idx][d][c] = 0;
	for (int i = 0; i <= ub; i++)
		ans = (ans%mod + f(idx + 1, (D + d - i % D) % D, c && (i == ub))) % mod;
	return ans;
}	

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> k >> D;
	n = sz(k);
	print((f(0, 0, 1) - 1 + mod) % mod);
}

	



signed main() {
	 __speed() solve();
}
