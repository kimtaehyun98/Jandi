#include <bits/stdc++.h>
using namespace std;

int main() {
	// 가장 긴 올바른 부분 문자열의 길이
	int n, ans = 0, l = 0;
	char c;
	cin >> n;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == '(') {
			l++;
			s.push(0);
		}
		else {
			if (l > 0) {
				int temp = 2;
				while (!s.empty() && s.top() != 0) {
					temp += s.top();
					s.pop();
				}
				s.pop();
				if (!s.empty() && s.top() > 0) {
					temp += s.top();
					s.pop();
				}
				s.push(temp);
				ans = max(ans, temp);
				l--;
			}
			else {
				s.push(-1);
			}
		}
	}
	cout << ans << "\n";
}