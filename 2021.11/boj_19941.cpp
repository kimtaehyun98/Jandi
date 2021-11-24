#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, ans = 0;
	string str;
	cin >> n >> k >> str;
	deque<int> p, h;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'H') h.push_back(i);
		else p.push_back(i);
	}
	for (int i = 0; i < p.size(); i++) {
		while (!h.empty()) {
			if (h[0] < p[i] - k) h.pop_front();
			else if (h[0] > p[i] + k) break;
			else {
				ans++;
				h.pop_front();
				break;
			}
 		}
	}
	cout << ans << "\n";
}