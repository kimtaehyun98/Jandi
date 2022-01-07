#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; 
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	ll x = 2 * (n - 1) * (-1), ans = 0;
	for (int i = 0; i < n; i++) {
		ans += v[i] * x;
		x += 4;
	}
	cout << ans << "\n";
}