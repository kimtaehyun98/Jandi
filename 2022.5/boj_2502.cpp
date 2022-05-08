#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int d, k; bool stop = false;
	cin >> d >> k;
	for (int a = 1; a <= k; a++) {
		int l = 1, r = k;
		while (l <= r) {
			int mid = (l + r) / 2;
			int temp = 0, fir = a, sec = mid;
			for (int i = 3; i <= d; i++) {
				if (temp > k) break;
				temp = fir + sec;
				fir = sec; sec = temp; 
			}
			if (temp == k) {
				cout << a << "\n" << mid << "\n";
				stop = true;
				break;
			}
			else if (temp > k) r = mid - 1;
			else l = mid + 1;
		}
		if (stop) break;
	}
}