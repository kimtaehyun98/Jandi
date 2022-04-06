#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m, k; ll cnt = 0, cost = 0, pay = 0;
	cin >> n >> m >> k;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cost = m;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] <= v[i + 1]) { // 증가 or 같으면 
			// 주식 전량 매도 후 대출 상환, 대출 후 매수
			cost += v[i] * cnt; cnt = 0;           // 매도
			if (((cost - pay) + ((cost - pay) * k)) / v[i] > 0) { // 매수 가능할 때만 대출 가능
				cost -= pay; pay = 0;                  // 대출 상환
				pay += (cost * k); cost += (cost * k); // 대출
				cnt += cost / v[i]; cost %= v[i];      // 매수
			}
		}
		else { // 감소
			// 주식 전량 매도
			cost += v[i] * cnt; cnt = 0;           // 매도
			if (i == n - 2) {
				ll temp = ((cost - pay) + ((cost - pay) * k)) / v[i]; // 만약 주식을 샀을 때의 경우
				if (temp * v[i + 1] > cost) { // 감소하지만 주식을 샀을 때 이득이라면 
					cost -= pay; pay = 0;                  // 대출 상환
					pay += (cost * k); cost += (cost * k); // 대출
					cnt += cost / v[i]; cost %= v[i];      // 매수
				}
			}
		}
	}
	cost += v[n - 1] * cnt;
	cout << cost << "\n";
}