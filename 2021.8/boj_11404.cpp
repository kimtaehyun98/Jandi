#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int INF = 1000000007;

int dis[107][107];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, a, b, c, ans;
	cin >> n >> m;
	// dis 배열 초기화
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) i == j ? dis[i][j] = 0 : dis[i][j] = INF;
	// 간선 입력 받기
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dis[a - 1][b - 1] = min(dis[a - 1][b - 1], c); // 시작 도시와 도착 도시를 연결하는 노선 여러개 가능
	}
	// 플로이드 와샬 알고리즘
	for (int k = 0; k < n; k++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] == INF ? ans = 0 : ans = dis[i][j];
			cout << ans << " ";
		}
		cout << "\n";
	}
}