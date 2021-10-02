#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll dp[5005];
ll ans[5005];

int main() {
	// ���̰� 1�� �κ� ������ �׻� �����ϴ� �κ� ������
	// ������ Ai�� ������ �����ϴ� �κ� ������ ���� ���
	int n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	// 1) �����ϴ� �κ� ���� ���ϱ�
	// 2) ����� �� index ���ؼ� ���
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