#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, p, d, ans = 0;
	bool check[10007];
	memset(check, false, sizeof(check));
	// ���� ��¥�� �������� �����غ��� ��
	// �����ᰡ ���� ���Ǻ��� ������ ���� ��¥(�ִ��� �����ϰ� �����)�� ����
	cin >> n;
	vector<pii>v;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back(pii(p, d));
	}
	sort(v.begin(), v.end(), greater<pii>());
	for (int i = 0; i < n; i++) {
		for (int k = v[i].second; k > 0; k--) {
			if (check[k] == false) {
				check[k] = true;
				ans += v[i].first;
				break;
			}
		}
	}
	cout << ans << "\n";
}