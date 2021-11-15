#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	bool check = false;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == 'D' || str[i] == 'd') {
			if (str[i + 1] == '2') {
				check = true;
				break;
			}
		}
	}
	if (check) cout << "D2" << "\n";
	else cout << "unrated" << "\n";
}