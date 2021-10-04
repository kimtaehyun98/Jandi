#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 1) cout << "1" << "\n";
	else {
		vector<pii>temp;
		// 0 유지 1 증가 2 감소
		int prev = 0, now = 0, cnt = 1, ans = 1;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] < v[i + 1]) now = 1;
			else if (v[i] > v[i + 1]) now = 2;
			else now = 0;
			if (i != 0 && prev != now) {
				temp.push_back(pii(cnt, prev));
				cnt = 2;
			}
			else cnt++;
			if (i == n - 2)temp.push_back(pii(cnt, now));
			prev = now;
		}
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i].second == 0) continue;
			else ans = max(ans, temp[i].first);
			if (i > 0 && temp[i].second == 2 && temp[i - 1].second == 1) ans = max(ans, temp[i].first + temp[i - 1].first - 1);
		}
		cout << ans << "\n";
	}
}