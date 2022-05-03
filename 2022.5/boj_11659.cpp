#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; ll s, e;
	cin >> n >> m;
	vector<ll>v(n), sum(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = i == 1 ? v[i - 1] : sum[i - 1] + v[i - 1];
	}
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		if (s == e) cout << v[s - 1] << "\n";
		else cout << sum[e] - sum[s - 1] << "\n";
	}
}