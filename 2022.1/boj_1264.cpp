#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while (1) {
		getline(cin, str);
		if (str == "#") break;
		int ans = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				ans++;
			}
			if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
				ans++;
			}
		}
		cout << ans << "\n";
	}
}