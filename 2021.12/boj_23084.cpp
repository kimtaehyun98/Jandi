#include <bits/stdc++.h>
using namespace std;

int a[26], b[26];

int main() {
	int n;	
	string str, t;
	
	cin >> str >> n;

	for (int i = 0; i < str.size(); i++) {
		a[str[i] - 'a']++;
	}

	for (int i = 0; i < n; i++) {
		cin >> t;
		
		if (t.size() < str.size()) {
			cout << "NO" << "\n";
			continue;
		}

		bool stop = false;
		memset(b, 0, sizeof(b));

		for (int k = 0; k < t.size(); k++) {
			b[t[k] - 'a']++;
			if (k >= str.size()) {
				b[t[k - str.size()] - 'a']--;
			}

			if (k < str.size() - 1) continue;

			int check = 0;
			for (int m = 0; m < 26; m++) {
				if (a[m] != b[m]) {
					check += abs(a[m] - b[m]);
				}
			}

			if (check == 2 || (check == 0 && k >= str.size())) {
				stop = true;
				break;
			}
		}

		if (stop) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
}