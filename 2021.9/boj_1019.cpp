#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[] = { 0,0,0,0,0,0,0,0,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll a = 1, b, cnt = 1;
	cin >> b;
	while (1) {
		// 먼저 a%10을 0으로 맞추기 (증가시키면서)
		while (a % 10 != 0 && a <= b) {
			string str = to_string(a);
			for (int k = 0; k < str.size(); k++) arr[str[k] - '0'] += cnt;
			a++;
		}
		if (a > b) break;
		// b%10을 9로 맞추기 (감소시키면서)
		while (b % 10 != 9 && a <= b) {
			string str = to_string(b);
			for (int k = 0; k < str.size(); k++) arr[str[k] - '0'] += cnt;
			b--;
		}
		if (a > b) break;
		for (int i = 0; i <= 9; i++) arr[i] += ((b / 10) - (a / 10) + 1) * cnt;
		a /= 10; b /= 10; cnt *= 10;
	}
	for (int i = 0; i <= 9; i++) cout << arr[i] << " ";
}