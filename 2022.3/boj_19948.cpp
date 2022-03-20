#include <bits/stdc++.h>
using namespace std;

int main() {
	string str, ans = ""; int sp, arr[26];
	memset(arr, 0, sizeof(arr));
	getline(cin, str);
	cin >> sp; sp++;
	for (int i = 0; i < 26; i++) cin >> arr[i];
	str = " " + str;
	bool stop = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			if (i > 0 && str[i - 1] == ' ') continue;
			sp--;
			if (sp < 0) {
				stop = true;
				break;
			}
		}
		else {
			if (str[i - 1] == ' ') {
				ans += str[i] >= 'a' ? str[i] - 32 : str[i];
			}
			if (str[i] == str[i - 1]) continue;
			else {
				int temp = str[i] >= 'a' ? str[i] - 'a' : str[i] - 'A';
				arr[temp]--;
				if (arr[temp] < 0) {
					stop = true;
					break;
				}
			}
		}
	}
	if (stop) ans = "-1";
	else {
		for (int i = 0; i < ans.size(); i++) {
			if (i > 0 && ans[i - 1] == ans[i]) continue;
			int temp = ans[i] - 'A';
			arr[temp]--;
			if (arr[temp] < 0) {
				ans = "-1";
				break;
			}
		}
	}
	cout << ans << "\n";
}