#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, x;
	cin >> n >> m;
	priority_queue<int, vector<int>, less<int>> pq;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		v.push_back(x);
	}
	bool stop = false;
	for (int i = 0; i < v.size(); i++) {
		x = pq.top();
		pq.pop();
		if (x < v[i]) {
			stop = true;
			break;
		}
		else {
			x -= v[i];
			if (v[i] != 0) pq.push(x);
		}
	}
	int ans = stop ? 0 : 1;
	cout << ans << "\n";
}