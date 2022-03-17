#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int arr[1004][1004], dis[1004][1004];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check[1004][1004];

void bfs(pii a, pii b) {
	queue<pii>q;
	q.push(a); q.push(b);
	check[a.first][a.second] = true; check[b.first][b.second] = true;
	dis[a.first][a.second] = 0; dis[b.first][b.second] = 0;
	while (!q.empty()) {
		pii now = q.front();
		int x = now.first;
		int y = now.second;
		q.pop();
		if (arr[x][y] == 3) continue;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != -1) {
				if (!check[nx][ny]) {
					arr[nx][ny] = arr[x][y];
					dis[nx][ny] = dis[x][y] + 1;
					check[nx][ny] = true;
					q.push(pii(nx, ny));
				}
				else {
					if (dis[nx][ny] == dis[x][y] + 1 && arr[nx][ny] != arr[x][y] && arr[nx][ny] != 3) {
						arr[nx][ny] = 3;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<pii>temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				temp.push_back(pii(i, j));
			}
		}
	}
	bfs(temp[0], temp[1]);
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) one++;
			else if (arr[i][j] == 2) two++;
			else if (arr[i][j] == 3) three++;
		}
	}
	cout << one << " " << two << " " << three << "\n";
}
