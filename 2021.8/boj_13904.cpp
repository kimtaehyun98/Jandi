#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// ���� ������ ũ�鼭 �������� ���� ���� ����
	// ���������� ū �������� �� �̻� ������ ������ �� ���� ������ ����
	int n, d, w, ans = 0;
	cin >> n;
	vector<pii> hw;
	bool check[1004];
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		hw.push_back(pii(w, d));
	}
	sort(hw.begin(), hw.end(), greater<pii>());
	for (int i = 0; i < n; i++) {
		for (int k = hw[i].second; k > 0; k--) {
			if (check[k] == false) {
				check[k] = true;
				ans += hw[i].first;
				break;
			}
		}
	}
	cout << ans << "\n";
}