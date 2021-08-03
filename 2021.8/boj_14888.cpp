#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX, MINF = INT_MAX * (-1);

vector<int>oper, temp, arr(17);
bool check[17];
int n, a, maxAns = MINF, minAns = INF;

int solve() {
	int prev = arr[0];
	for (int i = 0; i < temp.size(); i++) {
		int next = arr[i + 1], t = temp[i];
		if (t == 1) prev += next;
		else if (t == 2) prev -= next;
		else if (t == 3) prev *= next;
		else prev /= next;
	}
	return prev;
}

void backtracking(int cnt) {
	if (cnt == n - 1) {
		int ret = solve();
		maxAns = max(maxAns, ret);
		minAns = min(minAns, ret);
		return;
	}
	for (int i = 0; i < oper.size(); i++) {
		if (check[i]) continue;
		temp.push_back(oper[i]);
		check[i] = true;
		backtracking(cnt + 1);
		check[i] = false;
		temp.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i <= 4; i++) {
		cin >> a; for (int k = 0; k < a; k++) oper.push_back(i);
	}
	backtracking(0);
	cout << maxAns << "\n" << minAns << "\n";
}