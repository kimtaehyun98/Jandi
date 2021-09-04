#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; ll k;
	cin >> n >> k;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	// �� ���� �д� �۾��ӵ��� ���� �ִ밡 �ǰ� �Ѵ�
	// ���� k�� ������
	ll temp = 0;
	for (int i = 0; i < n - 1; i++) {
		ll one = ((ll)i + 1) * v[0];
		ll two = v[i + 1] * (n - (ll)i - 1);
		temp = max(temp, one + two);
	}
	ll ans = k / temp;
	ans += k % temp != 0 ? 1 : 0;
	cout << ans << "\n";
}