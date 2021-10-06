#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main() {
	int n, x, y, ans = 0;
	cin >> n;
	vector<pii>v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(pii(x, y));
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	ans = 1;
	for (int i = 1; i < n; i++) {
		while (!pq.empty()) {
			if (pq.top() > v[i].first) break;
			pq.pop();
		}
		pq.push(v[i].second);
		int size = pq.size();
		ans = max(ans, size);
	}
	cout << ans << "\n";
}