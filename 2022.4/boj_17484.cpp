#include <bits/stdc++.h>
using namespace std;

int n, m, ans = INT_MAX;
int arr[6][6];
int dy[] = { -1,0, 1 };

void bt(int i, int j, int pk, int sum) {
	if (i == n - 1) {
		ans = min(ans, sum);
		return;
	}
	for (int k = 0; k < 3; k++) {
		if (k == pk) continue;
		int nj = j + dy[k];
		if (0 <= nj && nj < m) {
			bt(i + 1, nj, k, sum + arr[i + 1][nj]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int j = 0; j < m; j++) {
		bt(0, j, -1, arr[0][j]);
	}
	cout << ans << "\n";
}