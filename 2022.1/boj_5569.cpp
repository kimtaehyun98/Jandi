#include <bits/stdc++.h>
using namespace std;

const int mod = 100000;
int dp[101][101][2][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// dp[i][j][k][l] : i, j 교차로에서 k(동, 남) 방향으로 l(꺽지 않는다면 or 꺽는다)
	// 여기서 k가 잘 이해가 안갔는데 k는 이전 칸에서 온 방향이다.
	// 즉, dp[i][j][동][꺽기O] = 동쪽 방향에서 들어오는데 이번에 꺽는다는 뜻이다
	// 그렇다면 동쪽은 w-1 이므로 dp[i-1][j]가 되고 이전 칸에서는
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