#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0;
	string cmp, str;
	cin >> cmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		str = str + str;
		for (int k = 0; k < str.size(); k++) {
			if (str[k] == cmp[0]) {
				bool stop = false;
				for (int s = 0; s < cmp.size(); s++) {
					if (str[k + s] != cmp[s]) {
						stop = true;
						break;
					}
				}
				if (!stop) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
}