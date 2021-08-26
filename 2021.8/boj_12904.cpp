#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// 문자열의 뒤에 A를 추가한다. -> (Reverse) A를 뺀다
	// 문자열을 뒤집고 뒤에 B를 추가한다. -> (Reverse) B를 빼고 뒤집는다
	string s, t;
	cin >> s >> t;
	// 거꾸로 실행
	while (1) {
		if (t.size() < s.size()) break;
		if (t.back() == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else t.pop_back();
		if (s == t) {
			cout << 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
}