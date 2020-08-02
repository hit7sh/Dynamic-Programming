// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>

#define __speed() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define f0(i, n) for(i = 0; i < int(n); i++)
#define f1(i, n) for(i = 1; i<= int(n); i++)
#define endl "\n"

using namespace std;
using mii = map<int, int>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int mod = 1e9+7,mxN = 1e6+5;

template<typename... Args>void print(Args... args){((cout << args << " "), ...);cout << endl;}

int n, cache[mxN], A[mxN];
int f(int pos){
	if(pos<=0)
		return 0;
	if(pos==1)
		return abs(A[0]-A[1]);
	if(cache[pos]!=-1)
		return cache[pos];
	return cache[pos]=min(abs(A[pos]-A[pos-2])+f(pos-2), abs(A[pos]-A[pos-1])+f(pos-1));
}

void solve(){//D
	cin >> n;
	int i;
	memset(cache, -1, sizeof(cache));
	f0(i, n)
		cin >> A[i];
	print(f(n-1));
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout);
	#endif
    __speed();
    solve();
    return 0;
}
