#include <bits/stdc++.h>
using namespace std;

int main() {
	string ans = "", str;
	while (1) {
		cin >> str;
		if (cin.eof()) break;
		ans += str;
	}
	ans += ",";
	int sum = 0;
	string temp = "";
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == ',') {
			sum += stoi(temp);
			temp = "";
		}
		else {
			temp += ans[i];
		}
	}
	cout << sum << "\n";
}