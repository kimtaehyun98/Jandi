#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; ll ans = 0;
	cin >> n >> k;
	vector<ll>v(n), temp;
	for (int i = 0; i < n; i++) cin >> v[i];
	// �� ���� ���̸� ���ϱ�
	// �� ���� ���̰� ���� ū ���� �ִ� k - 1�� ���� ���� -> ���� = �� ���� �������� �����ϴ� ���̴�.
	// ex) ������ ���̰��� = 2 2 1 4, �̶� 2�� ���� �����ϹǷ� 4�� 2 ���� 
	for (int i = 0; i < n - 1; i++) temp.push_back(v[i + 1] - v[i]);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n - k; i++) ans += temp[i];
	cout << ans << "\n";
}