#include <bits/stdc++.h>
using namespace std;

struct point {
	int J, O, I;

	point operator + (point& p) {
		return point{ J + p.J, O + p.O, I + p.I };
	}

	point operator - (point& p) {
		return point{ J - p.J, O - p.O, I - p.I };
	}
};

char arr[1001][1001];
point sum[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k, x1, y1, x2, y2, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	// ´©ÀûÇÕ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) cnt++;
			else if (i == 0) sum[i][j] = sum[i][j - 1];
			else if (j == 0) sum[i][j] = sum[i - 1][j];
			else sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

			if (arr[i][j] == 'I') sum[i][j].I++;
			else if (arr[i][j] == 'O') sum[i][j].O++;
			else sum[i][j].J++;
		}
	}
	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		point ans;
		if (x1 == 0 && y1 == 0) ans = sum[x2][y2];
		else if (x1 == 0) ans = sum[x2][y2] - sum[x2][y1 - 1];
		else if (y1 == 0) ans = sum[x2][y2] - sum[x1 - 1][y2];
		else ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

		cout << ans.J << " " << ans.O << " " << ans.I << "\n";
	}
}