#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll dp[5005];
ll ans[5005];

int main() {
	// 길이가 1인 부분 수열은 항상 증가하는 부분 수열임
	// 수열의 Ai로 끝나는 증가하는 부분 수열의 개수 출력
	int n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	// 1) 증가하는 부분 수열 구하기
	// 2) 출력할 때 index 더해서 출력
	memset(dp, 0, sizeof(dp));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < n; i++) {
		ll temp = 0;
		for (int k = 0; k < i; k++) {
			if (v[i] > v[k]) {
				temp += dp[k];
				temp %= mod;
			}
		}
		dp[i] = temp + 1;
		dp[i] %= mod;
	}
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
}