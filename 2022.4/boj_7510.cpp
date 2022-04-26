#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<ll>v(3);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end(), greater<ll>());
		string ans = (v[0] * v[0] == v[1] * v[1] + v[2] * v[2]) ? "yes" : "no";
		cout << "Scenario #" << i << ":" << "\n";
		cout << ans << "\n";
		cout << "\n";
	}
}