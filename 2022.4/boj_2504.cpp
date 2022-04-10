#include <bits/stdc++.h>
using namespace std;

stack<int>s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(' || c == '[') s.push(c == '(' ? -2 : -3);
		else {
			int cmp = c == ')' ? -2 : -3;
			int temp = 0;
			bool stop = false;
			while (!s.empty()) {
				int t = s.top();
				s.pop();
				if (t == cmp) {
					if (temp == 0) temp++;
					temp = temp * cmp * (-1);
					s.push(temp);
					stop = true;
					break;
				}
				else {
					if (t < 0) break; // 다른 괄호 나온거임
					temp += t;
				}
			}
			if (!stop) {
				cout << 0 << "\n";
				return 0;
			}
		}
	}
	int ans = 0;
	while (!s.empty()) {
		if (s.top() < 0) {
			ans = 0;
			break;
		}
		ans += s.top();
		s.pop();
	}
	cout << ans << "\n";
}