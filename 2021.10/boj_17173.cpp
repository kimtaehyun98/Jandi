#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	// �ڿ��� N�� M���� �ڿ��� Ki�� �־�����. 
	// Ki�� ��� �ϳ��� ����̸鼭 1 �̻� N ������ ���� ���� ���Ͽ���.
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int>v(m);
	for (int i = 0; i < m; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		bool stop = false;
		for (int k = 0; k < m; k++) {
			if (i % v[k] == 0) {
				stop = true;
				break;
			}
		}
		if (stop) ans += i;
	}
	cout << ans << "\n";
}