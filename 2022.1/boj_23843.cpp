#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<int>());
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < n; i++) {
		if (pq.size() < m) pq.push(arr[i]);
		else {
			int minX = pq.top();
			ans += minX;
			vector<int>v;
			while (!pq.empty()) {
				int temp = pq.top();
				pq.pop();
				temp -= minX;
				if (temp != 0) v.push_back(temp);
			}
			for (int i = 0; i < v.size(); i++) pq.push(v[i]);
			pq.push(arr[i]);
		}
	}
	int cmp = 0;
	while(!pq.empty()){
		cmp = max(cmp, pq.top());
		pq.pop();
	}
	cout << ans + cmp << "\n";
}