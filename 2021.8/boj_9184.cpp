#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;


int dp[22][22][22];

int main() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                if (i == 0 || j == 0 || k == 0) dp[i][j][k] = 1;
                else if (i < j && j < k) dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
            }
        }
    }
    int a, b, c, ans;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) return 0;
        if (a <= 0 || b <= 0 || c <= 0) ans = 1;
        else if (a > 20 || b > 20 || c > 20) ans = dp[20][20][20];
        else ans = dp[a][b][c];
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }
}