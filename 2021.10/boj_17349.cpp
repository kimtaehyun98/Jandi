#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main() {
	int a, b, cnt = 0, ans = 0;
	vector<pii>v;
	for (int i = 0; i < 9; i++) {
		cin >> a >> b;
		v.push_back(pii(a, b));
	}
	for (int i = 0; i < 9; i++) {
		int fir = 0;
		bool fix = false, cant[11];
		memset(cant, false, sizeof(cant));
		if (v[i].first == 0) {
			fir = v[i].second;
			fix = true; // 1루수가 확정됨
		}
		else cant[v[i].second] = true;
		bool stop = false;
		for (int k = 0; k < 9; k++) {
			if (k == i) continue;
			int f = v[k].first, s = v[k].second;
			if (f == 1) {
				if (fix) {
					if (s != fir) {
						stop = true;
						break;
					}
				}
				else {
					if (cant[s]) {
						stop = true;
						break;
					}
					fir = s;
					fix = true;
				}
			}
			else {
				if (fix) {
					if (s == fir) {
						stop = true;
						break;
					}
				}
				else {
					cant[s] = true;
				}
			}
		}
		if (stop == false) {
			if (fix) {
				cnt++;
				ans = fir;
			}
			else {
				int tcnt = 0;
				for (int k = 1; k <= 9; k++) {
					if (cant[k] == false) {
						tcnt++;
						fir = k;
					}
				}
				cnt += tcnt;
				if (tcnt == 1) ans = fir;
			}
		}
		if (cnt > 1) break;
	}
	if (cnt == 1) cout << ans << "\n";
	else cout << -1 << "\n";
}