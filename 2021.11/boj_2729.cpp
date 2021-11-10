#include <bits/stdc++.h>
using namespace std;

int calc(int temp,deque<int>& dq) {
	int ret = 0;
	if (temp < 2) dq.push_front(temp);
	else {
		dq.push_front(temp % 2);
		ret = 1;
	}
	return ret;
}

int main() {
	string a, b;
	int t;
	cin >> t;
	while (t--) {
		deque<int>dq;
		cin >> a >> b;
		int size = max(a.size(), b.size());
		int ap = a.size() - 1, bp = b.size() - 1;
		int prev = 0;
		while (1) {
			if (ap >= 0 && bp >= 0) {
				int temp = (a[ap] - '0') + (b[bp] - '0') + prev;
				prev = calc(temp, dq);
				ap--; bp--;
			}
			else if (ap >= 0) {
				int temp = prev + (a[ap] - '0');
				prev = calc(temp, dq);
				ap--;
			}
			else if (bp >= 0) {
				int temp = prev + (b[bp] - '0');
				prev = calc(temp, dq);
				bp--;
			}
			else break;
		}
		if (prev != 0) dq.push_front(1);
		bool check = true;
		for (int i = 0; i < dq.size(); i++) {
			if (check && dq[i] == 0) continue;
			check = false;
			cout << dq[i];
		}
		if (check) cout << 0;
		cout << "\n";
	}
}