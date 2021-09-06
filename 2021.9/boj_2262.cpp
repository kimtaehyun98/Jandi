#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	while (1) {
		if (v.size() == 1) break;
		pii temp = { 0,0 };
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > temp.first) temp = pii(v[i], i);
		}
		int left = INT_MAX, right = INT_MAX;
		if (temp.second != 0) left = temp.first - v[temp.second - 1];
		if (temp.second != v.size() - 1) right = temp.first - v[temp.second + 1];
		v.erase(v.begin() + temp.second);
		ans += min(left, right);
	}
	cout << ans << "\n";
}