#include <bits/stdc++.h>
using namespace std;

const int mod = 100000;
int dp[101][101][2][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// dp[i][j][k][l] : i, j �����ο��� k(��, ��) �������� l(���� �ʴ´ٸ� or ���´�)
	// ���⼭ k�� �� ���ذ� �Ȱ��µ� k�� ���� ĭ���� �� �����̴�.
	// ��, dp[i][j][��][����O] = ���� ���⿡�� �����µ� �̹��� ���´ٴ� ���̴�
	// �׷��ٸ� ������ w-1 �̹Ƿ� dp[i-1][j]�� �ǰ� ���� ĭ������
	int w, h;
	cin >> w >> h;
	for (int i = 2; i <= w; i++) dp[i][1][0][0] = 1;
	for (int i = 2; i <= h; i++) dp[1][i][1][0] = 1;
	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			dp[i][j][1][0] = (dp[i][j - 1][1][1] + dp[i][j - 1][1][0]) % mod;
			dp[i][j][1][1] = dp[i][j - 1][0][0] % mod;
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % mod;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
		}
	}
	cout << (dp[w][h][0][0] + dp[w][h][0][1] + dp[w][h][1][0] + dp[w][h][1][1]) % mod;
}