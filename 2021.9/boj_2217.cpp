#include <bits/stdc++.h>
using namespace std;

int main() {
	// 2���� ���� w = > �� w / 2
	// ans = max(���� 1, ���� 2) * 2
	int n, cnt = 1, ans = 0, min_num = INT_MAX;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		min_num = min(min_num, v[i]);
		ans = max(ans, min_num * cnt);
		cnt++;
	}
	cout << ans << "\n";
}