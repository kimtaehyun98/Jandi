#include <bits/stdc++.h>
using namespace std;

int r, c, ans = 0; bool stop = false;
char arr[10001][505];
bool check[10001][505];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

void init() {
	memset(arr, ' ', sizeof(arr));
	memset(check, false, sizeof(check));
}

void dfs(int x, int y) {
	if (y == c - 1) { // 종료 조건
		stop = true;
		ans++;
		return;
	}
	for (int k = 0; k < 3; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < r && 0 <= ny && ny < c) {
			if (check[nx][ny] == false && arr[nx][ny] != 'x') {
				check[nx][ny] = true;
				dfs(nx, ny);
				if (stop) return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	// dfs를 통해 최적으로 길을 탐색한다
	// 이때 최적이란 위쪽부터 탐색을 의미한다
	for (int i = 0; i < r; i++) {
		if (arr[i][0] != 'x') {
			stop = false;
			dfs(i, 0);
		}
	}
	cout << ans << "\n";
}