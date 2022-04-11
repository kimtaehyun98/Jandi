#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct tup {
	int x, y, z;
};

int n, m, a, one = 0, two = 0, three = 0;
int arr[55][55][4];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool check[55][55];

int bfs(int x, int y) {
	int ret = 1;
	queue<pii>q;
	q.push(pii(x, y));
	check[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !check[nx][ny]) {
				if (arr[x][y][k] == 0) {
					check[nx][ny] = true;
					q.push(pii(nx, ny));
					ret++;
				}
			}
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n; // 내가 구현하기 편하게 m, n으로 받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			// 벽 생성
			int k = 3;
			while (a > 0) {
				arr[i][j][k--] = a % 2;
				a /= 2;
			}
		}
	}
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				one++;
				two = max(two, bfs(i, j));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 2; k++) { // 남, 동쪽 성곽이 있는지 확인
				if (arr[i][j][k] == 1) { // 성곽이 있다면
					memset(check, false, sizeof(check));
					arr[i][j][k] = 0;
					three = max(three, bfs(i, j));
					arr[i][j][k] = 1;
				}
			}
		}
	}
	cout << one << " " << two << " " << three << "\n";
}