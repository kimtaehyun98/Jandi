#include <bits/stdc++.h>
using namespace std;

int n, s, ans = INT_MAX;
int dis[11][11];
vector<int>temp;
bool check[11];

void bt(int cnt) {
	if (cnt == n) {
		int cmp = 0;
		for (int i = 0; i < n - 1; i++) {
			cmp += dis[temp[i]][temp[i + 1]];
		}
		ans = min(cmp, ans);
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			temp.push_back(i);
			check[i] = true;
			bt(cnt + 1);
			temp.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dis[i][j];
		}
	}
	// 플로이드 와샬 알고리즘
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	// 백트래킹을 통해 모든 순열 계산 -> 모든 행성 방문
	temp.push_back(s);
	check[s] = true;
	bt(1);
	cout << ans << "\n";
}