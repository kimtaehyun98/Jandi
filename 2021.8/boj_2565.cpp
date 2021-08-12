#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dp[107][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x, y;
	cin >> n;
	vector<pii>v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pii(x, y));
	}
	sort(v.begin(), v.end());
	// 자신을 포함하려면 자신보다 x좌표가 작다면 자신보다 y좌표도 작아야 한다
	// dp[i][0] = i번째 전깃줄을 뺏을 경우 = max(dp[i-1][0], dp[i-1][1])
	// dp[i][1] = i번째 전깃줄을 포함 경우 = 자신보다 y좌표가 큰 것들 빼고 + 1
	dp[0][0] = 0; dp[0][1] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		// 자신의 y좌표보다 작은 점 찾기
		for (int j = i - 1; j >= 0; j--) {
			if (v[j].second < v[i].second) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
		dp[i][1] = max(dp[i][1], 1); // 모든 점이 자신보다 y좌표가 작을 경우
	}
	cout << n - max(dp[n - 1][0], dp[n - 1][1]) << "\n";
}