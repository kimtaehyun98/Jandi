#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 1, ans = 0;
	cin >> n;
	while (1) {
		if (n < cnt) break;
		n -= cnt++;
		if(n < cnt) cnt = 1;
		ans++;
	}
	cout << ans << "\n";
}