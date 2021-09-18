#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int r, c, t, sx, sy, ans = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char arr[101][101];

void backtrack(int x, int y, int cnt, int temp) {
	ans = max(ans, temp);
	if (cnt == t) return;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != '#') {
			bool flag = false;
			if (arr[nx][ny] == 'S') {
				flag = true;
				arr[nx][ny] = '.';
			}
			backtrack(nx, ny, cnt + 1, temp + flag);
			if (flag) arr[nx][ny] = 'S';
		}
	}
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'G') {
			sx = i; sy = j;
		}
	}
	backtrack(sx, sy, 0, 0);
	cout << ans << "\n";
}