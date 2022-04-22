#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, p, x, y, temp = 0, ans = INT_MAX;
int cost[11];
bool check[11];
vector<pii>sale[11];

void backTracking(int cnt) {
	if (cnt == n) {
		ans = min(temp, ans);
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			temp += max(1, cost[i]);
			for (int k = 0; k < sale[i].size(); k++) {
				cost[sale[i][k].first] -= sale[i][k].second;
			}
			backTracking(cnt + 1);
			for (int k = 0; k < sale[i].size(); k++) {
				cost[sale[i][k].first] += sale[i][k].second;
			}
			temp -= max(1, cost[i]);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> x >> y;
			sale[i].push_back(pii(x - 1, y)); // x를 y만큼 할인
		}
	}
	backTracking(0);
	cout << ans << "\n";
}