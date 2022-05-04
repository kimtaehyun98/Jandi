#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m, k;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, 1, -1, 0 };
bool check[1000][1000];

pii simul(int x, int y) {
	int s = 0, sum = 0;
	while (1) {
		sum++;
		check[x][y] = true;
		if (sum == k) {
			break;
		}
		while (1) {
			int nx = x + dx[s];
			int ny = y + dy[s];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !check[nx][ny]) {
				x = nx;
				y = ny;
				break;
			}
			else {
				s = (s + 1) % 4;
			}
		}
	}
	return pii(x, y);
}

int main() {
	cin >> m >> n;
	cin >> k;
	if (k > n * m) {
		cout << 0 << "\n";
		return 0;
	}
	pii ans = simul(n - 1, 0);
	cout << ans.second + 1 << " " <<  n - ans.first << "\n";
}