#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int INF = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.
	int n, x;
	cin >> n;
	vector<pii>v(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		v[i] = pii(x, i);
	}
	sort(v.begin(), v.end());
	int prev = INF, cnt = -1;
	vector<pii> ans;
	for (int i = 0; i < n; i++) {
		if (prev != v[i].first) cnt++;
		ans.push_back(pii(v[i].second, cnt));
		prev = v[i].first;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < n; i++) {
		cout << ans[i].second << " ";
	}
}