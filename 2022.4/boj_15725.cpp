#include <bits/stdc++.h>
using namespace std;

int main() {
	string str, temp; bool stop = false;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != 'x') temp += str[i];
		else {
			stop = true;
			break;
		}
	}
	if (!stop) {
		cout << 0 << "\n";
		return 0;
	}
	if (temp.size() == 0) cout << 1 << "\n";
	else if (temp.size() == 1 && temp == "-") cout << -1 << "\n";
	else cout << temp << "\n";
}