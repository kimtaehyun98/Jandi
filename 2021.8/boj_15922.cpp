#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x, y, ans = 0, prev_x = 0, prev_y = 0;
	cin >> n;
	// ������ �˰���
	// - �������� ���� �������� �۰ų� ���ٸ� ���� = max(���� ����, ���� ����)
	// - �׷��� �ʴٸ� ���Ӱ� ����
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (i == 0 || x > prev_y) {
			ans += prev_y - prev_x;
			prev_x = x; prev_y = y;
			continue;
		}
		prev_y = max(prev_y, y);
	}
	ans += prev_y - prev_x;
	cout << ans << "\n";
}