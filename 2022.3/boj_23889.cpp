#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int arr[100001];
bool check[100001];

bool cmp(pii a, pii b) {
	if (a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k, x;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> x;
		check[x] = true;
	}
	vector<pii>tmp;
	int temp = 0;
	for (int i = n; i >= 0; i--) {
		if (check[i]) { // 현재 위치에서 돌 시작한다면
			temp += arr[i];
			tmp.push_back(pii(temp, i));
			temp = 0;
		}
		else temp += arr[i];
	}
	sort(tmp.begin(), tmp.end(), cmp);
	vector<int>ans;
	for (int i = 0; i < m; i++) {
		ans.push_back(tmp[i].second);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}