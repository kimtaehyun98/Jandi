#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; ll ans = 0;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), greater<ll>());
	for (int i = 0; i < n; i++) ans += max(v[i] - i, (ll)0);
	cout << ans << "\n";
}