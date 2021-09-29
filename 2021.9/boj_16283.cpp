#include <bits/stdc++.h>
using namespace std;

int main() {
	// 양 한 마리는 하루에 사료를 정확히 a 그램 먹고
	// 염소 한 마리는 하루에 정확히 b 그램 먹는다
	// 전체 몇 마리인지 확인, 소비한 전체 사료양 확인
	// 양과 염소가 각각 몇 마리인지
	int a, b, n, w, cnt = 0, x, y; bool stop = false;
	cin >> a >> b >> n >> w;
	for (int i = 1; i < n; i++) {
		int j = n - i;
		if (i * a + j * b == w) {
			x = i; y = j;
			cnt++;
		}
		if (cnt > 1) break;
	}
	if (cnt == 1) cout << x << " " << y << "\n";
	else cout << -1 << "\n";
}