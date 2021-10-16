#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, ans = 0;
	cin >> h >> w;
	vector<int>v(w);
	for (int i = 0; i < w; i++) cin >> v[i];
	for (int i = 1; i <= h; i++) {
		bool l = false, r = false;
		int temp = 0;
		for (int k = 0; k < w; k++) {
			if (v[k] >= i) { // 벽이 있을때
				if (l == false) {
					l = true;
					temp = 0;
				}
				else {
					ans += temp;
					temp = 0;
				}
			}
			else temp++;
		}
	}
	cout << ans << "\n";
}