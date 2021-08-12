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
	// �ڽ��� �����Ϸ��� �ڽź��� x��ǥ�� �۴ٸ� �ڽź��� y��ǥ�� �۾ƾ� �Ѵ�
	// dp[i][0] = i��° �������� ���� ��� = max(dp[i-1][0], dp[i-1][1])
	// dp[i][1] = i��° �������� ���� ��� = �ڽź��� y��ǥ�� ū �͵� ���� + 1
	dp[0][0] = 0; dp[0][1] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		// �ڽ��� y��ǥ���� ���� �� ã��
		for (int j = i - 1; j >= 0; j--) {
			if (v[j].second < v[i].second) {
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
		}
		dp[i][1] = max(dp[i][1], 1); // ��� ���� �ڽź��� y��ǥ�� ���� ���
	}
	cout << n - max(dp[n - 1][0], dp[n - 1][1]) << "\n";
}