#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
set<int>s;

void bt(int cnt, int start, int stop, int sum, vector<int>& v) {
	if (cnt == stop) {
		s.insert(sum);
		return;
	}
	for (int i = start; i < n; i++) {
		sum += v[i];
		bt(cnt + 1, i + 1, stop, sum, v);
		sum -= v[i];
	}
}

int main() {
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ans += v[i];
	}
	// �ִ� 20���� ���� ���� -> 20*20 -> 20C1 + 20C2 + 20C3 + ... 20C20 = 2^20 = �� 1048576 (�鸸)
	// ���� ���� �� �ִ� ���� ��� ���� �� ��ü���� ���� �� (���⼭ �ߺ� �����ϱ� ���� set ����ϸ� �ɵ�)
	for (int i = 1; i <= n; i++) bt(0, 0, i, 0, v);
	cout << ans - s.size() << "\n";
}