#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;
int dp[1001][2][2]; // [n번째][A인지 아닌지][지금까지의 L의 개수]

int main() {
	int n; 
	cin >> n;
	dp[1][0][0] = 1; dp[1][0][1] = 1;
	dp[1][1][0] = 1; dp[0][0][0] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % MOD;
		dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 2][0][0]) % MOD;
		dp[i][1][1] = (dp[i - 1][0][1] + dp[i - 2][0][1]) % MOD;
	}
	cout << (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1]) % MOD << "\n";
}
