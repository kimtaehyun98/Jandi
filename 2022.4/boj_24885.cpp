#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k; ll cnt = 0, cost = 0, pay = 0;
	cin >> n >> m >> k;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cost = m;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] <= v[i + 1]) { // ���� or ������ 
			// �ֽ� ���� �ŵ� �� ���� ��ȯ, ���� �� �ż�
			cost += v[i] * cnt; cnt = 0;           // �ŵ�
			if (((cost - pay) + ((cost - pay) * k)) / v[i] > 0) { // �ż� ������ ���� ���� ����
				cost -= pay; pay = 0;                  // ���� ��ȯ
				pay += (cost * k); cost += (cost * k); // ����
				cnt += cost / v[i]; cost %= v[i];      // �ż�
			}
		}
		else { // ����
			// �ֽ� ���� �ŵ�
			cost += v[i] * cnt; cnt = 0;           // �ŵ�
			if (i == n - 2) {
				ll temp = ((cost - pay) + ((cost - pay) * k)) / v[i]; // ���� �ֽ��� ���� ���� ���
				if (temp * v[i + 1] > cost) { // ���������� �ֽ��� ���� �� �̵��̶�� 
					cost -= pay; pay = 0;                  // ���� ��ȯ
					pay += (cost * k); cost += (cost * k); // ����
					cnt += cost / v[i]; cost %= v[i];      // �ż�
				}
			}
		}
	}
	cost += v[n - 1] * cnt;
	cout << cost << "\n";
}