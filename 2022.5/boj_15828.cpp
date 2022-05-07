#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x;
	cin >> n;
	deque<int>dq;
	while (1) {
		cin >> x;
		if (x == -1) break;
		if (x == 0) dq.pop_front();
		else {
			if (dq.size() == n) continue;
			else dq.push_back(x);
		}
	}
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i] << " ";
	}
	if (dq.empty()) cout << "empty" << "\n";
}