#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <string, priority_queue<ll, vector<ll>>> psq;


int main() {
	// � �̸��� ���� ���� C1,C2, ... Ck��ŭ�� ��ġ�� ���� ���� k�� ����
	// ������ ������ Ư�� ���󿡰� ������ �� �� ��������� ���� �� ����
	// ���� ��� ������ ����
	// �� �� �ŷ��� ������ �ı�
	// 1 -> k���� ������ ������� �� ��ġ�� C1 ~ Ck �̴�
	// 2 -> b���� ������ �����Ѵ� (b�� ���ϸ� ���� ��� ���� ����)
	int q, x, k, b;
	ll ans = 0, c;
	bool check;
	string name;
	map<string, priority_queue<ll, vector<ll>>>m;
	cin >> q;
	while (q--) {
		cin >> x >> name;
		if (x == 1) {
			priority_queue<ll, vector<ll>> temp;
			cin >> k;
			m.find(name) == m.end() ? check = true : check = false;
			for (int i = 0; i < k; i++) {
				cin >> c;
				check ? temp.push(c) : m[name].push(c);
			}
			if (check) m.insert(psq(name, temp));
		}
		else {
			cin >> b;
			while (b--) {
				if (m[name].empty()) break;
				ans += m[name].top();
				m[name].pop();
			}
		}
	}
	cout << ans << "\n";
}