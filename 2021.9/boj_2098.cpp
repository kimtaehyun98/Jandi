#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

const int INF = 1000000000;
int n;
int w[16][16], dp[16][1 << 16];

int tsp(int cur, int visit) {

	// dp의 값이 있다면(이미 방문한 곳이라면) 반환
	if (dp[cur][visit] != -1) return dp[cur][visit];

	// 종료 조건 : 모든 마을을 방문했다면
	if (visit == (1 << n) - 1) {
		if (w[cur][0] != 0) return w[cur][0];
		return INF; // 갈 수 있는지 없는지에 따라 값 반환
	}

	int ret = INF;
	// 방문하지 않은 곳이라면 
	for (int i = 0; i < n; i++) { 
		// i번째 마을을 이미 거쳐왔거나, cur -> i로 길이 존재하지 않는다면
		if (visit & (1 << i) || w[cur][i] == 0) continue;
		ret = min(ret, tsp(i, visit | (1 << i)) + w[cur][i]);
	}
	dp[cur][visit] = ret;

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &w[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tsp(0, 1));
}