#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, h, w, sr, sc, fr, fc;
int arr[1004][1004], dis[1004][1004];
bool check[1004][1004];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void rec(int x, int y) {
	for (int i = x; i > x - h; i--) {
		if (i < 0) break;
		for (int j = y; j > y - w; j--) {
			if (j < 0) break;
			arr[i][j] = 1;
		}
	}
}

void bfs(int x, int y) {
	check[x][y] = true;
	dis[x][y] = 0;
	queue<pii>q;
	q.push(pii(x, y));
	while (!q.empty()) {
		pii temp = q.front();
		x = temp.first;
		y = temp.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n - h + 1 && 0 <= ny && ny < m - w + 1) {
				if (check[nx][ny] == false && arr[nx][ny] == 0) {
					check[nx][ny] = true;
					dis[nx][ny] = dis[x][y] + 1;
					if (nx == fr && ny == fc) return;
					q.push(pii(nx, ny));
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
	cin >> h >> w >> sr >> sc >> fr >> fc;
	sr--; sc--; fr--; fc--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				rec(i, j);
			}
		}
	}
	bfs(sr, sc);
	if (check[fr][fc] == false) dis[fr][fc] = -1;
	cout << dis[fr][fc] << "\n";
}