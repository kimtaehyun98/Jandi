#include <bits/stdc++.h>
using namespace std;

int main() {
	// �� �� ������ �Ϸ翡 ��Ḧ ��Ȯ�� a �׷� �԰�
	// ���� �� ������ �Ϸ翡 ��Ȯ�� b �׷� �Դ´�
	// ��ü �� �������� Ȯ��, �Һ��� ��ü ���� Ȯ��
	// ��� ���Ұ� ���� �� ��������
	int a, b, n, w, cnt = 0, x, y; bool stop = false;
	cin >> a >> b >> n >> w;
	for (int i = 1; i < n; i++) {
		int j = n - i;
		if (i * a + j * b == w) {
			x = i; y = j;
			cnt++;
		}
		if (cnt > 1) break;
	}
	if (cnt == 1) cout << x << " " << y << "\n";
	else cout << -1 << "\n";
}