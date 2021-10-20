#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, ans = 0, sum = 0;
	cin >> n >> m;
	vector<int>p(m);
	for (int i = 0; i < m; i++) cin >> p[i];
	sort(p.begin(), p.end());
	for (int i = 0; i < m; i++) {
		int temp = p[i] * min(n, (m - i));
		if (sum < temp) {
			sum = temp;
			ans = p[i];
		}
	}
	cout << ans << " " << sum << "\n";
}