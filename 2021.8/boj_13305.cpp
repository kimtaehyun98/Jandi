#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; ll ans = 0, cmp;
	cin >> n;
	vector<ll>edge(n), node(n);
	for (int i = 0; i < n - 1; i++) cin >> edge[i];
	for (int i = 0; i < n; i++) cin >> node[i];
	cmp = node[0]; ans += node[0] * edge[0];
	for (int i = 1; i < n - 1; i++) {
		if (cmp > node[i]) cmp = node[i];
		ans += cmp * edge[i];
	}
	cout << ans << "\n";
}