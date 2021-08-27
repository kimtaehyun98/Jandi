#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, p, d, ans = 0;
	bool check[10007];
	memset(check, false, sizeof(check));
	// 강연 날짜를 기준으로 생각해보면 됨
	// 강연료가 높은 강의부터 가능한 강연 날짜(최대한 만기일과 가까운)에 시행
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