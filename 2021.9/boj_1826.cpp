#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool check[10007];

bool cmp(pii a, pii b) {
	// ����ġ ���� �������, �Ÿ� ���� ������
	if (a.second > b.second) return true;
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, a, b, l, p;
	cin >> n;
	vector<pii>v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(pii(a, b));
	}
	cin >> l >> p;
	// �ڽ��� �� �� �ִ� ���� ������ �ִ� ���� ����ؼ� ���� -> ��� ��ġ�� ����� �Ұ����ϴٸ� -1
	sort(v.begin(), v.end(), cmp);
	memset(check, false, sizeof(check));
	int ans = 0;
	while (1) {
		if (p >= l) break;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (check[i] == false && v[i].first <= p) {
				check[i] = true;
				p += v[i].second;
				ans++;
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = -1;
			break;
		}
	}
	cout << ans << "\n";
}