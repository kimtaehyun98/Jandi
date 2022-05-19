#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, sx, sy, ex, ey;
char arr[505][505];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1 ,0 ,0 };
bool stop = false;

void bfs(int x, int y) {
	queue<pii>q;
	q.push(pii(x, y));
	while (!q.empty()) {
		pii now = q.front();
		q.pop();
		x = now.first;
		y = now.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (nx == ex && ny == ey) {
					if (arr[nx][ny] == 'X') { // Å»Ãâ
						cout << "YES" << "\n";
						stop = true;
						return;
					}
					else {
						q.push(pii(nx, ny));
						arr[nx][ny] = 'X';
					}
				}
				else {
					if (arr[nx][ny] != 'X') {
						q.push(pii(nx, ny));
						arr[nx][ny] = 'X';
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	bfs(sx, sy);
	if (!stop) cout << "NO" << "\n";
}