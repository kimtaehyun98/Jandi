#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, x, temp = 0; string str;
	cin >> n;
	cin >> str;
	vector<ll>ans;
	char color = str[0];
	bool check = false;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (color == str[i]) temp = max(temp, x);
		else {
			if (check == false) check = true;
			else ans.push_back(temp);
			temp = x;
			color = str[i];
		}
	}
	sort(ans.begin(), ans.end(), greater<ll>());
	ll sum = 0;
	double s = ans.size();
	for (int i = 0; i < (int)ceil(s / 2); i++) sum += ans[i];
	cout << sum << "\n";
}