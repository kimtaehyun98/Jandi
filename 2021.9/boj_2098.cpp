#include <bits/stdc++.h>
#pragma warning (disable:4996)
using namespace std;

const int INF = 1000000000;
int n;
int w[16][16], dp[16][1 << 16];

int tsp(int cur, int visit) {

	// dp�� ���� �ִٸ�(�̹� �湮�� ���̶��) ��ȯ
	if (dp[cur][visit] != -1) return dp[cur][visit];

	// ���� ���� : ��� ������ �湮�ߴٸ�
	if (visit == (1 << n) - 1) {
		if (w[cur][0] != 0) return w[cur][0];
		return INF; // �� �� �ִ��� �������� ���� �� ��ȯ
	}

	int ret = INF;
	// �湮���� ���� ���̶�� 
	for (int i = 0; i < n; i++) { 
		// i��° ������ �̹� ���Ŀ԰ų�, cur -> i�� ���� �������� �ʴ´ٸ�
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