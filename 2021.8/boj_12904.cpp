#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// ���ڿ��� �ڿ� A�� �߰��Ѵ�. -> (Reverse) A�� ����
	// ���ڿ��� ������ �ڿ� B�� �߰��Ѵ�. -> (Reverse) B�� ���� �����´�
	string s, t;
	cin >> s >> t;
	// �Ųٷ� ����
	while (1) {
		if (t.size() < s.size()) break;
		if (t.back() == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else t.pop_back();
		if (s == t) {
			cout << 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}