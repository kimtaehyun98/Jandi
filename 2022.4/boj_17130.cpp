#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char arr[1004][1004];
bool check[1004][1004];
int dp[1004][1004];
int dx[] = { -1, 0, 1 };
int dy[] = { -1, -1, -1 };
int ans = -1;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				x = i; y = j;
				check[i][j] = true;
			}
		}
	}
	for (int j = y + 1; j < m; j++) {
		for (int i = max(0, x - (j - y)); i <= min(x + (j - y), n - 1); i++) {
			if (arr[i][j] == '#') continue;
			for (int k = 0; k < 3; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (arr[nx][ny] != '#' && check[nx][ny]) {
						check[i][j] = true;
						dp[i][j] = max(dp[i][j], dp[nx][ny]);
					}
				}
			}
			if (arr[i][j] == 'C') dp[i][j]++;
			if (arr[i][j] == 'O' && check[i][j]) ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
}