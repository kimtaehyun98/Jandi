#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans = 0;
ll arr[1004][1004];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check[1004][1004];

struct rc {
	int x, y;
	ll nw;
};

struct cmp {
	bool operator()(rc a, rc b) {
		return a.nw > b.nw;
	}
};

void dijkstra(int x, int y) {
	priority_queue<rc, vector<rc>, cmp>pq;
	pq.push({ x, y, 0 });
	while (!pq.empty()) {
		x = pq.top().x;
		y = pq.top().y;
		ll c = pq.top().nw;
		pq.pop();
		if (check[x][y]) continue;
		check[x][y] = true;
		ans = max(ans, c);
		if (x == n - 1 && y == n - 1) return;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!check[nx][ny]) {
					ll nw = abs(arr[x][y] - arr[nx][ny]);
					pq.push({ nx, ny, nw });
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dijkstra(0, 0);
	cout << ans << "\n";
}
