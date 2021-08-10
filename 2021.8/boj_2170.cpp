#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// �׷��� ������ �� ���� ���ϱ� (���� ���� �� �׷��� ���� �ѹ��� ���)
	int n, x, y, ans = 0;
	cin >> n;
	vector<pii>v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pii(x, y));
	}
	// �����ϴ� ������ ����
	sort(v.begin(), v.end());
	int s = v[0].first, e = v[0].second;
	for (int i = 1; i < n; i++) {
		int ns = v[i].first, ne = v[i].second;
		if (s <= ns && ns <= e) { // �������� ���̿� �ִٸ�
			if (e < ne) e = ne;
		}
		else {
			ans += e - s;
			s = ns; e = ne;
		}
	}
	ans += e - s;
	cout << ans << "\n";
}