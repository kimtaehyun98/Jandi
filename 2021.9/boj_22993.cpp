#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; ll a, x; string ans = "Yes";
	cin >> n;
	vector<ll>v(n - 1);
	cin >> x;
	for (int i = 0; i < n - 1; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		if (v[i] < x) x += v[i];
		else {
			ans = "No";
			break;
		}
	}
	cout << ans << "\n";
}