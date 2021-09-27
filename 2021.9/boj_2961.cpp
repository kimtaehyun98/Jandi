#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool num[11];
vector<pii>v;
int n, s, b, ans = INT_MAX;

int solve() {
	int s = 1, b = 0;
	for (int i = 1; i <= n; i++) {
		if (num[i]) {
			s *= v[i - 1].first;
			b += v[i - 1].second;
		}
	}
	return abs(s - b);
}

void bt(int cnt, int s, int c) {
	if (cnt == c) {
		ans = min(ans, solve());
		return;
	}
	for (int i = s; i <= n; i++) {
		if (num[i] == false) {
			num[i] = true;
			bt(cnt + 1, i + 1, c);
			num[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> b;
		v.push_back(pii(s, b));
	}
	for (int i = 1; i <= n; i++) {
		memset(num, false, sizeof(num));
		bt(0, 1, i);
	}
	cout << ans << "\n";
}