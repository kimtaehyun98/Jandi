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
	// dis �迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) i == j ? dis[i][j] = 0 : dis[i][j] = INF;
	// ���� �Է� �ޱ�
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dis[a - 1][b - 1] = min(dis[a - 1][b - 1], c); // ���� ���ÿ� ���� ���ø� �����ϴ� �뼱 ������ ����
	}
	// �÷��̵� �ͼ� �˰���
	for (int k = 0; k < n; k++) 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	// ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] == INF ? ans = 0 : ans = dis[i][j];
			cout << ans << " ";
		}
		cout << "\n";
	}
}