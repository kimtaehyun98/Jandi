#include <bits/stdc++.h>
using namespace std;

int n, cost = INT_MAX, a, b, c, d, sum;
int arr[16][5], cmp[1][4];
vector<int>temp, ans;
bool flag = true;

bool dic(vector<int> a, vector<int> b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i] != b[i]) return  a[i] < b[i];
	}
	return a.size() < b.size();
}

void bt(int s, int cnt, int x) {
	if (s == cnt) {
		if ((cost > sum) || (cost == sum && dic(temp, ans))) {
			if (a >= cmp[0][0] && b >= cmp[0][1] && c >= cmp[0][2] && d >= cmp[0][3]) {
				cost = sum;
				ans = temp;
				if (flag) flag = false;
				
			}
		}
		return;
	}
	for (int i = x; i < n; i++) {
		a += arr[i][0]; b += arr[i][1];
		c += arr[i][2]; d += arr[i][3];
		sum += arr[i][4];
		temp.push_back(i);
		bt(s, cnt + 1, i + 1);
		a -= arr[i][0]; b -= arr[i][1];
		c -= arr[i][2]; d -= arr[i][3];
		sum -= arr[i][4];
		temp.pop_back();
	}
}

int main() {
	cin >> n;
	cin >> cmp[0][0] >> cmp[0][1] >> cmp[0][2] >> cmp[0][3];
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
	}
	for (int i = 1; i <= n; i++) {
		a = 0; b = 0; c = 0; d = 0; sum = 0;
		bt(i, 0, 0);
	}
	if (flag) cout << -1 << "\n";
	else {
		cout << cost << "\n";
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
	}
}