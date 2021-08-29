#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; ll ans = 0;
	cin >> n >> k;
	vector<ll>v(n), temp;
	for (int i = 0; i < n; i++) cin >> v[i];
	// 두 값의 차이를 구하기
	// 두 값의 차이가 가장 큰 곳을 최대 k - 1개 까지 제거 -> 제거 = 두 개의 집합으로 분할하는 것이다.
	// ex) 예제의 차이값들 = 2 2 1 4, 이때 2번 분할 가능하므로 4와 2 제거 
	for (int i = 0; i < n - 1; i++) temp.push_back(v[i + 1] - v[i]);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n - k; i++) ans += temp[i];
	cout << ans << "\n";
}