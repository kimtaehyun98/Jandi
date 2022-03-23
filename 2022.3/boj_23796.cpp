#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<ll>dq[8], ans[8];
ll arr[8][8];

void simul(int k) {
	for (int i = 0; i < 8; i++) {
		ll prev = 0, cnt = 0; bool check = false;
		int cmp = k % 2 == 0 ? 0 : dq[i].size() - 1;
		for (int j = k % 2 == 0 ? 0 : dq[i].size() - 1; k % 2 == 0 ? j < dq[i].size() : j >= 0; k % 2 == 0 ? j++ : j--) {
			cnt++;
			if (j == cmp) {
				prev = dq[i][j];
				continue;
			}
			if (!check) {
				if (prev != dq[i][j]) {
					if (k % 2 == 0) ans[i].push_back(prev);
					else ans[i].push_front(prev);
				}
				else {
					if (k % 2 == 0) ans[i].push_back(prev * 2);
					else ans[i].push_front(prev * 2);
					check = true;
				}
			}
			else check = false;
			prev = dq[i][j];
		}
		if (cnt > 0 && !check) {
			if (k % 2 == 0) ans[i].push_back(prev);
			else ans[i].push_front(prev);
		}
	}
}

int main() {
	char c;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> c;
	if (c == 'L' || c == 'R') {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if(arr[i][j] != 0) dq[i].push_back(arr[i][j]);
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if(arr[j][i] != 0) dq[i].push_back(arr[j][i]);
			}
		}
	}
	int flag;
	if (c == 'L') flag = 0;
	else if (c == 'R') flag = 1;
	else if (c == 'U') flag = 2;
	else flag = 3;
	simul(flag);
	memset(arr, 0, sizeof(arr));
	if (c == 'L' || c == 'U') {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				if (c == 'L') arr[i][j] = ans[i][j];
				else arr[j][i] = ans[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			int aj = 7;
			for (int j = ans[i].size() - 1; j >= 0; j--) {
				if (c == 'R') arr[i][aj--] = ans[i][j];
				else arr[aj--][i] = ans[i][j];
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}