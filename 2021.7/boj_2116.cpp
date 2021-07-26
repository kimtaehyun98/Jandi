#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	// �ֻ����� ����� ��� ũ�Ⱑ ��ư ������ü�̸� 1 ~ 6 ������
	// ���� ���� �鿡 ���� ������ ���� 7�� ���� �ʴ´� (����)
	// �ױ� ��Ģ : �Ʒ��� �ִ� �ֻ����� ���鿡 �����ִ� ���ڴ�
	// ���� �ִ� �ֻ����� �Ʒ��鿡 �����ִ� ���ڿ� ����
	// 1�� �ֻ����� ������� ���� �� �ִ�
	// �� �簢����� �� -> 4���� �� ������ ����
	// 4���� ���� �߿��� ��� �� ���� ������ ���� �ִ밡 �ǵ��� �ֻ����� �װ��� ��
	// �׿��� �ֻ����� ȸ�� ����
	// �� ������ ������ ���� �ִ��� ���ض� 

	int n, a, b, c, d, e, f;
	cin >> n;
	vector<pii>dice[10007];
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d >> e >> f;
		dice[i].push_back(pii(a, f));
		dice[i].push_back(pii(b, d));
		dice[i].push_back(pii(c, e));
	}
	// A-F, B-D, C-E ¦�� (�� 0-5, 1-3, 2-4 ¦��)
	int Answer = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			int ans = 0;
			pii temp = dice[0][i];
			int bottom, top;
			bottom = temp.first, top = temp.second;
			int pp = 0;
			for (int t = 1; t <= 6; t++) if (t != bottom && t != top) pp = max(pp, t);
			ans += pp;
			if (j == 1) swap(bottom, top);
			for (int k = 1; k < n; k++) {
				for (int t = 0; t < 3; t++) {
					if (dice[k][t].first == top) {
						bottom = top; top = dice[k][t].second; break;
					}
					if (dice[k][t].second == top) {
						bottom = top; top = dice[k][t].first; break;
					}
				}
				if (bottom != 6 && top != 6) ans += 6;
				else {
					int p = 0;
					for (int t = 1; t <= 6; t++) if (t != bottom && t != top) p = max(p, t);
					ans += p;
				}
			}
			Answer = max(ans, Answer);
		}
	}
	cout << Answer << "\n";
}