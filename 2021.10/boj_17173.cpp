#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	// 자연수 N과 M개의 자연수 Ki가 주어진다. 
	// Ki중 적어도 하나의 배수이면서 1 이상 N 이하인 수의 합을 구하여라.
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int>v(m);
	for (int i = 0; i < m; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		bool stop = false;
		for (int k = 0; k < m; k++) {
			if (i % v[k] == 0) {
				stop = true;
				break;
			}
		}
		if (stop) ans += i;
	}
	cout << ans << "\n";
}