#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, x, ans = INT_MAX, cnt = 0;
	cin >> n >> h;
	vector<int>bot, top;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i % 2 == 0) bot.push_back(x);
		else top.push_back(x);
	}
	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());
	for (int i = 1; i <= h; i++) {
		int temp = 0;
		temp += lower_bound(bot.begin(), bot.end(), i) - bot.begin();
		temp += upper_bound(top.begin(), top.end(), h - i) - top.begin();
		temp = n - temp;
		if (temp < ans) {
			ans = temp;
			cnt = 1;
		}
		else if (temp == ans) cnt++;
	}
	cout << ans << " " << cnt << "\n";
}